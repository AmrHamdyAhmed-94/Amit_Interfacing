/*
 * BUTTON.h
 *
 * Created: 12/11/2020 10:09:03 AM
 *  Author: Amrha
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void HAL_BUTTON_GENERIC_INITIALIZATION(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin);
uint8_t HAL_BUTTON_GENERIC_getButtonValue(uint8_t Copy_u8BuzzerPort ,uint8_t Copy_u8BuzzerPin ,uint8_t *BUTTON_VALUE);

#if 0 /* OLD CODE*/

void initialize_BUTTON_0();
void initialize_BUTTON_1();
void initialize_BUTTON_2();

uint8_t get_BUTTON_0_VALUE();
uint8_t get_BUTTON_1_VALUE();
uint8_t get_BUTTON_2_VALUE();

#endif

#endif /* BUTTON_H_ */