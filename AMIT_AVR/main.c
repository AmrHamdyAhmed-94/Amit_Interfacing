#include "MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "LIBRARIES_H/STD_TYPES.h"
#include "LIBRARIES_H/BIT_MATH.h"

#include "MCAL/DIO/H_FILES/DIO.h"
#include "HAL/LEDS/H_FILES/LEDS_CONFIG.h"
#include "HAL/LEDS/H_FILES/LEDS.h"
/*
#include "HAL/BUTTONS/H_FILES/BUTTON.h"
#include "HAL/BUZZER/H_FILES/BUZZER.h"
#include "HAL/S_SEGMENT/H_FILES/S_SEGMENT.h"
#include "HAL/KEYPAD/H_FILES/KEYPAD.h"
#include "HAL/LCD/H_FILES/LCD.h"*/

#include <util/delay.h>

#define F_CPU 8000000UL

int main(void){
	HAL_LED_GENERIC_INITIALIZATION(LED_0);
	HAL_LED_GENERIC_turnOn(LED_0);
	_delay_ms(2000);
	HAL_LED_GENERIC_turnOff(LED_0);

}
