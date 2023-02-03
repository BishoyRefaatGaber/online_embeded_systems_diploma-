/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include "STM32F103xx.h"
#include "GPIO.h"
#include "LCD_DRIVER.h"
#include "KEYPAD_DRIVER.h"
#include "EXTI.h"
#include "RCC.h"



GPIO_T *GPIO_A = GPIOA;
GPIO_T *GPIO_B = GPIOB;


//LCD DISPLAY PINS
GPIO_PinConfig_t PINA_0 ;
GPIO_PinConfig_t PINA_1 ;
GPIO_PinConfig_t PINA_2 ;
GPIO_PinConfig_t PINA_3 ;
GPIO_PinConfig_t PINA_4 ;
GPIO_PinConfig_t PINA_5 ;
GPIO_PinConfig_t PINA_6 ;
GPIO_PinConfig_t PINA_7 ;

//LCD CONTROL PINS
GPIO_PinConfig_t PINA_8 ;
GPIO_PinConfig_t PINA_9 ;
GPIO_PinConfig_t PINA_10 ;



//KEPAD PINS
GPIO_PinConfig_t PINB_3 ;
GPIO_PinConfig_t PINB_4 ;
GPIO_PinConfig_t PINB_5 ;
GPIO_PinConfig_t PINB_6 ;
GPIO_PinConfig_t PINB_7 ;
GPIO_PinConfig_t PINB_8 ;
GPIO_PinConfig_t PINB_9 ;
GPIO_PinConfig_t PINB_10 ;



//GPIO_PinConfig_t PINA_13 ;


void init(){
	//ُEnable Clock
	RCC_GPIOA_CLK_EN() ;	//enable GPIOA CLOCK FOR LCD
	RCC_GPIOB_CLK_EN() ;	//enable GPIOB CLOCK FOR INTERRUPT INPUT
	RCC_AFIO_CLK_EN();		//enable AFIO CLOCK FOR INTERRUPT


	//=========================
	//LCD PINS
	//=========================

	// D0
	PINA_0.GPIO_PinNumber = GPIO_PIN_0;
	PINA_0.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_0.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_0);

	//D1
	PINA_1.GPIO_PinNumber = GPIO_PIN_1;
	PINA_1.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_1.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_1);

	//D2
	PINA_2.GPIO_PinNumber = GPIO_PIN_2;
	PINA_2.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_2.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_2);

	//D3
	PINA_3.GPIO_PinNumber = GPIO_PIN_3;
	PINA_3.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_3.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_3);

	//D4
	PINA_4.GPIO_PinNumber = GPIO_PIN_4;
	PINA_4.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_4.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_4);

	//D5
	PINA_5.GPIO_PinNumber = GPIO_PIN_5;
	PINA_5.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_5.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_5);

	//D6
	PINA_6.GPIO_PinNumber = GPIO_PIN_6;
	PINA_6.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_6.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_6);

	//D7
	PINA_7.GPIO_PinNumber = GPIO_PIN_7;
	PINA_7.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_7.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_7);

	//RS
	PINA_8.GPIO_PinNumber = GPIO_PIN_8;
	PINA_8.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_8.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_8);

	//WR
	PINA_9.GPIO_PinNumber = GPIO_PIN_9;
	PINA_9.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_9.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_9);

	//EN
	PINA_10.GPIO_PinNumber = GPIO_PIN_10;
	PINA_10.GPIO_MODE = GPIO_MODE_OUTPUT_GENERAL_PUSHPULL;
	PINA_10.GPIO_OUTPUT_SPEED = GPIO_FREQ_10MHZ;
	MCAL_GPIO_INIT_PIN(GPIO_A , &PINA_10);
}



void wait_ms(uint32_t time){
	uint32_t i=0,j=0;
	for(; i < time ; i++){
		for (; j < 255 ; j++);
	}
}

void EXTI9_CALLBACK(void){
	LCD_WRITE_STRING("IRQ EXTI9 HAS  HAPPENDE _|-");
	wait_ms(1000000);
	LCD_WRITE_COMMAND(LCD_Clear_Display);

}
int main(void)
{
	init();
	LCD_INIT();
	EXTI_CONFIG_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.TRIGGER_CASE = EXTI_CASE_RISING;
	EXTI_CFG.P_IRQ_CALL_BACK = EXTI9_CALLBACK;
	EXTI_CFG.IRQ_EN = IRQ_ENABLE;

	MCAL_EXTI_INIT(&EXTI_CFG);


	while(1){

	}
	return 0;

}

