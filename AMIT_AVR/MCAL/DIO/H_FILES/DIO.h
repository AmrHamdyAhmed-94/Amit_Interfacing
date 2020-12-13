#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_LOW 0
#define DIO_HIGH 1

#define DIO_PORT_INPUT 0
#define DIO_PORT_OUTPUT 255

#define DIO_INPUT_FLOATING 0
#define DIO_INPUT_PULL_UP 1

uint8_t MCAL_DIO_u8SetPinDir(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Dir );

uint8_t MCAL_DIO_u8SetPortDir(uint8_t Copy_u8PortNo ,uint8_t Copy_u8Dir );

uint8_t MCAL_DIO_u8SetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Value );

uint8_t MCAL_DIO_u8SetPortValue(uint8_t Copy_u8PortNo ,uint8_t Copy_u8Value );

uint8_t MCAL_DIO_u8GetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t *ptr_u8Value );

uint8_t MCAL_DIO_u8GetPortValue(uint8_t Copy_u8PortNo ,uint8_t *ptr_u8Value );

uint8_t MCAL_DIO_u8SetPinInputType(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t Copy_u8Value );

uint8_t MCAL_DIO_u8SetPortInputType(uint8_t Copy_u8PortNo  ,uint8_t Copy_u8Value );

#endif /* DIO_INTERFACE_H_ */
