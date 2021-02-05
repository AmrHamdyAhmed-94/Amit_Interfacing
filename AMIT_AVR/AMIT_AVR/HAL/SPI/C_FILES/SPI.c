/*
 * SPI.c
 *
 * Created: 2/4/2021 12:28:05 AM
 *  Author: Amrha
 */ 

#include "../../../LIBRARIES_H/STD_TYPES.h"
#include "../../../LIBRARIES_H/BIT_MATH.h"

#include "../../../MCAL/DIO/H_FILES/AVR_DIO_REG.h"
#include "../../../MCAL/DIO/H_FILES/DIO.h"

#include "../H_FILES/SPI_REG.h"
#include "../H_FILES/SPI_CONFIG.h"
#include "../H_FILES/SPI.h"
#include <util/delay.h>

#define NO_OPERATION  10


uint8_t g_MasterMode = NO_OPERATION  ;

static void (*Call_Back_Master)(uint8_t) ;
static void (*Call_Back_Slave)(uint8_t) ;

void __vector_12(void)__attribute((signal,used));

/*- FUNCTION DEFINITION ----------------------------------*/

/*************************************************************
*Description: Initialization of SPI Module
* Input     : Clock frequency
* Output    : Error Status
* */
uint8_t MCAL_SPI_MasterInit(uint8_t ClockFrequency){
	uint8_t Local_u8Error = NO_ERROR ;
	if(SPI_DATA_ORDER == MSB_FIRST || SPI_DATA_ORDER == LSB_FIRST){
		ASSIGN_BIT(SPI_SPCR , SPI_SPCR_DORD , SPI_DATA_ORDER);  /*Set Data Order*/
		if(SPI_CLOCK_POLARITY == CLOCK_IDLE_HIGH || SPI_CLOCK_POLARITY == CLOCK_IDLE_LOW){
			ASSIGN_BIT(SPI_SPCR , SPI_SPCR_CPOL , SPI_CLOCK_POLARITY) ;
			if(SPI_CLOCK_PHASE == SETUP_IN_LEADING || SPI_CLOCK_PHASE == SAMPLE_IN_LEADING)	{
				ASSIGN_BIT(SPI_SPCR , SPI_SPCR_CPHA , SPI_CLOCK_PHASE) ;
				MCAL_DIO_u8SetPinDir(SPI_MOSI_PIN , DIO_OUTPUT);
				MCAL_DIO_u8SetPinDir(SPI_MISO_PIN , DIO_INPUT);
				MCAL_DIO_u8SetPinDir(SPI_SCK_PIN , DIO_OUTPUT);
				MCAL_DIO_u8SetPinDir(SPI_SS_PIN , DIO_OUTPUT);
				MCAL_DIO_u8SetPinValue(SPI_SCK_PIN , DIO_HIGH);
				SET_BIT(SPI_SPCR , SPI_SPCR_MSTR);
				CLR_BIT(SPI_SPCR , SPI_SPCR_SPR0);
				CLR_BIT(SPI_SPCR , SPI_SPCR_SPR1);
				CLR_BIT(SPI_SPSR , SPI_SPSR_SPI2X);
				if(ClockFrequency >= SPI_MASTER_FREQUENCY_4 && ClockFrequency <= SPI_MASTER_FREQUENCY_64){
					SPI_SPCR |= (SPI_SPCR & 0xFC) | (ClockFrequency & 0x03);
					if(ClockFrequency >= SPI_MASTER_DOUBLE_FREQUENCY_2)
						SET_BIT(SPI_SPSR , SPI_SPSR_SPI2X);

					SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
					Call_Back_Master = NULL_POINTER ;
				}else{
					Local_u8Error = ERROR ;
				}

			}else{
				Local_u8Error = ERROR;
			}
		}else{
			Local_u8Error = ERROR ;
		}
	}else{
		Local_u8Error = ERROR ;
	}
	return Local_u8Error ;
}

/*Description: Initialization of SPI Module Slave
* Input     : void
* Output    : Error Status
* */
uint8_t MCAL_SPI_SlaveInit(void){
	uint8_t Local_u8Error = NO_ERROR ;
	if(SPI_DATA_ORDER == MSB_FIRST || SPI_DATA_ORDER == LSB_FIRST){
		ASSIGN_BIT(SPI_SPCR , SPI_SPCR_DORD , SPI_DATA_ORDER);  /*Set Data Order*/
		if(SPI_CLOCK_POLARITY == CLOCK_IDLE_HIGH || SPI_CLOCK_POLARITY == CLOCK_IDLE_LOW){
			ASSIGN_BIT(SPI_SPCR , SPI_SPCR_CPOL , SPI_CLOCK_POLARITY) ;
			if(SPI_CLOCK_PHASE == SETUP_IN_LEADING || SPI_CLOCK_PHASE == SAMPLE_IN_LEADING){
				ASSIGN_BIT(SPI_SPCR , SPI_SPCR_CPHA , SPI_CLOCK_PHASE) ;
				MCAL_DIO_u8SetPinDir(SPI_MOSI_PIN , DIO_INPUT);
				MCAL_DIO_u8SetPinDir(SPI_MISO_PIN , DIO_OUTPUT);
				MCAL_DIO_u8SetPinDir(SPI_SCK_PIN , DIO_INPUT);
				MCAL_DIO_u8SetPinDir(SPI_SS_PIN , DIO_INPUT);
				CLR_BIT(SPI_SPCR , SPI_SPCR_MSTR);
				SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
				Call_Back_Slave = NULL_POINTER ;
			}else{
				Local_u8Error = ERROR ;
			}
		}else{
			Local_u8Error = ERROR;
		}
	}else{
		Local_u8Error = ERROR ;
	}
	return Local_u8Error ;
}


