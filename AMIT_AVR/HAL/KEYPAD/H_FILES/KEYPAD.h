/*
 * KEYPAD.h
 *
 * Created: 12/11/2020 5:34:16 PM
 *  Author: Amrha
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void HAL_KEYPAD_voidInitialize(void);
void HAL_KEYPAD_voidGetKeyPressedOnce(uint8_t *ptr_u8_KeyPressed);
void HAL_KEYPAD_voidGetKeyPressedContinous(uint8_t *ptr);


#endif /* KEYPAD_H_ */