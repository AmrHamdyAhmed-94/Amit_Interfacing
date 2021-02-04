/*
 * KEYPAD.h
 *
 * Created: 12/11/2020 5:34:16 PM
 *  Author: Amrha
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

extern void HAL_KEYPAD_voidInitialize(void);
extern void HAL_KEYPAD_voidGetKeyPressed_Once(uint8_t *ptr_u8_KeyPressed);
extern void HAL_KEYPAD_voidGetKeyPressed_Continous(uint8_t * ptr_u8KeyPressed, uint16_t Copy_DelayBetweenClicks_ms);


#endif /* KEYPAD_H_ */