/*************************************************************
*Description: Send and Receive Data of SPI Module Master
* Input     : Copy_u8DataSend Data to send , pointer to Data  received
* Output    : void
* */
void MCAL_SPI_Master_DataBusyWait(uint8_t Copy_u8DataSend , uint8_t *Ptr_DataReceive){
	CLR_BIT(SPI_SPCR , SPI_SPCR_SPIE);
	SPI_SPDR = Copy_u8DataSend ;
	MCAL_DIO_u8SetPinValue(SPI_SS_PIN , DIO_LOW);
	SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
	while(GET_BIT(SPI_SPSR , SPI_SPSR_SPIF) != 1);
	*Ptr_DataReceive = SPI_SPDR ;
	CLR_BIT(SPI_SPCR , SPI_SPCR_SPE);
	MCAL_DIO_u8SetPinValue(SPI_SS_PIN , DIO_HIGH);
}

/*************************************************************
*Description: Send and Receive Data of SPI Module Slave
* Input     : Copy_u8DataSend Data to send , pointer to Data  received
* Output    : void
* */
void MCAL_SPI_Slave_DataBusyWait(uint8_t Copy_u8DataSend , uint8_t *Ptr_DataReceive){
	CLR_BIT(SPI_SPCR , SPI_SPCR_SPIE);
	SPI_SPDR = Copy_u8DataSend ;
	SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
	while(GET_BIT(SPI_SPSR , SPI_SPSR_SPIF) != 1);
	*Ptr_DataReceive = SPI_SPDR ;
	CLR_BIT(SPI_SPCR , SPI_SPCR_SPE);
}

/*************************************************************
*Description: MCAL_SPI_Master_DataCallBack
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
void MCAL_SPI_Master_DataCallBack(uint8_t Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t)){
	if(g_MasterMode == NO_OPERATION){
		SET_BIT(SREG , GLOBAL_INTERRUPT_BIT);
		Call_Back_Master = Ptr_DataReceive ;
		SET_BIT(SPI_SPCR , SPI_SPCR_SPIE);
		SPI_SPDR = Copy_u8DataSend ;
		MCAL_DIO_u8SetPinValue(SPI_SS_PIN , DIO_LOW);
		g_MasterMode = SPI_MASTER ;
		SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
	}
}

/*************************************************************
*Description: MCAL_SPI_Slave_DataCallBack
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
void MCAL_SPI_Slave_DataCallBack(uint8_t Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t)){
	if(g_MasterMode == NO_OPERATION){
		SET_BIT(SREG , GLOBAL_INTERRUPT_BIT);
		Call_Back_Slave =  Ptr_DataReceive ;
		SET_BIT(SPI_SPCR , SPI_SPCR_SPIE);
		g_MasterMode = SPI_SLAVE ;
		SPI_SPDR = Copy_u8DataSend ;
		SET_BIT(SPI_SPCR , SPI_SPCR_SPE);
	}
}

/*************************************************************
*Description: MCAL_SPI_MasterString
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
void MCAL_SPI_MasterString(uint8_t *Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t)){
	uint16_t Local_Counter = 0 ;
	while(Copy_u8DataSend[Local_Counter] != NULL_CHR){
		MCAL_SPI_Master_DataCallBack(Copy_u8DataSend[Local_Counter] , Ptr_DataReceive);
		Local_Counter++ ;
		_delay_ms(1);
	}
}

/*************************************************************
*Description: MCAL_SPI_SlaveString
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
void MCAL_SPI_SlaveString(uint8_t *Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t)){
	uint16_t Local_Counter = 0 ;
	while(Copy_u8DataSend[Local_Counter] != NULL_CHR){
		MCAL_SPI_Slave_DataCallBack(Copy_u8DataSend[Local_Counter] , Ptr_DataReceive);
		Local_Counter++ ;
	}
}

void __vector_12(void){
	if(g_MasterMode == SPI_MASTER){
		if(Call_Back_Master != NULL_POINTER){
			Call_Back_Master(SPI_SPDR);
			CLR_BIT(SPI_SPCR , SPI_SPCR_SPE);
			CLR_BIT(SPI_SPCR , SPI_SPCR_SPIE);
			MCAL_DIO_u8SetPinValue(SPI_SS_PIN , DIO_HIGH);
		}
	}else if(g_MasterMode == SPI_SLAVE){
		CLR_BIT(SPI_SPCR , SPI_SPCR_SPIE);
		Call_Back_Slave(SPI_SPDR);
		CLR_BIT(SPI_SPCR , SPI_SPCR_SPE);
	}
	g_MasterMode = NO_OPERATION;
}