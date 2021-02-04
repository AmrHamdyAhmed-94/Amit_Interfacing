 #include "MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "LIBRARIES_H/STD_TYPES.h"
 #include "LIBRARIES_H/BIT_MATH.h"
 
 #include "MCAL/DIO/H_FILES/DIO.h"

 #include "HAL/LEDS/H_FILES/LEDS_CONFIG.h"
 #include "HAL/LEDS/H_FILES/LEDS.h"
 
 #include "HAL/SPI/H_FILES/SPI_CONFIG.h"
 #include "HAL/SPI/H_FILES/SPI.h"

 #include "HAL/USART/H_FILES/USART_CONFIG.h"
 #include "HAL/USART/H_FILES/USART.h"

 #include "main.h"
 
 #include <util/delay.h>


int main(void){
	#if (KIT_TYPE == 0)
		master_Main();
	#elif (KIT_TYPE == 1)
		slave_Main();
	#endif
	return 0;
}

int master_Main(){
	ptr_spi obj = {SPI_MASTER,SPI_MSB,CLK_IDLE_LOW,CLK_SAMPLE_LEADING,SPI_CLK_64};
	MCAL_SPI_voidInit(&obj);
	MCAL_USART_voidInit(9600);
	HAL_LED_GENERIC_INITIALIZATION(LED_0);
	HAL_LED_GENERIC_INITIALIZATION(LED_1);
	uint8_t arr[] = "Please Enter a Button:";
	MCAL_USART_voidTransmitString(arr);
	while(1){
		uint8_t chr = MCAL_USART_u8Receive();
		switch(chr){
			case '1':
				HAL_LED_GENERIC_TURN_ON(LED_0);
				MCAL_SPI_MasterTransData(chr);
				break;
			case '2' :
				HAL_LED_GENERIC_TURN_ON(LED_1);
				MCAL_SPI_MasterTransData(chr);
				break;
			case '3' :
				HAL_LED_GENERIC_TURN_OFF(LED_0);
				MCAL_SPI_MasterTransData(chr);
				break;
			case '4' :
				HAL_LED_GENERIC_TURN_OFF(LED_1);
				MCAL_SPI_MasterTransData(chr);
				break;
		}
	}
	return 0;
}

int slave_Main(){
	uint8_t recieved_Character , led_State;
	HAL_LED_GENERIC_INITIALIZATION(LED_0);
	HAL_LED_GENERIC_INITIALIZATION(LED_1);
	ptr_spi obj = {SPI_SLAVE,SPI_MSB,CLK_IDLE_LOW,CLK_SAMPLE_LEADING};
	MCAL_SPI_voidInit(&obj);
	while (1)
	{
		recieved_Character = MCAL_SPI_u8SlaveReceive();
		if (recieved_Character == '1')
			HAL_LED_GENERIC_TOGGLE(LED_0,&led_State);
		else if (recieved_Character == '2')
			HAL_LED_GENERIC_TOGGLE(LED_1,&led_State);
	}
	return  0;
}

