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

 static uint8_t GLOBAL_STATIC_initCheck ;

 uint8_t Key_Matrix[KEY_ROW_END - KEY_ROW_START + 1][KEY_COL_END - KEY_COL_START + 1 ]= {{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','/'},{'*','0','D','='}};

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

	GLOBAL_STATIC_initCheck = NO_ERROR ;
}

void HAL_KEYPAD_voidGetKeyPressed_Once(uint8_t *ptr_u8_KeyPressed){
	uint8_t Row_loop , Col_loop , Key_Pressed = DIO_HIGH;
	if(GLOBAL_STATIC_initCheck == NO_ERROR){
		for(Col_loop = KEY_COL_START ; Col_loop <= KEY_COL_END ; ++Col_loop){
			MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_LOW);
			for(Row_loop = KEY_ROW_START ; Row_loop <= KEY_ROW_END ; ++Row_loop){
				MCAL_DIO_u8GetPinValue(KEY_ROW_PORT , Row_loop , &Key_Pressed);
				if(Key_Pressed == DIO_LOW){
					*ptr_u8_KeyPressed = Key_Matrix[Row_loop - KEY_ROW_START][Col_loop - KEY_COL_START];
					while(Key_Pressed == DIO_LOW){
						MCAL_DIO_u8GetPinValue(KEY_ROW_PORT , Row_loop , &Key_Pressed);
					}
				}
			}
			MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_HIGH);
		}
	}
} 

void HAL_KEYPAD_voidGetKeyPressed_Continous(uint8_t * ptr_u8KeyPressed, uint16_t Copy_DelayBetweenClicks_ms){
	uint8_t Row_loop, Col_loop , Key_Pressed = DIO_HIGH;
	if(GLOBAL_STATIC_initCheck == NO_ERROR){
		for(Col_loop = KEY_COL_START ; Col_loop <= KEY_COL_END ; Col_loop ++){
			MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_LOW);   /*set Column To Low to Check if The key is Pressed in this Column*/
			for(Row_loop = KEY_ROW_START ; Row_loop <= KEY_ROW_END ; Row_loop ++){
				MCAL_DIO_u8GetPinValue(KEY_ROW_PORT , Row_loop , &Key_Pressed); /*Read The Row if The Column is Pressed Then we will read Low*/
				if(Key_Pressed == DIO_LOW){
					*ptr_u8KeyPressed = Key_Matrix[Row_loop - KEY_ROW_START][Col_loop - KEY_COL_START]; /*Get The Pressed Key to return it*/
					_delay_ms(Copy_DelayBetweenClicks_ms);
				}
			}
			MCAL_DIO_u8SetPinValue(KEY_COL_PORT , Col_loop , DIO_HIGH);  /*Set The column to High to look for another Column*/
		}
	}
}
