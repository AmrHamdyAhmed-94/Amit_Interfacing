#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../../LIBRARIES_H/BIT_MATH.h"

#include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/S_SEGMENT_CONFIG.h"
#include "../H_FILES/S_SEGMENT.h"

void initialize_S_SEGMENT(){
	MCAL_DIO_u8SetPinDir(S_SEGMENT_ENABLE_2 , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_ENABLE_1 , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_DOT , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_A , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_B , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_C , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir(S_SEGMENT_D , DIO_OUTPUT);
}

void turn_ON_S_SEGMENT_1(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_ENABLE_1 , DIO_HIGH);
}

void turn_ON_S_SEGMENT_2(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_ENABLE_2 , DIO_HIGH);
}

void turn_ON_S_SEGMENT_DOT(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_DOT , DIO_HIGH);
}

void show_ON_S_SEGMENT(uint8_t value){
	MCAL_DIO_u8SetPortValue(DIO_PORTA , value<<4);
}

void turn_OFF_S_SEGMENT_1(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_ENABLE_1 , DIO_LOW);
}

void turn_OFF_S_SEGMENT_2(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_ENABLE_2 , DIO_LOW);
}

void turn_OFF_S_SEGMENT_DOT(){
	MCAL_DIO_u8SetPinValue(S_SEGMENT_DOT , DIO_LOW);
}
