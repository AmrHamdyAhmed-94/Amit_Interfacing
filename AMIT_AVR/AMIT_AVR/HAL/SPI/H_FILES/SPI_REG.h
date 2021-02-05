/*
 * IncFile1.h
 *
 * Created: 2/4/2021 9:45:45 PM
 *  Author: Amrha
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPI_SPCR *((volatile uint8_t*)0x2D)
#define SPI_SPSR *((volatile uint8_t*)0x2E)
#define SPI_SPDR *((volatile uint8_t*)0x2F)
#define SREG   *((volatile uint8_t*)0x5F)

#define SPI_SPCR_SPIE  7
#define SPI_SPCR_SPE   6
#define SPI_SPCR_DORD  5
#define SPI_SPCR_MSTR  4
#define SPI_SPCR_CPOL  3
#define SPI_SPCR_CPHA  2
#define SPI_SPCR_SPR1  1
#define SPI_SPCR_SPR0  0


#define SPI_SPSR_SPIF  7
#define SPI_SPSR_WCOL  6
#define SPI_SPSR_SPI2X 0

#define GLOBAL_INTERRUPT_BIT  7

#endif /* SPI_REG_H_ */