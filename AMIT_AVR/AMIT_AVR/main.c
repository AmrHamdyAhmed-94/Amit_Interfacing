 #include "LIBRARIES_H/STD_TYPES.h"
 #include "LIBRARIES_H/BIT_MATH.h"
 
 #include "MCAL/DIO/H_FILES/AVR_DIO_REG.h"
 #include "MCAL/DIO/H_FILES/DIO.h"

 #include "HAL/LEDS/H_FILES/LEDS_CONFIG.h"
 #include "HAL/LEDS/H_FILES/LEDS.h"
 
 #include "HAL/SPI/H_FILES/SPI_REG.h"
 #include "HAL/SPI/H_FILES/SPI_CONFIG.h"
 #include "HAL/SPI/H_FILES/SPI.h"

 #include "HAL/USART/H_FILES/USART_REG.h"
 #include "HAL/USART/H_FILES/USART_CONFIG.h"
 #include "HAL/USART/H_FILES/USART.h"

 #include "main.h"
 
int main(void){
	#if (KIT_TYPE == 0)
		master_Main();
	#elif (KIT_TYPE == 1)
		slave_Main();
	#endif
	return 0;
}

void master_Main(){
	str_UartConfg_t obj = {9600,UART_8_BIT_MODE,UART_POLLING};
	MCAL_SPI_MasterInit(SPI_MASTER_FREQUENCY_64);
	MCAL_UART_init(&obj);
	HAL_LED_GENERIC_INITIALIZATION(LED_0);
	HAL_LED_GENERIC_INITIALIZATION(LED_1);
	uint8_t arr[] = "Please Enter a Button:";
	uint8_t i = 0 , chr, recieve;
	while (arr[i] != '/0'){
		MCAL_UART_sendByteBusyWait(arr[i++]);
	}
	while(1){
		MCAL_UART_recieveByteBusyWait(&chr);
		switch(chr){
			case '0' :
				HAL_LED_GENERIC_TURN_ON(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_OFF(LED_1);
				break;
			case '1' :
				HAL_LED_GENERIC_TURN_OFF(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_ON(LED_1);
				break;
			case '3' :
				HAL_LED_GENERIC_TURN_ON(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_ON(LED_1);
				break;
			case '4' :
				HAL_LED_GENERIC_TURN_OFF(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_OFF(LED_1);
			break;
			default :
				MCAL_SPI_Master_DataBusyWait(chr,&recieve);
			break;
		}
	}
}

void slave_Main(){
	MCAL_SPI_SlaveInit();
	HAL_LED_GENERIC_INITIALIZATION(LED_0);
	HAL_LED_GENERIC_INITIALIZATION(LED_1);
	uint8_t recieve_char , send = NULL;
	while(1){
		MCAL_SPI_Slave_DataBusyWait(send,&recieve_char);
		switch(recieve_char){
			case '0' :
				HAL_LED_GENERIC_TURN_ON(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_OFF(LED_1);
				break;
			case '1' :
				HAL_LED_GENERIC_TURN_OFF(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_ON(LED_1);
				break;
			case '3' :
				HAL_LED_GENERIC_TURN_ON(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_ON(LED_1);
			break;
			case '4' :
				HAL_LED_GENERIC_TURN_OFF(LED_0);//to check that the program went through this condition
				HAL_LED_GENERIC_TURN_OFF(LED_1);
			break;
		}
	}
}