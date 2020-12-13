#ifndef LEDS_H_
#define LEDS_H_

void HAL_LED_GENERIC_INITIALIZATION(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin);
void HAL_LED_GENERIC_turnOn(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin);
void HAL_LED_GENERIC_turnOff(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin);
void HAL_LED_GENERIC_toggle(uint8_t Copy_u8LedPort , uint8_t Copy_u8LedPin , uint8_t *state);

#if 0 /* OLD CODE*/
 void initialize_LED_0();
 void initialize_LED_1();
 void initialize_LED_2();

 void turn_ON_LED_0();
 void turn_ON_LED_1();
 void turn_ON_LED_2();

 void turn_OFF_LED_0();
 void turn_OFF_LED_1();
 void turn_OFF_LED_2();

 void toggle_LED_0(uint8_t *state);
 void toggle_LED_1(uint8_t *state);
 void toggle_LED_2(uint8_t *state);
 #endif
#endif /* LEDS_H_ */