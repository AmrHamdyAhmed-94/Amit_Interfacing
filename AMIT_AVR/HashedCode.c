
/*
 * HashedCode.S
 *
 * Created: 12/12/2020 8:31:59 AM
 *  Author: Amrha
 */ 
 #if 0
int main_NOT(void)
{
	initialize_S_SEGMENT();
	
	initialize_LED_0();
	initialize_LED_1();
	initialize_LED_2();

	initialize_BUTTON_0();
	initialize_BUTTON_1();
	initialize_BUTTON_2();

    uint8_t BUTTON_0_VALUE , BUTTON_1_VALUE , BUTTON_2_VALUE , stateAfterToggle = DIO_LOW , loobVariable, loobVariable2;

    while(1){
		BUTTON_0_VALUE = get_BUTTON_0_VALUE();
		if(BUTTON_0_VALUE == DIO_HIGH){
			toggle_LED_0(&stateAfterToggle);
			while(BUTTON_0_VALUE == DIO_HIGH){
				BUTTON_0_VALUE = get_BUTTON_0_VALUE();
			}
		}
		
		BUTTON_1_VALUE = get_BUTTON_1_VALUE();
		if(BUTTON_1_VALUE == DIO_HIGH){
			turn_ON_LED_1();
			while(BUTTON_1_VALUE == DIO_HIGH){
				BUTTON_1_VALUE = get_BUTTON_1_VALUE();
			}
			turn_OFF_LED_1();
		}
		
		BUTTON_2_VALUE = get_BUTTON_2_VALUE();
		if(BUTTON_2_VALUE == DIO_HIGH){
			turn_ON_BUZZER();
			while(BUTTON_2_VALUE == DIO_HIGH){
				BUTTON_2_VALUE = get_BUTTON_2_VALUE();
			}
			turn_OFF_BUZZER();
		}
		
		for(loobVariable = 0 ; loobVariable < 10 ; ++loobVariable){
			turn_ON_S_SEGMENT_1();
			show_ON_S_SEGMENT(1);
			turn_OFF_S_SEGMENT_1();
			_delay_ms(1);
			for(loobVariable2 = 0 ; loobVariable2 < 10 ; ++loobVariable2){
				turn_ON_S_SEGMENT_2();
				show_ON_S_SEGMENT(loobVariable2);
				_delay_ms(1);
			}
			//_delay_ms(5000);
		}

/*
		turn_ON_S_SEGMENT_1();
		show_ON_S_SEGMENT(1);
/ *
		turn_OFF_S_SEGMENT_1();
		_delay_us(100);
		turn_ON_S_SEGMENT_2();
		show_ON_S_SEGMENT(5);
		turn_OFF_S_SEGMENT_2();* /
		_delay_us(100);*/
	}
	return 0;
}

int main(void){
	initialize_S_SEGMENT();
	
	initialize_LED_0();
	initialize_LED_1();
	initialize_LED_2();

	initialize_BUTTON_0();
	initialize_BUTTON_1();
	initialize_BUTTON_2();

	uint8_t BUTTON_0_VALUE , BUTTON_1_VALUE , BUTTON_2_VALUE , stateAfterToggle = DIO_LOW , count=0;

	while(1){
		turn_ON_S_SEGMENT_1();
		show_ON_S_SEGMENT(count);

		BUTTON_0_VALUE = get_BUTTON_0_VALUE();
		if(BUTTON_0_VALUE == DIO_HIGH){
			count = (count == 9) ? 0 : ++count;
			while(BUTTON_0_VALUE == DIO_HIGH){
				BUTTON_0_VALUE = get_BUTTON_0_VALUE();
			}
		}

		BUTTON_1_VALUE = get_BUTTON_1_VALUE();
		if(BUTTON_1_VALUE == DIO_HIGH){
			count = (count == 0) ? 0 : --count;
			while(BUTTON_1_VALUE == DIO_HIGH){
				BUTTON_1_VALUE = get_BUTTON_1_VALUE();
			}
		}
	}

}

int main(void){
	uint8_t value = 1;
	initialize_S_SEGMENT();
	HAL_KEYPAD_voidInitialize();
	while(1){
		turn_ON_S_SEGMENT_2();
		turn_ON_S_SEGMENT_1();
		HAL_KEYPAD_voidGetKeyPressedOnce(&value);
		show_ON_S_SEGMENT(value+'0');
	}

}

int main(void){
	uint8_t value = 1;
	//HAL_KEYPAD_voidInitialize();
	HAL_LCD_voidInitialize();
	HAL_LCD_voidWriteCharacter('A');
	while(1){
		//HAL_KEYPAD_voidGetKeyPressedOnce(&value);
		
	}

}

#endif