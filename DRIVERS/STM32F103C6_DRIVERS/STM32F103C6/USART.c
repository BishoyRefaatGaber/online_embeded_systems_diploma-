/*
 * USART.c
 *
 *  Created on: Feb 3, 2023
 *      Author: Bishoy Refaat
 */


//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "USART.h"


USART_CFG_t * G_USARTx[3] = {NULL , NULL , NULL};
//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

//_PCLK_  -> clock of the system taken from microcontroller (RCC registers)
//_BAUD_  -> Baud rate taken from the user
//Tx/Rx baud = fCK / (16*USARTDIV)   -> fck = _PCLK_ ----->> USARTDIV = fck / ( 16 * Tx/Rx baud)
//USARTDIV = DIV_Mantissa + (DIV_Fraction / 16)
#define USARTDIV(_PCLK_,_BAUD_)				(uint32_t)(_PCLK_ / ( 16 * _BAUD_))	//Get an integer value of the USARTDIV
#define USARTDIV_MUL100(_PCLK_,_BAUD_)		(uint32_t)((25 * _PCLK_) / (4 * _BAUD_)) //Multiply the USARTDIV by 100
#define Mantissa_MUL100(_PCLK_,_BAUD_)		(uint32_t)(USARTDIV(_PCLK_,_BAUD_) * 100)//Multiply the Mantissa by 100
#define Mantissa(_PCLK_,_BAUD_)				(uint32_t)(USARTDIV(_PCLK_,_BAUD_))	//Get an integer value of the Mantissa
#define DIV_Fraction(_PCLK_,_BAUD_)			(uint32_t)((USARTDIV_MUL100(_PCLK_,_BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_)) * 16 / 100)//Get the fraction
#define USART_BRR_Register(_PCLK_,_BAUD_)	(uint32_t)((Mantissa(_PCLK_,_BAUD_) << 4 | (DIV_Fraction(_PCLK_,_BAUD_) & 0xF)))//Put the manissa and the fraction on BRR


//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|


void MCAL_USART_INIT(USART_t * USARTx , USART_CFG_t * USART_Config){

	uint32_t Pclk,BRR;

	//Enable the clock for the USART
	if(USARTx == USART1)
		RCC_USART1_CLK_EN();
	else if (USARTx == USART2)
		RCC_USART2_CLK_EN();
	else if (USARTx == USART3)
		RCC_USART3_CLK_EN();


	if(USARTx == USART1)
		G_USARTx[0] = USART_Config;
	else if (USARTx == USART2)
		G_USARTx[1] = USART_Config;
	else if (USARTx == USART3)
		G_USARTx[2] = USART_Config;

	//Enable the UART module
	USARTx->CR1 = (USARTx->CR1 & ~(1 << 13)) | USART_Config->UE;

	//PayLoad
	USARTx->CR1 = (USARTx->CR1 & ~(1 << 12)) | USART_Config->M;

	//stop bits
	USARTx->CR2 = (USARTx->CR2 & ~(0b11 << 12)) | USART_Config->STOP;

	//Baud rate
		if(USARTx == USART1)
			Pclk = MCAL_RCC_GET_PCLK2_FRQ();
		else
			Pclk = MCAL_RCC_GET_PCLK1_FRQ();


		BRR = USART_BRR_Register(Pclk,USART_Config->USART_BaudRate);
		USARTx->BRR = BRR;


	//Enable TX RX
	USARTx->CR1 = (USARTx->CR1 & ~(0b11 << 2)) | USART_Config->RE_TE;


	//Parity
	USARTx->CR1 = (USARTx->CR1 & ~ (0b11 << 9)) | USART_Config->PS_PCE;


	//Flow control
	USARTx->CR3 = (USARTx->CR1 & ~(0b11 << 8)) | USART_Config->Flow_CTRL;



	//Enable Interrupt
	if(USART_Config->IRQ_Enable != USART_IRQ_Enable_NONE){

		USARTx->CR1 = (USARTx->CR1 & ~(0b11110 << 4)) | USART_Config->IRQ_Enable;

		//Enable NVIC

		if(USARTx == USART1)
			NVIC_IRQ37_USART1_ENABLE;
		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_ENABLE;
		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_ENABLE;
	}

}

