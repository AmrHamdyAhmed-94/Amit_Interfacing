 #include "../../../LIBRARIES_H/STD_TYPES.h"
 #include "../../../LIBRARIES_H/BIT_MATH.h"
 
 #include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "../../../MCAL/DIO/H_FILES/DIO.h"
 
 #include "../H_FILES/LCD_PRE_CONFIG.h"
 #include "../H_FILES/LCD.h"
 
 #include <util/delay.h>
 
 static void HAL_LCD_voidInitialize_4_Bit_Mode(void);
 static void HAL_LCD_voidInitialize_8_Bit_Mode(void);
 
 static void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command);
 static void HAL_LCD_voidWriteCommand_4_Bit_Mode(uint8_t Copy_u8Command);
 static void HAL_LCD_voidWriteCommand_8_Bit_Mode(uint8_t Copy_u8Command);
 
 static void HAL_LCD_voidWriteData(uint8_t Copy_u8DATA);
 static void HAL_LCD_voidWriteData_4_Bit_Mode(uint8_t Copy_u8Data);
 static void HAL_LCD_voidWriteData_8_Bit_Mode(uint8_t Copy_u8Data);
 
 uint8_t arr_Shapes[BLOCKS_BYTES] = {0x00,0x00,0x1F,0x19,0x19,0x19,0x01,0x01};
 
 
 void HAL_LCD_voidInitialize(void){
 	#if (LCD_MODE == LCD_4_BIT_MODE || LCD_MODE == 4)
 	HAL_LCD_voidInitialize_4_Bit_Mode();
 	#elif (LCD_MODE == LCD_8_BIT_MODE || LCD_MODE == 8)
 	HAL_LCD_voidInitialize_8_Bit_Mode();
 	#endif
 }
 
 void HAL_LCD_voidClearLCD(void){
 	HAL_LCD_voidWriteCommand(0b00000001);
 }
 
 void HAL_LCD_voidClearPart(uint8_t Copy_RowNo , uint8_t Copy_u8Start , uint8_t Copy_u8End){
 	uint8_t Local_u8Loop = START_LOOP ;
 	HAL_LCD_voidMoveCursor(Copy_RowNo , Copy_u8Start);
 	for(Local_u8Loop = Copy_u8Start ; Local_u8Loop <= Copy_u8End ; Local_u8Loop++){
 		HAL_LCD_voidWriteData(' ');
 	}
 }
 
 void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character){
 	HAL_LCD_voidWriteData(Copy_u8Character);
 }
 
 void HAL_LCD_voidWriteString(uint8_t *Ptr_u8String){
 	uint8_t charLoop = START_LOOP;
 	while(Ptr_u8String[charLoop] != NULL_CHAR){
 		HAL_LCD_voidWriteData(Ptr_u8String[charLoop++]);
 	}
 }
 
 void HAL_LCD_voidWriteNumber(uint32_t Copy_u32Number){
 	uint8_t Local_u8CharArr[10] , Local_u8Count = 1 , Local_u8Count2 , Local_u8Loop = 0;
 	uint16_t Local_u32IntValue = Copy_u32Number; /*Copy of integer Value as the original Value is not effected*/
 	while(Local_u32IntValue / 10 != 0){
 		Local_u8Count++;
 		Local_u8CharArr[Local_u8Count-1] = Local_u32IntValue % 10;
 		Local_u32IntValue /= 10 ;
 	}
 	Local_u32IntValue = Copy_u32Number;
 	Local_u8Count2 = Local_u8Count;
 	while(Local_u8Count!=0){
 		Local_u8CharArr[Local_u8Count-1] = Local_u32IntValue % 10;
 		Local_u32IntValue /=10;
 		Local_u8Count--;
 	}
 	for(Local_u8Loop=0 ; Local_u8Loop < Local_u8Count2 ; Local_u8Loop++){
 		HAL_LCD_voidWriteData(Local_u8CharArr[Local_u8Loop] + '0' );  /*Add 48 To each Number To convert To Character*/
 	}
 }
 
 void HAL_LCD_voidWriteSpecialChar(uint8_t *ptr_Shapes , uint8_t Copy_RowNo , uint8_t Copy_ColNo){
 	uint8_t Char_loop ;
 	HAL_LCD_voidWriteCommand(0x40);
 	for(Char_loop = 0 ; Char_loop < 8 ; Char_loop ++){
 		HAL_LCD_voidWriteData(ptr_Shapes[Char_loop]);
 	}
 	HAL_LCD_voidMoveCursor(Copy_RowNo , Copy_ColNo);
 }
 
 void HAL_LCD_voidMoveCursor(uint8_t Copy_u8RowNumber, uint8_t Copy_u8ColNumber){
 	HAL_LCD_voidWriteCommand(128+(0x40*Copy_u8RowNumber)+Copy_u8ColNumber);
 }
 
 void HAL_LCD_voidDisplaySetup(uint8_t Copy_u8DisplayValue){
 	if(Copy_u8DisplayValue == LCD_DISPLAY_ON){
 		HAL_LCD_voidWriteCommand(0b00001111); /*0 0 0 0 1 (Display 0 off , 1 on ) (Cursor 0 off 1 on)(Cursor Blink 0 off 1 on)*/
 		}else if(Copy_u8DisplayValue == LCD_DISPLAY_OFF){
 		HAL_LCD_voidWriteCommand(0b00001011); /*0 0 0 0 1 (Display 0 off , 1 on ) (Cursor 0 off 1 on)(Cursor Blink 0 off 1 on)*/
 	}
 }
 
 /////////////////////////////////////////////////// Static Methods
 
 /* Write COMMAND */
 static void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command){
 	#if (LCD_MODE == LCD_4_BIT_MODE || LCD_MODE == 4)
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(Copy_u8Command);
 	#elif (LCD_MODE == LCD_8_BIT_MODE || LCD_MODE == )
 	HAL_LCD_voidWriteCommand_8_Bit_Mode(Copy_u8Command);
 	#endif
 }
 
 static void HAL_LCD_voidWriteCommand_4_Bit_Mode(uint8_t Copy_u8Command){
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0F) | (Copy_u8Command & 0xF0);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0F) | (Copy_u8Command << 4);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
 	_delay_ms(1);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 }
 
 static void HAL_LCD_voidWriteCommand_8_Bit_Mode(uint8_t Copy_u8Command){
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8Command);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 }
 
 /* Write DATA */
 static void HAL_LCD_voidWriteData(uint8_t Copy_u8Data){
 	#if (LCD_MODE == LCD_4_BIT_MODE || LCD_MODE == 4)
 	HAL_LCD_voidWriteData_4_Bit_Mode(Copy_u8Data);
 	#elif (LCD_MODE == LCD_8_BIT_MODE || LCD_MODE == 8)
 	HAL_LCD_voidWriteData_8_Bit_Mode(Copy_u8Data);
 	#endif
 }
 
 static void HAL_LCD_voidWriteData_4_Bit_Mode(uint8_t Copy_u8Data){
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_HIGH);
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0F) | (Copy_u8Data & 0xF0);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_HIGH);
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0F) | (Copy_u8Data << 4);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
 }
 
 static void HAL_LCD_voidWriteData_8_Bit_Mode(uint8_t Copy_u8Data){
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN,DIO_LOW);                                      /*Clear Enable To Low*/
 	MCAL_DIO_u8SetPinValue(LCD_RS_PIN,DIO_HIGH); 									/*RS Command 0 Data 1*/
 	MCAL_DIO_u8SetPinValue(LCD_RW_PIN,DIO_LOW); 						            /*RW write  0 Read 1*/
 	MCAL_DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);                             /*Write The Data*/
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN,DIO_HIGH);                                     /*Set Enable bit */
 	_delay_ms(2);
 	MCAL_DIO_u8SetPinValue(LCD_EN_PIN,DIO_LOW);                                      /*Clear Enable Bit */
 }
 
 /* Initialization */
 static void HAL_LCD_voidInitialize_4_Bit_Mode(void){
 	LCD_DATA_DIR_REG = ((LCD_DATA_DIR_REG & (0x0F)) | 0xF0);
 	MCAL_DIO_u8SetPinDir(LCD_RS_PIN , DIO_OUTPUT);
 	MCAL_DIO_u8SetPinDir(LCD_RW_PIN , DIO_OUTPUT);
 	MCAL_DIO_u8SetPinDir(LCD_EN_PIN , DIO_OUTPUT);
 	_delay_ms(30);
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(0x33);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(0x32);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(0b00101100);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(0b00001111);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_4_Bit_Mode(0b00000001);
 	_delay_ms(2);
 }
 
 static void HAL_LCD_voidInitialize_8_Bit_Mode(void){
 	MCAL_DIO_u8SetPortDir(LCD_DATA_PORT,DIO_PORT_OUTPUT);
 	MCAL_DIO_u8SetPinDir(LCD_RS_PIN , DIO_OUTPUT);
 	MCAL_DIO_u8SetPinDir(LCD_RW_PIN , DIO_OUTPUT);
 	MCAL_DIO_u8SetPinDir(LCD_EN_PIN , DIO_OUTPUT);
 	_delay_ms(30);
 	HAL_LCD_voidWriteCommand_8_Bit_Mode(0b00111100);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_8_Bit_Mode(0b00001111);
 	_delay_ms(2);
 	HAL_LCD_voidWriteCommand_8_Bit_Mode(0b00000001);
 	_delay_ms(2);
 }