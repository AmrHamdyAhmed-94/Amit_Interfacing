#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../../LIBRARIES_H/BIT_MATH.h"

#include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/LCD_PRE_CONFIG.h"
#include "../H_FILES/LCD.h"


#include <avr/delay.h>

static void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command);
static void HAL_LCD_voidWriteData(uint8_t Copy_u8DATA);

static void HAL_LCD_voidWriteCommand_4_Bit_Mode(uint8_t Copy_u8Command);
static void HAL_LCD_voidWriteCommand_8_Bit_Mode(uint8_t Copy_u8Command);

static void HAL_LCD_voidWriteData_4_Bit_Mode(uint8_t Copy_u8Data);
static void HAL_LCD_voidWriteData_8_Bit_Mode(uint8_t Copy_u8Data);

static void HAL_LCD_voidInitialize_4_Bit_Mode(void);
static void HAL_LCD_voidInitialize_8_Bit_Mode(void);

void HAL_LCD_voidInitialize(void){
	#if (LCD_MODE == 4)
		HAL_LCD_voidInitialize_4_Bit_Mode();
	#elif (LCD_MODE == 8)
		HAL_LCD_voidInitialize_8_Bit_Mode();
	#else
	#endif
}

void HAL_LCD_voidClearLCD(void){
	_delay_ms(2);
	HAL_LCD_voidWriteCommand(LCD_CLEAR_COMMAND);
	_delay_ms(2);
}

void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character){
	HAL_LCD_voidWriteData(Copy_u8Character);
}

void HAL_LCD_voidWriteString(uint8_t *Ptr_u8String){
	uint8_t charLoop = 0;
	while(Ptr_u8String[charLoop] != NULL_CHAR){
		HAL_LCD_voidWriteData(Ptr_u8String[charLoop++]);
	}
}

void HAL_LCD_voidMoveCursor(uint8_t Copy_u8RowNumber, uint8_t Copy_u8ColNumber){
	HAL_LCD_voidWriteCommand(128+(0x40*Copy_u8RowNumber)+Copy_u8ColNumber);
}

/////////////////////////////////////////////////// Static Methods

/* Write COMMAND */
void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command){
	#if (LCD_MODE == 4)
		HAL_LCD_voidWriteCommand_4_Bit_Mode(Copy_u8Command);
	#elif (LCD_MODE == 8)
		HAL_LCD_voidWriteCommand_8_Bit_Mode(Copy_u8Command);
	#else
	#endif
}

void HAL_LCD_voidWriteCommand_4_Bit_Mode(uint8_t Copy_u8Command){
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0f) | (Copy_u8Command & 0xf0);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0f) | (Copy_u8Command <<4);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
}

void HAL_LCD_voidWriteCommand_8_Bit_Mode(uint8_t Copy_u8Command){
		MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
		MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_LOW);
		MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
		MCAL_DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8Command);
		MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
		_delay_ms(1);
		MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
}


/* Write DATA */
void HAL_LCD_voidWriteData(uint8_t Copy_u8Data){
	#if (LCD_MODE == 4)
	HAL_LCD_voidWriteData_4_Bit_Mode(Copy_u8Data);
	#elif (LCD_MODE == 8)
	HAL_LCD_voidWriteData_8_Bit_Mode(Copy_u8Data);
	#else
	#endif
}

void HAL_LCD_voidWriteData_4_Bit_Mode(uint8_t Copy_u8Data){
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_HIGH);
	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0f) | (Copy_u8Data & 0xf0);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_HIGH);
	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
	LCD_DATA_PORT_REG = (LCD_DATA_PORT_REG & 0x0f) | (Copy_u8Data <<4);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
}

void HAL_LCD_voidWriteData_8_Bit_Mode(uint8_t Copy_u8Data){
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
	MCAL_DIO_u8SetPinValue(LCD_RS_PIN , DIO_HIGH);
	MCAL_DIO_u8SetPinValue(LCD_RW_PIN , DIO_LOW);
	MCAL_DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8Data);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MCAL_DIO_u8SetPinValue(LCD_EN_PIN , DIO_LOW);
}

/* Initialization */
void HAL_LCD_voidInitialize_4_Bit_Mode(void){
		MCAL_DIO_u8SetPortDir(LCD_DATA_PORT,DIO_PORT_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_RS_PIN , DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_RW_PIN , DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_EN_PIN , DIO_OUTPUT);
		_delay_ms(30);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_4BIT_33);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_4BIT_32);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_4BIT_COMMAND);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_COMMAND);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_CLEAR_COMMAND);
		_delay_ms(2);
}

void HAL_LCD_voidInitialize_8_Bit_Mode(void){
		MCAL_DIO_u8SetPortDir(LCD_DATA_PORT,DIO_PORT_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_RS_PIN , DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_RW_PIN , DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(LCD_EN_PIN , DIO_OUTPUT);
		_delay_ms(30);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_8BIT_COMMAND);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_INITIALIZE_COMMAND);
		_delay_ms(2);
		HAL_LCD_voidWriteCommand(LCD_CLEAR_COMMAND);
		_delay_ms(2);
}