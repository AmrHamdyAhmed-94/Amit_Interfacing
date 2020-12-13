 #include "../../../LIBRARIES_H/STD_TYPES.h"
 #include "../../../LIBRARIES_H/BIT_MATH.h"

 #include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "../../../MCAL/DIO/H_FILES/DIO.h"

 #include "../H_FILES/BUTTONS_CONFIG.h"
 #include "../H_FILES/BUTTON.h"

void HAL_BUTTON_GENERIC_INITIALIZATION(uint8_t Copy_u8ButtonPort , uint8_t Copy_u8ButtonPin){
	MCAL_DIO_u8SetPinDir(Copy_u8ButtonPort ,Copy_u8ButtonPin , DIO_INPUT);
}

uint8_t HAL_BUTTON_GENERIC_getButtonValue(uint8_t Copy_u8ButtonPort , uint8_t Copy_u8ButtonPin , uint8_t *BUTTON_VALUE){
	MCAL_DIO_u8GetPinValue(Copy_u8ButtonPort ,Copy_u8ButtonPin ,BUTTON_VALUE);
}

#if 0 /*   OLD CODE    */
 void initialize_BUTTON_0(){
	  MCAL_DIO_u8SetPinDir(DIO_PORTB , DIO_PIN_0 , DIO_INPUT);
 }
 void initialize_BUTTON_1(){
	  MCAL_DIO_u8SetPinDir(DIO_PORTB , DIO_PIN_4 , DIO_INPUT);
 }
 void initialize_BUTTON_2(){
	 MCAL_DIO_u8SetPinDir(DIO_PORTD , DIO_PIN_2 , DIO_INPUT);
 }

 uint8_t get_BUTTON_0_VALUE(){
	uint8_t BUTTON_0_VALUE;
	MCAL_DIO_u8GetPinValue(DIO_PORTB , DIO_PIN_0, &BUTTON_0_VALUE);
	return BUTTON_0_VALUE;
 }

 uint8_t get_BUTTON_1_VALUE(){
	  uint8_t BUTTON_1_VALUE;
	  MCAL_DIO_u8GetPinValue(DIO_PORTB , DIO_PIN_4, &BUTTON_1_VALUE);
	  return BUTTON_1_VALUE;
 }

 uint8_t get_BUTTON_2_VALUE(){
	   uint8_t BUTTON_2_VALUE;
	   MCAL_DIO_u8GetPinValue(DIO_PORTD , DIO_PIN_2, &BUTTON_2_VALUE);
	   return BUTTON_2_VALUE;
 }
 #endif