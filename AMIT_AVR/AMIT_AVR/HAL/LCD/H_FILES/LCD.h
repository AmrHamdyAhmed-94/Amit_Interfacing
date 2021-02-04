#ifndef LCD_H_
#define LCD_H_

#define LCD_4_BIT_MODE  4U	/*4 bit Mode*/
#define LCD_8_BIT_MODE  8U  /*8 bit Mode*/

/*_____LCD LINES___________________________*/
#define LCD_LINES_1  	0U   /*1 Line */
#define LCD_LINES_2  	1U   /*2 Lines*/

/*_____LCD FONT___________________________*/
#define LCD_FONT_5_8  	0U   /*5 * 8 Font*/
#define LCD_FONT_5_11  	1U   /*5 * 11 Font*/

/*_____LCD Diplay___________________________*/
#define LCD_DISPLAY_OFF  	0U   /*Display Off*/
#define LCD_DISPLAY_ON  	1U   /*Display On*/

/*_____LCD Cursor___________________________*/
#define LCD_CURSOR_OFF  	0U   /*CURSOR Disable*/
#define LCD_CURSOR_ON	  	1U   /*CURSOR Enable*/

/*_____LCD Cursor blink___________________________*/
#define LCD_CURSOR_BLINK_OFF  		0U   /*CURSOR Blink Disable*/
#define LCD_CURSOR_BLINK_ON		  	1U   /*CURSOR Blink Enable*/



extern void HAL_LCD_voidInitialize(void);
extern void HAL_LCD_voidDisplaySetup(uint8_t Copy_u8DisplayValue);
extern void HAL_LCD_voidMoveCursor(uint8_t , uint8_t);

extern void HAL_LCD_voidClearLCD(void);
extern void HAL_LCD_voidClearPart(uint8_t Copy_RowNo , uint8_t Copy_u8Start , uint8_t Copy_u8End);

extern void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character);
extern void HAL_LCD_voidWriteString(uint8_t *Ptr_u8String);
extern void HAL_LCD_voidWriteNumber(uint32_t Copy_u32Number);
extern void HAL_LCD_voidWriteSpecialChar(uint8_t *ptr_Shapes , uint8_t Copy_RowNo , uint8_t Copy_ColNo);


extern void HAL_LCD_voidMoveCursor(uint8_t , uint8_t);


#endif /* LCD_H_ */