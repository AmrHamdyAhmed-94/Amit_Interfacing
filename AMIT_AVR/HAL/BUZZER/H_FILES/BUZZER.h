/*
 * BUZZER.h
 *
 * Created: 12/11/2020 11:06:25 AM
 *  Author: Amrha
 */ 

#ifndef BUZZER_H_
#define BUZZER_H_

void HAL_BUZZER_GENERIC_INITIALIZATION(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin);
void HAL_BUZZER_GENERIC_turnOn(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin);
void HAL_BUZZER_GENERIC_turnOff(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin);
void HAL_BUZZER_GENERIC_toggle(uint8_t Copy_u8BuzzerPort , uint8_t Copy_u8BuzzerPin , uint8_t *state);

#if 0
void initialize_BUZZER();
void turn_ON_BUZZER();
void turn_OFF_BUZZER();
void toggle_BUZZER(uint8_t *state);
#endif

#endif /* BUZZER_H_ */