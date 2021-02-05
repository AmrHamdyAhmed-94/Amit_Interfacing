/*
 * SPI.c
 *
 * Created: 2/4/2021 12:28:05 AM
 *  Author: Amrha
 */ 

 #ifndef SPI_H_
 #define SPI_H_

#define SPI_SS_PIN   	DIO_PORTB , DIO_PIN_4
#define SPI_MOSI_PIN   	DIO_PORTB , DIO_PIN_5
#define SPI_MISO_PIN   	DIO_PORTB , DIO_PIN_6
#define SPI_SCK_PIN   	DIO_PORTB , DIO_PIN_7


#define MSB_FIRST            0U
#define LSB_FIRST            1U

#define CLOCK_IDLE_HIGH      1U
#define CLOCK_IDLE_LOW       0U

#define SAMPLE_IN_LEADING    0U
#define SETUP_IN_LEADING     1U


#define SPI_MASTER_FREQUENCY_4      0U
#define SPI_MASTER_FREQUENCY_16     1U
#define SPI_MASTER_FREQUENCY_64     2U
#define SPI_MASTER_FREQUENCY_128    3U
#define SPI_MASTER_DOUBLE_FREQUENCY_2      4U
#define SPI_MASTER_DOUBLE_FREQUENCY_8      5U
#define SPI_MASTER_DOUBLE_FREQUENCY_32     6U
#define SPI_MASTER_DOUBLE_FREQUENCY_64     7U
#define SPI_SLAVE_FREQUENCY			8U

#define SPI_SLAVE			 0U
#define SPI_MASTER			 1U

#define SPI_POLLING          0U
#define SPI_INTERRUPT        1U

typedef struct
{
	uint8_t MasterMode ;
	uint8_t ClockFrequency ;
	uint8_t FlagMode ;

}St_SPICfg_t;


/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of SPI Module
* Input     : Clock frequency
* Output    : Error Status
* */
extern uint8_t MCAL_SPI_MasterInit(uint8_t ClockFrequency);

/*Description: Initialization of SPI Module Slave
* Input     : void
* Output    : Error Status
* */
extern uint8_t MCAL_SPI_SlaveInit(void);


/*************************************************************
*Description: Send and Receive Data of SPI Module Master
* Input     : Copy_u8DataSend Data to send , pointer to Data  received
* Output    : void
* */
extern void MCAL_SPI_Master_DataBusyWait(uint8_t Copy_u8DataSend , uint8_t *Ptr_DataReceive);

/*************************************************************
*Description: Send and Receive Data of SPI Module Slave
* Input     : Copy_u8DataSend Data to send , pointer to Data  received
* Output    : void
* */
extern void MCAL_SPI_Slave_DataBusyWait(uint8_t Copy_u8DataSend , uint8_t *Ptr_DataReceive);

/*************************************************************
*Description: MCAL_SPI_Master_DataCallBack
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
extern void MCAL_SPI_Master_DataCallBack(uint8_t Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t));

/*************************************************************
*Description: MCAL_SPI_Slave_DataCallBack
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
extern void MCAL_SPI_Slave_DataCallBack(uint8_t Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t));

/*************************************************************
*Description: MCAL_SPI_MasterString
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
extern void MCAL_SPI_MasterString(uint8_t *Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t));

/*************************************************************
*Description: MCAL_SPI_SlaveString
* Input     : Copy_u8DataSend Data to send , pointer to function takes Data  received
* Output    : void
* */
extern void MCAL_SPI_SlaveString(uint8_t *Copy_u8DataSend , void (*Ptr_DataReceive)(uint8_t));

 #endif /* SPI_H_ */