void MCAL_USART_RESET(USART_t * USARTx){

	if(USARTx == USART1){
		RCC_USART1_RESET();
		NVIC_IRQ37_USART1_DISABLE;
	}
	else if(USARTx == USART2){
		RCC_USART2_RESET();
		NVIC_IRQ38_USART2_DISABLE;
	}
	else if(USARTx == USART3){
		RCC_USART3_RESET();
		NVIC_IRQ39_USART3_DISABLE;
	}
}

void MCAL_USART_GPIO_SetPins(USART_t * USARTx ,USART_CFG_t * USART_Config){

	GPIO_PinConfig_t USART_PinCFG;

	if(USARTx == USART1){

		//PA9 TX
		//PA10 RX
		//PA11 CTS
		//PA12 RTS


		//PA9 TX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_9;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
		MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);


		//PA10 RX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_10;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
		MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PA11 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_11;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		}
		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_RTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PA11 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_12;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		}




	}
	else if(USARTx == USART2){

		//PA2 TX
		//PA3 RX
		//PA0 CTS
		//PA1 RTS


		//PA2 TX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_2;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
		MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);


		//PA3 RX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_3;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
		MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PA0 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_0;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		}
		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_RTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PA1 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_1;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOA, &USART_PinCFG);

		}




	}

	else if(USARTx == USART3){

		//PB10 TX
		//PB11 RX
		//PB13 CTS
		//PB14 RTS


		//PB10 TX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_10;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
		MCAL_GPIO_INIT_PIN(GPIOB, &USART_PinCFG);


		//PB11 RX
		USART_PinCFG.GPIO_PinNumber = GPIO_PIN_11;
		USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
		USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
		MCAL_GPIO_INIT_PIN(GPIOB, &USART_PinCFG);

		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PB13 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOB, &USART_PinCFG);

		}
		if(USART_Config->Flow_CTRL == USART_Flow_CTRL_RTS || USART_Config->Flow_CTRL == USART_Flow_CTRL_CTS_RTS){

			//PB14 CTS
			USART_PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			USART_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			USART_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOB, &USART_PinCFG);

		}




	}


}

void MCAL_USART_SendData(USART_t * USARTx , uint16_t * PTxBuffer , enum USART_Polling_mechanism  PollingEn ,USART_CFG_t * USART_Config){
	//check the polling
	if(PollingEn == USART_enable){
		while (! (USARTx->SR & (1 << 7)));

	}
	//get the data from the buffer to the DR
	if(USART_Config->M == M_9bit){
		USARTx->DR = (*PTxBuffer & (uint16_t)0x1FF);
	}
	else if (USART_Config->M == M_8bit){
		USARTx->DR = (*PTxBuffer & (uint8_t)0xFF);
	}
}

void MCAL_USART_ReceiveData(USART_t * USARTx , uint16_t * PTxBuffer , enum USART_Polling_mechanism  PollingEn , USART_CFG_t * USART_Config){

	if(PollingEn == USART_enable){
		while (! (USARTx->SR & (1 << 5)));

	}
	//get the data from the DR to the buffer
	if(USART_Config->PS_PCE != PS_PCE_DISABLE){
		if(USART_Config->M == M_9bit){

			*PTxBuffer = ( USARTx->DR & (uint16_t)0xFF);
		}
		else if (USART_Config->M == M_8bit){

			*PTxBuffer = (USARTx->DR & (uint8_t)0x7F);
		}
	}
	else{
		if(USART_Config->M == M_9bit){

			*PTxBuffer = ( USARTx->DR & (uint16_t)0x1FF);
		}
		else if (USART_Config->M == M_8bit){

			*PTxBuffer = (USARTx->DR & (uint8_t)0xFF);
		}
	}
}

void MCAL_USART_WAIT_TC(USART_t * USARTx){
	while (! (USARTx->SR & (1 << 6)));

}





void USART1_IRQHandler(void){
	G_USARTx[0]->P_IRQ_CALL_BACK();
}
void USART2_IRQHandler(void){
	G_USARTx[1]->P_IRQ_CALL_BACK();
}
void USART3_IRQHandler(void){
	G_USARTx[2]->P_IRQ_CALL_BACK();
}






