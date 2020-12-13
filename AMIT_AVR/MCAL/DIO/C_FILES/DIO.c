#include "../../../LIBRARIES_H/BIT_MATH.h"
#include "../../../LIBRARIES_H/STD_TYPES.h"

#include "../H_FILES/AVR_DIO_REG.h"
#include "../H_FILES/DIO.h"

uint8_t MCAL_DIO_u8SetPinDir(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Dir ){
	uint8_t Local_u8ErrorStatus  = 1;
	if(Copy_u8PinNo >= DIO_PIN_0 && Copy_u8PinNo <= DIO_PIN_7){
		switch(Copy_u8PortNo){
			case DIO_PORTA :
				ASSIGN_BIT(DDRA , Copy_u8PinNo , Copy_u8Dir);
				break ;
			case DIO_PORTB :
				ASSIGN_BIT(DDRB , Copy_u8PinNo , Copy_u8Dir);
				break ;
			case DIO_PORTC :
				ASSIGN_BIT(DDRC , Copy_u8PinNo , Copy_u8Dir);
				break ;
			case DIO_PORTD :
				ASSIGN_BIT(DDRD , Copy_u8PinNo , Copy_u8Dir);
				break ;
			default :
				Local_u8ErrorStatus = 0;
				break;
		}
	}else{
		Local_u8ErrorStatus = 0 ;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8SetPortDir(uint8_t Copy_u8PortNo ,uint8_t Copy_u8Dir ){
	uint8_t Local_u8ErrorStatus  = 1;
	switch(Copy_u8PortNo){
		case DIO_PORTA :
			DDRA = Copy_u8Dir;
			break ;
		case DIO_PORTB :
			DDRA = Copy_u8Dir;
			break ;
		case DIO_PORTC :
			DDRA = Copy_u8Dir;
			break ;
		case DIO_PORTD :
			DDRA = Copy_u8Dir;
			break ;
		default :
			Local_u8ErrorStatus = 0;
			break;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8SetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Value ){
	uint8_t Local_u8ErrorStatus  = 1;
	if(Copy_u8PinNo >= DIO_PIN_0 && Copy_u8PinNo <= DIO_PIN_7){
		switch(Copy_u8PortNo){
			case DIO_PORTA :
				ASSIGN_BIT(PORTA , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTB :
				ASSIGN_BIT(PORTB , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTC :
				ASSIGN_BIT(PORTC , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTD :
				ASSIGN_BIT(PORTD , Copy_u8PinNo , Copy_u8Value);
				break ;
			default :
				Local_u8ErrorStatus = 0;
				break;
		}
	}else{
		Local_u8ErrorStatus = 0 ;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8SetPortValue(uint8_t Copy_u8PortNo ,uint8_t Copy_u8Value ){
	uint8_t Local_u8ErrorStatus  = 1;
	switch(Copy_u8PortNo){
		case DIO_PORTA :
			PORTA = Copy_u8Value;
			break ;
		case DIO_PORTB :
			PORTA = Copy_u8Value;
			break ;
		case DIO_PORTC :
			PORTA = Copy_u8Value;
			break ;
		case DIO_PORTD :
			PORTA = Copy_u8Value;
			break ;
		default :
			Local_u8ErrorStatus = 0;
			break;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8GetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t *ptr_u8Value){
	uint8_t Local_u8ErrorStatus = 1;
	if(Copy_u8PinNo >= DIO_PIN_0 && Copy_u8PinNo <= DIO_PIN_7){
		switch(Copy_u8PortNo){
			case DIO_PORTA :
				*ptr_u8Value = GET_BIT(PINA , Copy_u8PinNo);
				break ;
			case DIO_PORTB :
				*ptr_u8Value = GET_BIT(PINB , Copy_u8PinNo);
				break ;
			case DIO_PORTC :
				*ptr_u8Value = GET_BIT(PINC , Copy_u8PinNo);
				break ;
			case DIO_PORTD :
				*ptr_u8Value = GET_BIT(PIND , Copy_u8PinNo);
				break ;
			default :
				Local_u8ErrorStatus = 0;
				break;
		}
	}else{
		Local_u8ErrorStatus = 0 ;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8GetPortValue(uint8_t Copy_u8PortNo ,uint8_t *ptr_u8Value ){
	uint8_t Local_u8ErrorStatus = 1;
	switch(Copy_u8PortNo){
		case DIO_PORTA :
			*ptr_u8Value = PINA ;
			break ;
		case DIO_PORTB :
			*ptr_u8Value = PINB ;
				break ;
		case DIO_PORTC :
			*ptr_u8Value = PINC ;
				break ;
		case DIO_PORTD :
			*ptr_u8Value = PIND ;
				break ;
		default :
			Local_u8ErrorStatus = 0;
			break;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8SetPinInputType(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Value ){
	uint8_t Local_u8ErrorStatus  = 1;
	if(Copy_u8PinNo >= DIO_PIN_0 && Copy_u8PinNo <= DIO_PIN_7){
		switch(Copy_u8PortNo){
			case DIO_PORTA :
				ASSIGN_BIT(PORTA , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTB :
				ASSIGN_BIT(PORTB , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTC :
				ASSIGN_BIT(PORTC , Copy_u8PinNo , Copy_u8Value);
				break ;
			case DIO_PORTD :
				ASSIGN_BIT(PORTD , Copy_u8PinNo , Copy_u8Value);
				break ;
			default :
				Local_u8ErrorStatus = 0;
				break;
		}
	}else{
		Local_u8ErrorStatus = 0 ;
	}
	return Local_u8ErrorStatus ;
}

uint8_t MCAL_DIO_u8SetPortInputType(uint8_t Copy_u8PortNo  ,uint8_t Copy_u8Value ){
	uint8_t Local_u8ErrorStatus  = 1;
	switch(Copy_u8PortNo){
		case DIO_PORTA :
			PORTA = Copy_u8Value;
			break ;
		case DIO_PORTB :
			PORTB = Copy_u8Value;
			break ;
		case DIO_PORTC :
			PORTC = Copy_u8Value;
			break ;
		case DIO_PORTD :
			PORTD = Copy_u8Value;
			break ;
		default :
			Local_u8ErrorStatus = 0;
			break;
	}
	return Local_u8ErrorStatus ;
}
