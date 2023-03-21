/*
 * GPIO.c
 *
 *  Created on: Jan 3, 2023
 *      Author: Bishoy Refaat
 */

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "GPIO.h"
#include "STM32F103xx.h"
//==========================================================================


//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|



void MCAL_GPIO_INIT_PIN(GPIO_T * GPIOx , GPIO_PinConfig_t * PIN_CONFIG){
	volatile uint8_t PIN_SELECT ;		//Used to catch the position of the pin in configuration register

	PIN_SELECT = (PIN_CONFIG->GPIO_PinNumber > 7 )? 1 : 0;		//If the pin number is more than 7 it returns 1 else 0

	PIN_SELECT = ((PIN_CONFIG->GPIO_PinNumber - 8 * PIN_SELECT) * GPIO_REGISTER_SIZE);    //GPIO_REGISTER_SIZE exists in GENERIC MACROS in GPIO header = 4
																							//The position of the pin in CRH or CRL  -> EX: (12 - 8 * 1 ) * 4 = 16

	volatile uint32_t * REGISTER_SELECT ;		//Used to choose between CRH or CRL
	REGISTER_SELECT = (PIN_CONFIG->GPIO_PinNumber > 7 )? &GPIOx->CRH : &GPIOx->CRL;		//If the pin number is more than 7 it returns CRH else CRL

	//				   (		MASK on the desired pins	   ) | (			Desired configurations shifted by the pin needed			)
	*REGISTER_SELECT = (*REGISTER_SELECT & ~(0xf << PIN_SELECT)) | ((PIN_CONFIG->GPIO_MODE<<2 | PIN_CONFIG->GPIO_FREQ_SPEED) << PIN_SELECT);

	//If the pin is Pull-up input write 1 in the according ODR
	if(PIN_CONFIG->GPIO_MODE == GPIO_MODE_INPUT_PULLUP){
		GPIOx->ODR |= (1 << PIN_CONFIG->GPIO_PinNumber);
	}
	//If the pin is Pull-up input write 0 in the according ODR
	else if(PIN_CONFIG->GPIO_MODE == GPIO_MODE_INPUT_PULLDOWN){
		GPIOx->ODR &= ~(1 << PIN_CONFIG->GPIO_PinNumber);
	}

}



//void MCAL_GPIO_INIT_PORT(GPIO_T * GPIOx ,GPIO_PortConfig_t *PORT_CONFIG){

//}



void MCAL_GPIO_RESET(uint8_t GPIOx_RESET){
	RCC->APB2RSTR |= (1 << GPIOx_RESET);
	RCC->APB2RSTR &= ~(1 << GPIOx_RESET);
}



uint8_t MCAL_GPIO_READ_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER){

	return ((GPIOx->IDR >> PIN_NUMBER ) & 1);
}



uint16_t MCAL_GPIO_READ_PORT(GPIO_T * GPIOx){

	return ((uint16_t)GPIOx->IDR);
}



void MCAL_GPIO_WRITE_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER , uint8_t VAL){
	if(VAL){
		GPIOx->BSRR |= (VAL << PIN_NUMBER);
	}
	else{
		GPIOx->BRR |= ~(VAL << PIN_NUMBER);
	}
}



void MCAL_GPIO_WRITE_PORT(GPIO_T * GPIOx , uint16_t VAL){
	GPIOx->ODR &= 0xFFFF0000;
	GPIOx->ODR |= VAL;
}



void MCAL_GPIO_TOGGLE_PIN(GPIO_T * GPIOx , uint16_t PIN_NUMBER){
	GPIOx->ODR ^= (1 << PIN_NUMBER);
}



uint8_t MCAL_GPIO_LOCK_PIN(GPIO_T * GPIOx , uint16_t PIN_NUMBER){
	/*Bit 16 LCKK[16]: Lock key
	*This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
	*0: Port configuration lock key not active
	*1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	*LOCK key writing sequence:
	*Write 1
	*Write 0
	*Write 1
	*Read 0
	*Read 1 (this read is optional but confirms that the lock is active)
	*Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	*Any error in the lock sequence will abort the lock.
	*Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	*These bits are read write but can only be written when the LCKK bit is 0.
	*0: Port configuration not locked
	*1: Port configuration locked.
	**/
	volatile uint16_t tmp;
	GPIOx->LCKR |= 1 << PIN_NUMBER | 1 << 16;
	GPIOx->LCKR &= ~(1 << 16);
	GPIOx->LCKR |= 1 << 16;
	tmp = GPIOx->LCKR;
	if( GPIOx->LCKR & 1<<16){
		return 1;
	}
	else {
		return 0;
	}
}
