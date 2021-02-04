#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../../LIBRARIES_H/BIT_MATH.h"

#include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/LEDS_CONFIG.h"
#include "../H_FILES/LEDS.h"

 void HAL_LED_GENERIC_INITIALIZATION(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin){
	 MCAL_DIO_u8SetPinDir(Copy_u8LedPort , Copy_u8LedPin , DIO_OUTPUT);
 }

 void HAL_LED_GENERIC_TURN_ON(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin){
	 MCAL_DIO_u8SetPinValue(Copy_u8LedPort , Copy_u8LedPin , DIO_HIGH);
 }

 void HAL_LED_GENERIC_TURN_OFF(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin){
	 MCAL_DIO_u8SetPinValue(Copy_u8LedPort , Copy_u8LedPin , DIO_LOW);
 }

 void HAL_LED_GENERIC_TOGGLE(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin , uint8_t *state){
	 MCAL_DIO_u8SetPinValue(Copy_u8LedPort , Copy_u8LedPin , TOGGLE_BIT(*state,DIO_LOW));
 }


#if 0 /* OLD CODE*/

 void initialize_LED_0(){
	 MCAL_DIO_u8SetPinDir(LED_0 , DIO_OUTPUT);
 }
 void initialize_LED_1(){
	MCAL_DIO_u8SetPinDir(LED_1 , DIO_OUTPUT);
 }
 void initialize_LED_2(){
	  MCAL_DIO_u8SetPinDir(LED_2 , DIO_OUTPUT);
 }
  void initialize_LED_2(){
	  MCAL_DIO_u8SetPinDir(LED_2 , DIO_OUTPUT);
 }

 void turn_ON_LED_0(){
	  MCAL_DIO_u8SetPinValue(LED_0 , DIO_HIGH);
 }
 void turn_ON_LED_1(){
	  MCAL_DIO_u8SetPinValue(LED_1 , DIO_HIGH);
 }
 void turn_ON_LED_2(){
	  MCAL_DIO_u8SetPinValue(LED_2 , DIO_HIGH);
 }

void turn_OFF_LED_0(){
	  MCAL_DIO_u8SetPinValue(LED_0 , DIO_LOW);
  }
void turn_OFF_LED_1(){
	  MCAL_DIO_u8SetPinValue(LED_1 , DIO_LOW);
  }
void turn_OFF_LED_2(){
	  MCAL_DIO_u8SetPinValue(LED_2 , DIO_LOW);
}

void toggle_LED_0(uint8_t *state){
	MCAL_DIO_u8SetPinValue(LED_0 , TOGGLE_BIT(*state,DIO_LOW));
}
void toggle_LED_1(uint8_t *state){
	MCAL_DIO_u8SetPinValue(LED_1 , TOGGLE_BIT(*state,DIO_LOW));
}
void toggle_LED_2(uint8_t *state){
	MCAL_DIO_u8SetPinValue(LED_2 , TOGGLE_BIT(*state,DIO_LOW));
}

#endif
