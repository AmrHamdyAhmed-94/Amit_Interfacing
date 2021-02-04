#include "../../../LIBRARIES_H/BIT_MATH.h"
#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../DIO/H_FILES/AVR_DIO_REG.h"
#include "../../DIO/H_FILES/DIO.h"
#include "../H_FILES/AVR_INTERRUPT_REG.h"
#include "../H_FILES/EXTERNAL_INTERRUPT.h"

 void (*g_PtrCallBack_INT0)(void) = NULL_POINTER;
 void (*g_PtrCallBack_INT1)(void) = NULL_POINTER;
 void (*g_PtrCallBack_INT2)(void) = NULL_POINTER;

 static void __vector_1(void)__attribute((signal,used));
 static void __vector_2(void)__attribute((signal,used));
 static void __vector_3(void)__attribute((signal,used));

 uint8_t MCAL_EXTINT_u8Init(uint8_t Copy_u8ExtIntNo , uint8_t Copy_u8LevelDetection){
	 uint8_t Local_Error_Statue = NO_ERROR ;
	 switch(Copy_u8ExtIntNo){
		 case EXTERNAL_INTERRUPT_0 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC01);
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC00);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC01);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC00);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_ON_CHANGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_LOW_LEVEL){
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else{
				 Local_Error_Statue = ERROR;
			 }

			 if(Local_Error_Statue == NO_ERROR){
				 SET_BIT(EXTINT_SREG , SREG_GLOBAL_ENABLE);					/*Enable Global Interrupt*/
				 SET_BIT(EXTINT_GICR , GICR_INT_0);							/*Enable INT 0*/
			 }
			break ;
		 case EXTERNAL_INTERRUPT_1 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC11);
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC10);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC11);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC10);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_ON_CHANGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC10);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC11);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_LOW_LEVEL){
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC10);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC11);
			 }else{
				 Local_Error_Statue = ERROR;								/*Error Status : Error*/
			 }

			 if(Local_Error_Statue == NO_ERROR){
				 SET_BIT(EXTINT_SREG , SREG_GLOBAL_ENABLE);					/*Enable Global Interrupt*/
				 SET_BIT(EXTINT_GICR , GICR_INT_1);							/*Enable INT 1*/
			 }
			 break ;
		 case EXTERNAL_INTERRUPT_2 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUSCR , MCUSCR_ISC2);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 CLR_BIT(EXTINT_MCUSCR , MCUSCR_ISC2);
			 }else{
				 Local_Error_Statue = ERROR ;
			 }

			 if(Local_Error_Statue == NO_ERROR){
				 SET_BIT(EXTINT_SREG , SREG_GLOBAL_ENABLE);					/*Enable Global Interrupt*/
				 SET_BIT(EXTINT_GICR , GICR_INT_2);							/*Enable INT 2*/
			 }
			 break ;
		 default :
			Local_Error_Statue = ERROR ;
		 break;
	 }
	 return Local_Error_Statue ;
 }

 uint8_t MCAL_EXTINT_u8LevelDetection(uint8_t Copy_u8ExtIntNo , uint8_t Copy_u8LevelDetection){
	 uint8_t Local_Error_Statue = NO_ERROR ;
	 switch(Copy_u8ExtIntNo){
		 case EXTERNAL_INTERRUPT_0 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_ON_CHANGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_LOW_LEVEL){
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC00);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC01);
			 }else{
				 Local_Error_Statue = ERROR;								/*Error Status : Error*/
			 }
			 break ;

		 case EXTERNAL_INTERRUPT_1 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC11);
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC10);

			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC11);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC10);

			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_ON_CHANGE){
				 SET_BIT(EXTINT_MCUCR , MCUCR_ISC10);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC11);

			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_LOW_LEVEL){
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC10);
				 CLR_BIT(EXTINT_MCUCR , MCUCR_ISC11);
			 }else{
				 Local_Error_Statue = ERROR;								/*Error Status : Error*/
			 }
		break ;
		case EXTERNAL_INTERRUPT_2 :
			 if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_RISING_EDGE){
				 SET_BIT(EXTINT_MCUSCR , MCUSCR_ISC2);
			 }else if(Copy_u8LevelDetection == EXTERNAL_INTERRUPT_FALLING_EDGE){
				 CLR_BIT(EXTINT_MCUSCR , MCUSCR_ISC2);
			 }else{
				 Local_Error_Statue = ERROR ;
			 }
		break ;
		default :
			Local_Error_Statue = ERROR ;
		break;
	 }
	 return Local_Error_Statue ;
 }

 uint8_t MCAL_EXTINT_SetCallBack(uint8_t Copy_u8ExtIntNo , void (*Ptr_ToFunction) (void)){
	 uint8_t Local_Error_Statue = NO_ERROR;
	 switch(Copy_u8ExtIntNo){
		case EXTERNAL_INTERRUPT_0 :
			 g_PtrCallBack_INT0 = Ptr_ToFunction ;    	/*Pointer to Function to send to ISR*/
		break;
		case EXTERNAL_INTERRUPT_1 :
			 g_PtrCallBack_INT1 = Ptr_ToFunction ;		/*Pointer to Function to send to ISR*/
		break;
		case EXTERNAL_INTERRUPT_2 :
			 g_PtrCallBack_INT2 = Ptr_ToFunction ;		/*Pointer to Function to send to ISR*/
		break;
		default :
			Local_Error_Statue = ERROR;
		break ;
	 }
	 return Local_Error_Statue ;
 }

void __vector_1(void){
	if(g_PtrCallBack_INT0 != NULL){
		g_PtrCallBack_INT0();
	}
}

void __vector_2(void){
	if(g_PtrCallBack_INT1 != NULL){
		g_PtrCallBack_INT1();
	}
}

void __vector_3(void){
	if(g_PtrCallBack_INT2 != NULL){
		g_PtrCallBack_INT2();
	}
}
