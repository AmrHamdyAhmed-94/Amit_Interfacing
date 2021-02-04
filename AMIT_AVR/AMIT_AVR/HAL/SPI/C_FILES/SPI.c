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

#include "../H_FILES/SPI_CONFIG.h"
#include "../H_FILES/SPI.h"
#include <util/delay.h>

void MCAL_SPI_voidInit(ptr_spi *ptr_info){
	if ((ptr_info->spi_type)==SPI_MASTER){
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_4,DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_5,DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_6,DIO_INPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_7,DIO_OUTPUT);
		ASSIGN_BIT(SPCR,SPCR_MSTR,ptr_info->spi_type);
		if (((ptr_info->spi_data_direction)==SPI_MSB)||((ptr_info->spi_data_direction)==SPI_LSB))
			ASSIGN_BIT(SPCR,SPCR_DORD,ptr_info->spi_data_direction);
		if (((ptr_info->clk_polarity)==CLK_IDLE_LOW) || ((ptr_info->clk_polarity)==CLK_IDLE_HIGH))
			ASSIGN_BIT(SPCR,SPCR_CPOL,ptr_info->clk_polarity);
		if (((ptr_info->clk_phase)==CLK_SAMPLE_LEADING) || ((ptr_info->clk_phase)==CLK_SAMPLE_TRAILING))
			ASSIGN_BIT(SPCR,SPCR_CPHA,ptr_info->clk_phase);
		if (((ptr_info->spi_clk)>=SPI_CLK_4)&&((ptr_info->spi_clk)<=SPI_CLK_Double_64))
			SPCR |= (SPCR & 0xFC) | ((ptr_info->spi_clk) & 0x03);
		if ((ptr_info->spi_clk)>=SPI_CLK_Double_2)
			SET_BIT(SPSR,SPSR_SPI2X);

		SET_BIT(SPCR,SPCR_SPE);
	}else if ((ptr_info->spi_type)==SPI_SLAVE){
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_4,DIO_INPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_5,DIO_INPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_6,DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTB,DIO_PIN_7,DIO_INPUT);
		
		if (((ptr_info->spi_data_direction)==SPI_MSB)||((ptr_info->spi_data_direction)==SPI_LSB))
			ASSIGN_BIT(SPCR,SPCR_DORD,ptr_info->spi_data_direction);
		if (((ptr_info->clk_phase)==CLK_SAMPLE_LEADING) || ((ptr_info->clk_phase)==CLK_SAMPLE_TRAILING))
			ASSIGN_BIT(SPCR,SPCR_CPHA,ptr_info->clk_phase);
		
		SET_BIT(SPCR,SPCR_SPE);
	}
}

void MCAL_SPI_MasterTransData(uint8_t u8Data){
	SPDR = u8Data;
	MCAL_DIO_u8SetPinValue(DIO_PORTB,DIO_PIN_4,DIO_LOW);	
	SET_BIT(SPCR,SPCR_SPE);
	while(GET_BIT(SPSR,SPSR_SPIF)!=1);
	CLR_BIT(SPCR,SPCR_SPE);
	MCAL_DIO_u8SetPinValue(DIO_PORTB,DIO_PIN_4,DIO_HIGH);
}

uint8_t MCAL_SPI_u8SlaveReceive(){
	//SPDR = 0 ;
	//	set_bit(SPCR,SPCR_SPE);
	while(GET_BIT(SPSR , SPSR_SPIF) != 1);
	//	clr_bit(SPCR,SPCR_SPE);
	return SPDR;
}