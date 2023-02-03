/*
 * GPIO.c
 *
 *  Created on: Jan 3, 2023
 *      Author: Bishoy Refaat
 */

//---------------------------------
//includes
//---------------------------------

#include "GPIO.h"
#include "STM32F103xx.h"
//==========================================================================


//------------------------------------
//APIs Supported by "MCAL GPIO DRIVER"
//------------------------------------
/**================================================================
* @Fn - MCAL_GPIO_INIT
* @brief - Initialize the portx
* @param[in] - GPIO port
* @param[out] - GPIO pin in the specific port (in the last parameter)
*               takes values @ref GPIO_PinNumber  @ref GPIO_MODE  @ref GPIO_FREQ
*/

void MCAL_GPIO_INIT_PIN(GPIO_T * GPIOx , GPIO_PinConfig_t * PIN_CONFIG){
	volatile uint8_t PIN_SELECT ;
	PIN_SELECT = (PIN_CONFIG->GPIO_PinNumber > 7 )? 1 : 0;
	PIN_SELECT = ((PIN_CONFIG->GPIO_PinNumber - 8 * PIN_SELECT) * GPIO_REGISTER_SIZE);    //GPIO_REGISTER_SIZE exists in GENERIC MACROS in GPIO header
	volatile uint32_t * REGISTER_SELECT ;
	REGISTER_SELECT = (PIN_CONFIG->GPIO_PinNumber > 7 )? &GPIOx->CRH : &GPIOx->CRL;
	*REGISTER_SELECT &= ~(0xf << PIN_SELECT);
	*REGISTER_SELECT |= (PIN_CONFIG->GPIO_MODE<<2 | PIN_CONFIG->GPIO_OUTPUT_SPEED) << PIN_SELECT;
	if(PIN_CONFIG->GPIO_MODE == GPIO_MODE_INPUT_PULLUP){
		GPIOx->ODR |= (1 << PIN_CONFIG->GPIO_PinNumber);
	}
	else if(PIN_CONFIG->GPIO_MODE == GPIO_MODE_INPUT_PULLDOWN){
		GPIOx->ODR &= ~(1 << PIN_CONFIG->GPIO_PinNumber);
	}

}



//void MCAL_GPIO_INIT_PORT(GPIO_T * GPIOx ,GPIO_PortConfig_t *PORT_CONFIG){

//}



/**================================================================
* @Fn - MCAL_GPIO_RESET
* @brief - PORT needed to be reset -> takes values included GENERIC MACROS  GPIO_RESET section in GPIO header
* @param[in] - portx
*/

void MCAL_GPIO_RESET(uint8_t GPIOx_RESET){
	RCC->APB2RSTR |= (1 << GPIOx_RESET);
	RCC->APB2RSTR &= ~(1 << GPIOx_RESET);
}

/**================================================================
* @Fn - MCAL_GPIO_READ_PIN
* @brief - Read a pin from portx
* @param[in] - portx
* @param[out] - Pin number in portx (the first parameter)
* @retval- 8 bit return value read from the pin (the second parameter)
*/


uint8_t MCAL_GPIO_READ_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER){
	uint8_t VAL;
	VAL = ((GPIOx->IDR >> PIN_NUMBER ) & 1) ;
	return VAL;
}

/**================================================================
* @Fn - MCAL_GPIO_READ_PORT
* @brief - Read the whole port
* @param[in] - portx
* @retval- 16 bit value read from portx
*/


uint16_t MCAL_GPIO_READ_PORT(GPIO_T * GPIOx){
	uint16_t VAL;
	VAL = (uint16_t)GPIOx->IDR;
	return VAL;
}

/**================================================================
* @Fn - MCAL_GPIO_WRITE_PIN
* @brief - Write a value in a specific pin portx
* @param[in] - portx
* @param[in] - number of a specific pint in portx
* @param[out] - 8 bit value Written to pinx in portx
*/

void MCAL_GPIO_WRITE_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER , uint8_t VAL){
	if(VAL){
		GPIOx->BSRR |= (VAL << PIN_NUMBER);
	}
	else{
		GPIOx->BRR |= ~(VAL << PIN_NUMBER);
	}
}

/**================================================================
* @Fn - MCAL_GPIO_WRITE_PORT
* @brief - Write a value in the whole port
* @param[in] - portx
* @param[out] - 8 bit value Written to portx
*/

void MCAL_GPIO_WRITE_PORT(GPIO_T * GPIOx , uint16_t VAL){
	GPIOx->ODR &= 0xFFFF0000;
	GPIOx->ODR |= VAL;
}

/**================================================================
* @Fn - MCAL_GPIO_TOGGLE_PIN
* @brief - toggle a specific pin
* @param[in] - portx
* @param[in] - pin number
*/

void MCAL_GPIO_TOGGLE_PIN(GPIO_T * GPIOx , uint16_t PIN_NUMBER){
	GPIOx->ODR ^= (1 << PIN_NUMBER);
}

/**================================================================
* @Fn - MCAL_GPIO_LOCK_PIN
* @brief - lock the value of a specific pin
* @param[in] - portx
* @param[out] - pin number needed to be locked
* @retval - 8 bit value for lock
*/

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
