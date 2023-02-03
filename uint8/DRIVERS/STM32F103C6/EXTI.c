/*
 * INTERRUPT.c
 *
 *  Created on: Jan 31, 2023
 *      Author: Bishoy Refaat
 */


//1-Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
//2-Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR andEXTI_FTSR)
//3-Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
//External Interrupt Controller (EXTI) so that an interrupt coming from one of the 20 lines
//can be correctly acknowledged.




//---------------------------------
//includes
//---------------------------------

#include "EXTI.h"


//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

#define AFIO_GPIO_EXTI_MAPPING(x)	((x == GPIOA)? 0 :\
									(x == GPIOB)? 1 :\
									(x == GPIOC)? 2 : 3)



//		|-----------------------------------------------|
//		|=============GENERIC VARIABLES=================|
//		|-----------------------------------------------|

void(* GP_IRQ_CALL_BACK[15])(void);


//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|


/**================================================================
* @Fn - MCAL_GPIO_INIT
* @brief - Initialize the portx
* @param[in] - GPIO port
* @param[out] - GPIO pin in the specific port (in the last parameter)
*               takes values @ref GPIO_PinNumber  @ref GPIO_MODE  @ref GPIO_FREQ
*/
void MCAL_EXTI_INIT(EXTI_CONFIG_t * EXTI_CONFIG){
	Update_EXTI(EXTI_CONFIG);
}

void MCAL_EXTI_GPIO_RESET(void){
	EXTI->PR = 0xFFFFFFFF;
	EXTI->EMR = 0x00000000;
	EXTI->IMR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->MAPR2 = 0x00000000;
	EXTI->SWIER = 0x00000000;

	//DISABLE NVIC
	NVIC_IRQ6_EXTI0_DISABLE;
	NVIC_IRQ7_EXTI1_DISABLE;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_9_DISABLE;
	NVIC_IRQ40_EXTI10_15_DISABLE;
}
void MCAL_GPIO_UPDATE(EXTI_CONFIG_t * EXTI_CONFIG){
	Update_EXTI(EXTI_CONFIG);
}

//		|-----------------------------------------------|
//		|=============GENERIC FUNCTIONS=================|
//		|-----------------------------------------------|

void ENABLE_NVIC(uint16_t IRQ){
	switch (IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE;
		break;


	}
}


void DISABLE_NVIC(uint16_t IRQ){
	switch (IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE;
		break;


	}
}



void Update_EXTI(EXTI_CONFIG_t * EXTI_CONFIG){

	//1- Configure the GPIO to be AF input (floating input)
	GPIO_PinConfig_t PINCFG;
	PINCFG.GPIO_PinNumber = EXTI_CONFIG->EXTI_PIN.GPIO_PIN;
	PINCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
	PINCFG.GPIO_OUTPUT_SPEED = GPIO_FREQ_IN;
	MCAL_GPIO_INIT_PIN(EXTI_CONFIG->EXTI_PIN.GPIO_PORT , &PINCFG);
//  _____________________________________________________________________

	//2- Configure the AFIO to route between the EXTI lines with ports A , B , C , D
	uint8_t AFIO_EXTICR_INDEX = EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER / 4 ;
	uint8_t AFIO_EXTICR_POSITION = (EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER % 4) * 4;
	AFIO->EXTICR[AFIO_EXTICR_INDEX] = (AFIO->EXTICR[AFIO_EXTICR_INDEX] & ~(0xF << AFIO_EXTICR_POSITION)) | (AFIO_GPIO_EXTI_MAPPING(EXTI_CONFIG->EXTI_PIN.GPIO_PORT) << AFIO_EXTICR_POSITION);
//	________________________________________________________________________________________________________________________________________________________________________________________________________


// 3- Configure the rising & falling edges

	if(EXTI_CONFIG->TRIGGER_CASE == EXTI_CASE_RISING){
		EXTI->RTSR = (EXTI->RTSR & ~(1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN)) | (1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN);
	}
	else if(EXTI_CONFIG->TRIGGER_CASE == EXTI_CASE_FALLING){
		EXTI->FTSR = (EXTI->FTSR & ~(1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN)) | (1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN);
	}
	else if(EXTI_CONFIG->TRIGGER_CASE == EXTI_CASE_RISING_FALLING){
		EXTI->RTSR = (EXTI->RTSR & ~(1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN)) | (1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN);
		EXTI->FTSR = (EXTI->FTSR & ~(1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN)) | (1 << EXTI_CONFIG->EXTI_PIN.GPIO_PIN);
	}
//	_________________________________________________________________________________________________________________

	//4- Configure IRQ Call back function

	GP_IRQ_CALL_BACK[EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER] = EXTI_CONFIG->P_IRQ_CALL_BACK;

	//5- Enable/Disable IRQ EXTI & NVIC

	if(EXTI_CONFIG->IRQ_EN == IRQ_ENABLE){
		EXTI->IMR |= (1 << EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER);
		ENABLE_NVIC(EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER);
	}
	else{
		EXTI->IMR &= ~(1 << EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER);
		DISABLE_NVIC(EXTI_CONFIG->EXTI_PIN.EXTI_INPUT_LINENUMBER);
	}

}













