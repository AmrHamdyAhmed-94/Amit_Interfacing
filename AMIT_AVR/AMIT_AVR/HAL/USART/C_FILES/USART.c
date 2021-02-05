#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../../LIBRARIES_H/BIT_MATH.h"

#include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/USART_REG.h"
#include "../H_FILES/USART_CONFIG.h"
#include "../H_FILES/USART.h"

#define BITS_LESS_THAN_9  	0
#define BITS_EQUAL_9  		1

#define MAX_8_bit 			255


uint8_t g_FlagMode ;
uint8_t g_CharacterSize ;


void __vector_14(void)__attribute((signal,used));
void __vector_13(void)__attribute((signal,used));

static uint16_t *UART_UDR_CallBack=0;

static void (*UART_RX_CallBack)(uint16_t Copy_u16UartValue)=0;

/*- FUNCTION DEFINITIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
* Output    : Error Status
* */
uint8_t MCAL_UART_init(str_UartConfg_t * Uart_Config){

	uint8_t Local_u8Error = NO_ERROR ;   /*Error Status*/
	uint16_t Local_u16_UBRR_Value ;

	/*_______________________________________________________________________________*/

		/*Set Baud Rate According to the Clock
		 * UBRR = (fOSC / (16 * BAUD) )– 1*/
		Local_u16_UBRR_Value = ((uint64_t) SYSTEM_FREQUENCY / ( (uint64_t) 16 * Uart_Config->u32_BaudRate )) - 1 ;

		if(Local_u16_UBRR_Value <= MAX_8_bit ){
			UBBRRL = Local_u16_UBRR_Value  ;
		}else{
			CLR_BIT(UCSRC , UCSRC_URSEL);
			UBBRRH = (uint8_t)(Local_u16_UBRR_Value >> 8 );
			UBBRRL = (uint8_t)Local_u16_UBRR_Value ;
		}
	SET_BIT(UCSRC , UCSRC_URSEL );       /*Select The UCSRC Register*/
	/*Assign the Parity Check
	 * _____________________________________________________________________*/
	#if UART_PARITY_CHECK_BIT == UART_PARITY_DISABLE
		CLR_BIT(UCSRC , UCSRC_UPM1);
		CLR_BIT(UCSRC , UCSRC_UPM0);
	#elif UART_PARITY_CHECK_BIT == UART_PARITY_EVEN
		SET_BIT(UCSRC , UCSRC_UPM1);
		CLR_BIT(UCSRC , UCSRC_UPM0);
	#elif UART_PARITY_CHECK_BIT == UART_PARITY_ODD
		SET_BIT(UCSRC , UCSRC_UPM1);
		SET_BIT(UCSRC , UCSRC_UPM0);
	#else
		Local_u8Error = ERROR ;
	#endif
	/*______________________________________________________________________*/

	/*Assign the Stop Bit Mode
	 _______________________________________________________________________ */

	ASSIGN_BIT(UCSRC , UCSRC_USBS , UART_STOP_BIT);

	/*_______________________________________________________________________*/
	/*Assign Synchronization Mode
	 * _______________________________________________________________________ */
	ASSIGN_BIT(UCSRC , UCSRC_UMSEL , UART_SYNCHRONOUS_MODE);

	/*________________________________________________________________________*/

	/*Set Character Size to send from 5 to 9 bits
	 * _______________________________________________________________________*/

	g_CharacterSize = BITS_LESS_THAN_9 ;

	if(Uart_Config ->u8_DataBits == UART_5_BIT_MODE){         /*5 Bits Mode*/
		CLR_BIT(UCSRC,UCSRC_UCSZ0);  /*In Case 5 Bits*/
		CLR_BIT(UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
	}else if(Uart_Config ->u8_DataBits == UART_6_BIT_MODE){   /*6 Bits Mode*/
		UCSRB|= (1<<UCSRB_TXEN)|(1<<UCSRB_RXEN);                // enable receiver and transmitter
		UCSRC|= (1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ0);   // 8bit data format
		CLR_BIT(UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
	}else if(Uart_Config ->u8_DataBits == UART_7_BIT_MODE){   /*7 Bits Mode*/
		UCSRB|= (1<<UCSRB_TXEN)|(1<<UCSRB_RXEN);                // enable receiver and transmitter
		UCSRC|= (1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1);   // 8bit data format
		CLR_BIT(UCSRC,UCSRC_UCSZ0);   /*In Case 7 Bits*/
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
	}else if(Uart_Config ->u8_DataBits == UART_8_BIT_MODE){	/*8 Bits Mode*/
		UCSRB|= (1<<UCSRB_TXEN)|(1<<UCSRB_RXEN);                // enable receiver and transmitter
		UCSRC|= (1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1);   // 8bit data format
	}
	else if(Uart_Config ->u8_DataBits == UART_9_BIT_MODE){	/*8 Bits Mode*/
		SET_BIT(UCSRB,UCSRB_UCSZ2);
		UCSRB|= (1<<UCSRB_TXEN)|(1<<UCSRB_RXEN);                // enable receiver and transmitter
		UCSRC|= (1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1);   // 8bit data format
		g_CharacterSize = BITS_EQUAL_9 ;
	}else{
		Local_u8Error = ERROR ;   /*Error Status */
	}

	g_FlagMode = Uart_Config->u8_FlagAction ;

	/*Set Flag Action
	 * ____________________________________________________________________________*/

	if(Uart_Config->u8_FlagAction == UART_INTERRUPT){
		SET_BIT(SREG , GLOBAL_INTERRUPT_BIT);        /*Enable Global Interrupt Flag*/

	}else if(Uart_Config->u8_FlagAction == UART_POLLING){
		CLR_BIT(UCSRB , UCSRB_RXCIE);               /*Disable Receive Interrupt*/
		CLR_BIT(UCSRB , UCSRB_UDRIE);               /*Disable Transmit Interrupt*/
	}else{
		Local_u8Error = ERROR ;
	}
	return Local_u8Error ;
}

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
uint8_t MCAL_UART_sendByteBusyWait(const uint16_t u16_Data){
	uint8_t Local_u8Error = NO_ERROR ;
	while(GET_BIT(UCSRA , UCSRA_UDRE ) != 1);
	if(g_CharacterSize == BITS_EQUAL_9){
		ASSIGN_BIT(UCSRC ,  UCSRA_TXC  , (GET_BIT(u16_Data , 9))  );
		UDR = u16_Data ;
	}else{
		UDR = u16_Data ;
	}
	return Local_u8Error ;
}

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
uint8_t MCAL_UART_recieveByteBusyWait(uint16_t *u16_Data){
	uint8_t Local_u8Error = NO_ERROR ;
	SET_BIT(UCSRB , UCSRB_RXEN);
	while(GET_BIT(UCSRA , UCSRA_RXC) != 1);
	while(GET_BIT(UCSRA , UCSRA_UDRE ) != 1);
	if(g_CharacterSize == BITS_EQUAL_9){
		ASSIGN_BIT(*u16_Data ,  9  , (GET_BIT(UCSRC , UCSRA_RXC))  );
		*u16_Data = UDR ;
	}else{
		*u16_Data = UDR ;
	}
	return Local_u8Error ;
}

/*************************************************************
*Description: MCAL_UART_RecieveCallBack
* Input     : pointer to Function
* Output    : Error Status
* */
uint8_t MCAL_UART_RecieveCallBack(void (*ptr_PointerToFunction)(uint16_t Copy_u16UartValue)){
	uint8_t Local_u8Error = NO_ERROR ;
	if(ptr_PointerToFunction != NULL_POINTER){
		SET_BIT(UCSRB , UCSRB_RXEN);
		SET_BIT(UCSRB , UCSRB_RXCIE);
		UART_RX_CallBack = ptr_PointerToFunction ;
	}else{
		Local_u8Error = ERROR ;
	}
	return Local_u8Error ;
}

void __vector_13(void){
	uint16_t u16_Data ;
	if(UART_RX_CallBack != NULL_POINTER){
		if(g_CharacterSize == BITS_EQUAL_9){
			ASSIGN_BIT(u16_Data ,  9  , (GET_BIT(UCSRC , UCSRA_RXC))  );
			while(GET_BIT(UCSRA , UCSRA_UDRE ) != 1);
			u16_Data = UDR ;
		}else{
			while(GET_BIT(UCSRA , UCSRA_UDRE ) != 1);
			u16_Data = UDR ;
		}
		UART_RX_CallBack(u16_Data);
	}
}

/*************************************************************
*Description: MCAL_UART_SendCallBack
* Input     : pointer to Value
* Output    : Error Status
* */
uint8_t MCAL_UART_SendCallBack(uint16_t *u16UartValue){
	uint8_t Local_u8Error = NO_ERROR ;
	if(u16UartValue != NULL_POINTER){
		SET_BIT(UCSRB , UCSRB_TXEN);
		UART_UDR_CallBack = u16UartValue ;
		SET_BIT(UCSRB , UCSRB_UDRIE); 				/*Enable Transmit Interrupt*/
	}else{
		Local_u8Error  = ERROR;
	}
	return Local_u8Error ;
}

void __vector_14(void){
	UDR = *UART_UDR_CallBack ;
	while(GET_BIT(UCSRA , UCSRA_TXC) != 1);
	SET_BIT(UCSRA , UCSRA_TXC);
	CLR_BIT(UCSRB , UCSRB_UDRIE);
}