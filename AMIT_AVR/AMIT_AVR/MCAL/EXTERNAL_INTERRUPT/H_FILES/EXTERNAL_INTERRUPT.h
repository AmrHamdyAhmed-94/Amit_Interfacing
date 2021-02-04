/*
 * External_Interrupt.h
 *
 * Created: 12/24/2020 8:48:17 PM
 *  Author: Amrha
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#define EXTERNAL_INTERRUPT_0 0		
#define EXTERNAL_INTERRUPT_1 1		
#define EXTERNAL_INTERRUPT_2 2		

#define EXTERNAL_INTERRUPT_DISABLE 0
#define EXTERNAL_INTERRUPT_ENABLE 1

#define EXTERNAL_INTERRUPT_FALLING_EDGE	 	0  		
#define EXTERNAL_INTERRUPT_RISING_EDGE 		1		
#define EXTERNAL_INTERRUPT_ON_CHANGE 		2		
#define EXTERNAL_INTERRUPT_LOW_LEVEL 		3		

extern uint8_t MCAL_EXTINT_u8Init(uint8_t Copy_u8ExtIntNo , uint8_t Copy_u8LevelDetection);
extern uint8_t MCAL_EXTINT_u8LevelDetection(uint8_t Copy_u8ExtIntNo , uint8_t Copy_u8LevelDetection);
extern uint8_t MCAL_EXTINT_SetCallBack(uint8_t Copy_u8ExtIntNo , void (*Ptr_ToFunction) (void));

#endif /* EXTERNAL_INTERRUPT_H_ */