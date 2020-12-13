/*
 * BUZZER.c
 *
 * Created: 12/11/2020 11:06:37 AM
 *  Author: Amrha
 */ 
 #include "../../../LIBRARIES_H/STD_TYPES.h"
 #include "../../../LIBRARIES_H/BIT_MATH.h"

 #include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/BUZZER_CONFIG.h"
 #include "../H_FILES/BUZZER.h"

 void HAL_BUZZER_GENERIC_INITIALIZATION(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin){
	MCAL_DIO_u8SetPinDir(Copy_u8BuzzerPort , Copy_u8BuzzerPin , DIO_OUTPUT);
 }
 void HAL_BUZZER_GENERIC_turnOn(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin){
	MCAL_DIO_u8SetPinValue(Copy_u8BuzzerPort , Copy_u8BuzzerPin , DIO_HIGH);
 }
 void HAL_BUZZER_GENERIC_turnOff(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin){
	MCAL_DIO_u8SetPinValue(Copy_u8BuzzerPort , Copy_u8BuzzerPin , DIO_LOW);
 }
 void HAL_BUZZER_GENERIC_toggle(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin , uint8_t *state){
	MCAL_DIO_u8SetPinValue(Copy_u8BuzzerPort , Copy_u8BuzzerPin , TOGGLE_BIT(*state,DIO_LOW));
 }

 #if 0 /* OLD CODE*/

 void initialize_BUZZER(){
	MCAL_DIO_u8SetPinDir(DIO_PORTA , DIO_PIN_3 , DIO_OUTPUT);
 }

 void turn_ON_BUZZER(){
	MCAL_DIO_u8SetPinValue(DIO_PORTA , DIO_PIN_3 , DIO_HIGH);
 }

 void turn_OFF_BUZZER(){
	MCAL_DIO_u8SetPinValue(DIO_PORTA , DIO_PIN_3 , DIO_LOW);
 }

 void toggle_BUZZER(uint8_t *state){
	 MCAL_DIO_u8SetPinValue(DIO_PORTA , DIO_PIN_3 , TOGGLE_BIT(*state,DIO_LOW));
 }

 #endif