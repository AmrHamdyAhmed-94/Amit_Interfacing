/*
 * SPI.c
 *
 * Created: 2/4/2021 12:28:05 AM
 *  Author: Amrha
 */ 

 #ifndef SPI_H_
 #define SPI_H_

 /******SPI type******/
 #define SPI_MASTER 1
 #define SPI_SLAVE 0

 /******MSB or LSB*******/
 #define SPI_MSB 0
 #define SPI_LSB 1

 /*******CLK Polarity******/
 #define CLK_IDLE_LOW 0
 #define CLK_IDLE_HIGH 1

 /*******CLK Phase*********/
 #define CLK_SAMPLE_LEADING 0
 #define CLK_SAMPLE_TRAILING 1

 /*******SPI Clock*******/
 #define SPI_CLK_4 0
 #define SPI_CLK_16 1
 #define SPI_CLK_64 2
 #define SPI_CLK_128 3
 #define SPI_CLK_Double_2 4
 #define SPI_CLK_Double_8 5
 #define SPI_CLK_Double_32 6
 #define SPI_CLK_Double_64 7

 typedef struct
 {
	 uint8_t spi_type;
	 uint8_t spi_data_direction;
	 uint8_t clk_polarity;
	 uint8_t clk_phase;
	 uint8_t spi_clk;
 }ptr_spi;
 void MCAL_SPI_voidInit(ptr_spi *ptr_info);
 void MCAL_SPI_MasterTransData(uint8_t u8Data);
 uint8_t MCAL_SPI_u8SlaveReceive();



 #endif /* SPI_H_ */