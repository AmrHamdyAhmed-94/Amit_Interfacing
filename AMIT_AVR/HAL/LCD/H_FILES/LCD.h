#ifndef LCD_H_
#define LCD_H_

extern void HAL_LCD_voidInitialize(void);
extern void HAL_LCD_voidClearLCD(void);
extern void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character);
extern void HAL_LCD_voidWriteString(uint8_t *Ptr_u8String);
extern void HAL_LCD_voidMoveCursor(uint8_t , uint8_t);

#endif /* LCD_H_ */