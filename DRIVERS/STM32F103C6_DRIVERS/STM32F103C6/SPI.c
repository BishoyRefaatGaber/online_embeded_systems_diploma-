/*
 * SPI.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Bishoy Refaat
 */

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|
#include "SPI.h"

//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

#define SPI_SR_TXE 	((uint8_t)0x02)	//!< Transmit buffer empty
#define SPI_SR_RXNE	((uint8_t)0x01)	//!< Receive buffer not empty

//		|-----------------------------------------------|
//		|=============GENERIC VARIABLES=================|
//		|-----------------------------------------------|

SPI_CFG_t *GP_SPI_CFG[2] ={NULL , NULL};

enum SPI_INDEX{
	SPI1_INDEX,
	SPI2_INDEX
};


//		|-----------------------------------------------|
//		|=============GENERIC FUNCTIONS=================|
//		|-----------------------------------------------|



//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|

void MCAL_SPI_INIT(SPI_t * SPIx , SPI_CFG_t * SPI_Config){
	//safety for registers
	uint16_t tmpreg_CR1 = 0 ;
	uint16_t tmpreg_CR2 = 0;

	//SPI CLOCK ENABLE
	if(SPIx == SPI1){
		GP_SPI_CFG [SPI1_INDEX] = SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if (SPIx == SPI2){
		GP_SPI_CFG [SPI2_INDEX] = SPI_Config;
		RCC_SPI2_CLK_EN();
	}


	//Enable SPI CR1 : BIT 6   SPE : enable
	tmpreg_CR1 = 1 << 6;

	//Slave or Master
	tmpreg_CR1 |= SPI_Config->MSTR;

	//SPI communication mode
	tmpreg_CR1 |= SPI_Config->BIDIOE_BIDIMODE;

	//SPI frame format
	tmpreg_CR1 |= SPI_Config->LSBFIRST;

	//Data size
	tmpreg_CR1 |= SPI_Config->DFF;

	//Clock polarity
	tmpreg_CR1 |= SPI_Config->CPOL;

	//Clock phase
	tmpreg_CR1 |= SPI_Config->CPHA;

	//NSS
	if(SPI_Config->NSS == NSS_Hard_Master_SS_output_enable){
		tmpreg_CR2 |= SPI_Config->NSS;
	}
	else if (SPI_Config->NSS == NSS_Hard_Master_SS_output_disable){
		tmpreg_CR2 &= SPI_Config->NSS;
	}
	else {
		tmpreg_CR1 |= SPI_Config->NSS;
	}


	//Baud rate prescaler
	tmpreg_CR1 |= SPI_Config->BR;


	//Interrupt enable
	if(SPI_Config->SPI_IRQ != SPI_IRQ_Enable_NONE){
		tmpreg_CR2 |= SPI_Config->SPI_IRQ;

		if(SPIx == SPI1){
			NVIC_IRQ35_SPI1_ENABLE;
		}
		else if(SPIx == SPI2){
			NVIC_IRQ36_SPI2_ENABLE;
		}
	}

	SPIx->CR1 = tmpreg_CR1;
	SPIx->CR2 = tmpreg_CR2;

}




void MCAL_SPI_RESET(SPI_t * SPIx){
	if(SPIx == SPI1){
		NVIC_IRQ35_SPI1_DISABLE;
		RCC_SPI1_RESET();
	}
	else if(SPIx == SPI2){
		NVIC_IRQ36_SPI2_DISABLE;
		RCC_SPI2_RESET();
	}
}




void MCAL_SPI_GPIO_SetPins(SPI_t * SPIx ){

	GPIO_PinConfig_t SPI_PinCFG;
	if(SPIx == SPI1){
		//PA4 : SPI1_NSS
		//PA5 : SPI1_SCK
		//PA6 : SPI1_MISO
		//PA7 : SPI1_MOSI
		if(GP_SPI_CFG[SPI1_INDEX]->MSTR == MSTR_Master){

			//PA4 : SPI1_NSS
			switch(GP_SPI_CFG[SPI1_INDEX]->NSS){
			case ((uint16_t)NSS_Hard_Master_SS_output_disable):

				//Hardware master / slave Input floating
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
				MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);
				break;

			case NSS_Hard_Master_SS_output_enable :

				//Hardware master / slave NSS output enabled Alternative function push-pull
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
				MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);
				break;
			}

			//PA5 : SPI1_SCK
			//Master Alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);

			//PA6 : SPI1_MISO
			//full duplex / master input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);

			//PA7 : SPI1_MOSI
			//full duplex / master alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);

		}
		else if(GP_SPI_CFG[SPI1_INDEX]->MSTR == MSTR_Slave){

			//PA4 : SPI1_NSS
			if(GP_SPI_CFG[SPI1_INDEX]->NSS == NSS_Hard_Slave){

				//Hardware master / slave Input floating
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
				MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);
			}

			//PA5 : SPI1_SCK
			//Slave input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);

			//PA6 : SPI1_MISO
			//full duplex / master input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);

			//PA7 : SPI1_MOSI
			//full duplex / master alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOA, &SPI_PinCFG);
		}
	}
	else if(SPIx == SPI2){

		//PB12 : SPI2_NSS
		//PB13 : SPI2_SCK
		//PB14 : SPI2_MISO
		//PB15 : SPI2_MOSI
		if(GP_SPI_CFG[SPI2_INDEX]->MSTR == MSTR_Master){

			//PB12 : SPI2_NSS
			switch(GP_SPI_CFG[SPI2_INDEX]->NSS){
			case (uint16_t)NSS_Hard_Master_SS_output_disable:

				//Hardware master / slave Input floating
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
				MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);
				break;

			case NSS_Hard_Master_SS_output_enable :

				//Hardware master / slave NSS output enabled Alternative function push-pull
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
				MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);
				break;
			}

			//PB13 : SPI2_SCK
			//Master Alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);

			//PB14 : SPI1_MISO
			//full duplex / master input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);

			//PB15 : SPI1_MOSI
			//full duplex / master alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_15;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);
		}
		else if(GP_SPI_CFG[SPI2_INDEX]->MSTR == MSTR_Slave){

			//PB12 : SPI2_NSS
			if(GP_SPI_CFG[SPI2_INDEX]->NSS == NSS_Hard_Slave){

				//Hardware master / slave Input floating
				SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				SPI_PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
				SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
				MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);
			}

			//PB13 : SPI2_SCK
			//Slave input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);

			//PB14 : SPI2_MISO
			//full duplex / master input floating
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_10MHZ;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);

			//PB15 : SPI2_MOSI
			//full duplex / master alternative function push-pull
			SPI_PinCFG.GPIO_PinNumber = GPIO_PIN_15;
			SPI_PinCFG.GPIO_MODE = GPIO_MODE_ALTERNATIVE_INPUT;
			SPI_PinCFG.GPIO_FREQ_SPEED = GPIO_FREQ_IN;
			MCAL_GPIO_INIT_PIN(GPIOB, &SPI_PinCFG);
		}
	}


}




void MCAL_SPI_SendData(SPI_t * SPIx , uint16_t * PTxBuffer , enum SPI_Polling_mechanism  PollingEn ){
	if(PollingEn == SPI_enable)
		while(!(SPIx->SR & SPI_SR_TXE));
	SPIx->DR = *PTxBuffer;
}




void MCAL_SPI_ReceiveData(SPI_t * SPIx , uint16_t * PTxBuffer , enum SPI_Polling_mechanism  PollingEn ){
	if(PollingEn == SPI_enable)
		while(!(SPIx->SR & SPI_SR_RXNE));
	*PTxBuffer = SPIx->DR;
}




void MCAL_SPI_TX_RX(SPI_t * SPIx , uint16_t * PTxBuffer , enum SPI_Polling_mechanism  PollingEn ){
	if(PollingEn == SPI_enable)
	//	while(SPIx->SR != 2);
	SPIx->DR = *PTxBuffer;

	if(PollingEn == SPI_enable)
		while(!(SPIx->SR & SPI_SR_RXNE));
	*PTxBuffer = SPIx->DR;
}
//SPIx->SR & SPI_SR_TXE