//		|-----------------------------------------------|
//		|=================ISR FUNCTIONS=================|
//		|-----------------------------------------------|


	void EXTI0_IRQHandler(void){

		EXTI->PR |= 1 << 0;
		GP_IRQ_CALL_BACK[0]();
	}


	void EXTI1_IRQHandler(void){
		EXTI->PR |= 1 << 1;
		GP_IRQ_CALL_BACK[1]();

	}

	void EXTI2_IRQHandler(void){
		EXTI->PR |= 1 << 2;
		GP_IRQ_CALL_BACK[2]();
	}

	void EXTI3_IRQHandler(void){
		EXTI->PR |= 1 << 3;
		GP_IRQ_CALL_BACK[3]();
	}


	void EXTI4_IRQHandler(void){
		EXTI->PR |= 1 << 4;
		GP_IRQ_CALL_BACK[4]();
	}


	void EXTI9_5_IRQHandler(void){
		if(EXTI->PR & (1 << 5 )) {EXTI->PR |= (1 << 5);  GP_IRQ_CALL_BACK[5]();}
		if(EXTI->PR & (1 << 6 )) {EXTI->PR |= (1 << 6);  GP_IRQ_CALL_BACK[6]();}
		if(EXTI->PR & (1 << 7 )) {EXTI->PR |= (1 << 7);  GP_IRQ_CALL_BACK[7]();}
		if(EXTI->PR & (1 << 8 )) {EXTI->PR |= (1 << 8);  GP_IRQ_CALL_BACK[8]();}
		if(EXTI->PR & (1 << 9 )) {EXTI->PR |= (1 << 9);  GP_IRQ_CALL_BACK[9]();}
	}


	void EXTI15_10_IRQHandler(void){
		if(EXTI->PR & (1 << 10 )) {EXTI->PR |= (1 << 10);  GP_IRQ_CALL_BACK[10]();}
		if(EXTI->PR & (1 << 11 )) {EXTI->PR |= (1 << 11);  GP_IRQ_CALL_BACK[11]();}
		if(EXTI->PR & (1 << 12 )) {EXTI->PR |= (1 << 12);  GP_IRQ_CALL_BACK[12]();}
		if(EXTI->PR & (1 << 13 )) {EXTI->PR |= (1 << 13);  GP_IRQ_CALL_BACK[13]();}
		if(EXTI->PR & (1 << 14 )) {EXTI->PR |= (1 << 14);  GP_IRQ_CALL_BACK[14]();}
		if(EXTI->PR & (1 << 15 )) {EXTI->PR |= (1 << 15);  GP_IRQ_CALL_BACK[15]();}
	}











































