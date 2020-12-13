#ifndef LCD_PRE_CONFIG_H_
#define LCD_PRE_CONFIG_H_

#define LCD_MODE 4

#define LCD_DATA_PORT_REG PORTA
#define LCD_DATA_PORT DIO_PORTA
#define LCD_RS_PIN DIO_PORTB , DIO_PIN_1
#define LCD_RW_PIN DIO_PORTB , DIO_PIN_2
#define LCD_EN_PIN DIO_PORTB , DIO_PIN_3

/*0 0 1 (FS : 1 8 bit , 0 4 bit) (N : 0 1_Line , 1 2_Lines ) (Font: 0 5x8 , 1 5x11)*/
#define LCD_INITIALIZE_4BIT_COMMAND 0b00101100
#define LCD_INITIALIZE_8BIT_COMMAND 0b00111100

/*Related to 4bit to make sure it's 4bit*/
#define LCD_INITIALIZE_4BIT_33 0x33
#define LCD_INITIALIZE_4BIT_32 0x32

/*0 0 0 0 1 (Display 0 off , 1 on ) (Cursor 0 off 1 on)(Cursor Blink 0 off 1 on)*/
#define LCD_INITIALIZE_COMMAND 0b00001111

/*Clear Command*/
#define LCD_CLEAR_COMMAND 0b00000001

#endif /* LCD_PRE_CONFIG_H_ */