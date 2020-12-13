/*
 * KEYPAD.c
 *
 * Created: 12/11/2020 5:57:48 PM
 *  Author: Amrha
 */

 #include "../../../LIBRARIES_H/STD_TYPES.h"
 #include "../../../LIBRARIES_H/BIT_MATH.h"

 #include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "../../../MCAL/DIO/H_FILES/DIO.h"

 #include "../H_FILES/KEYPAD_PRE_CONFIG.h"
 #include "../H_FILES/KEYPAD.h"

uint8_t KEY_MATRIX[(KEY_ROW_END - KEY_ROW_START) + 1][(KEY_COL_END - KEY_COL_START) + 1] = {{1, 2, 3, 10},{4, 5, 6, 11},{7, 8, 9, 12},{13, 0, 14, 15}};

void HAL_KEYPAD_voidInitialize(void){
	uint8_t Row_loop , Col_loop;

	for(Row_loop = KEY_ROW_START ; Row_loop <= KEY_ROW_END ; ++Row_loop){
		MCAL_DIO_u8SetPinDir(KEY_ROW_PORT , Row_loop , DIO_INPUT);
		MCAL_DIO_u8SetPinInputType(KEY_ROW_PORT , Row_loop , DIO_INPUT_PULL_UP);
	}

	for(Col_loop = KEY_COL_START ; Col_loop <= KEY_COL_END ; ++Col_loop){
		MCAL_DIO_u8SetPinDir(KEY_COL_PORT , Col_loop , DIO_OUTPUT);
		MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_HIGH);
	}
}

void HAL_KEYPAD_voidGetKeyPressedOnce(uint8_t *ptr_u8_KeyPressed){
	uint8_t Row_loop , Col_loop , Key_Pressed = DIO_HIGH;
	for(Col_loop = KEY_COL_START ; Col_loop <= KEY_COL_END ; ++Col_loop){		
		MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_LOW);		
		for(Row_loop = KEY_ROW_START ; Row_loop <= KEY_ROW_END ; ++Row_loop){
			MCAL_DIO_u8GetPinValue(KEY_ROW_PORT , Row_loop , &Key_Pressed);
			if(Key_Pressed == DIO_LOW){
				*ptr_u8_KeyPressed = KEY_MATRIX[Row_loop - KEY_ROW_START][Col_loop - KEY_COL_START];
				while(Key_Pressed == DIO_LOW){
					MCAL_DIO_u8GetPinValue(KEY_ROW_PORT , Row_loop , &Key_Pressed);
				}
			}		
		}	
		MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_HIGH);
	}

} 
