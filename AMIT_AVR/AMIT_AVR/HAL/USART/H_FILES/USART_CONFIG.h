#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*************USART UCSRA*****************/
#define usart_UCSRA *((volatile uint8_t *)0x2B)
#define usart_UCSRA_RXC 7
#define usart_UCSRA_TXC 6
#define usart_UCSRA_UDRE 5
#define usart_UCSRA_FE 4
#define usart_UCSRA_DOR 3
#define usart_UCSRA_PE 2
#define usart_UCSRA_U2X 1
#define usart_UCSRA_MPCM 0

/*************USART UCSRB****************/
#define usart_UCSRB *((volatile uint8_t *)0x2A)
#define usart_UCSRB_RXCIE 7
#define usart_UCSRB_TXCIE 6
#define usart_UCSRB_UDRIE 5
#define usart_UCSRB_RXEN 4
#define usart_UCSRB_TXEN 3
#define usart_UCSRB_UCSZ2 2
#define usart_UCSRB_RXB8 1
#define usart_UCSRB_TXB8 0

/************USART UCSRC and UBRRH******/
#define usart_UCSRC_UBRRH *((volatile uint8_t *)0x40)
#define usart_UCSRC_URSEL 7
#define usart_UCSRC_UMSEL 6
#define usart_UCSRC_UPM1 5
#define usart_UCSRC_UPM0 4
#define usart_UCSRC_USBS 3
#define usart_UCSRC_UCSZ1 2
#define usart_UCSRC_UCSZ0 1
#define usart_UCSRC_UCPOL 0



#define usart_UBRRL *((volatile uint8_t *)0x29)
#define usart_UDR *((volatile uint8_t *)0x2C)




#endif /* USART_CONFIG_H_ */