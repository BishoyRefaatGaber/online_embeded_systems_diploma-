/*
 * MAX7221.c
 *
 * Created: 3/18/2023 1:02:12 AM
 *  Author: Bishoy Refaat
 */ 

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|


#include "MAX7221.h"


SPI_CFG_t SPI_Config;

void MAX7221_INIT(MAX7221_CFG_t *max7221cfg ,SPI_CFG_t * spicfg)
{
	SPI_Config = *spicfg;
	
	MAX7221_WriteCommand(DecodeMode_add , max7221cfg->DECODE_MODE , &SPI_Config);	//Decode-Mode
	MAX7221_WriteCommand(Intensity_add , max7221cfg->Intensity_MODE , &SPI_Config);	//Intensity Control and Inter digit Blanking
	MAX7221_WriteCommand(ScanLimit_add , max7221cfg->Scan_Limit , &SPI_Config);	//Scan-Limit Register
	MAX7221_WriteCommand(Shutdown_add , max7221cfg->Initial_PowerUp , &SPI_Config);  //Mode Register
	
}

void MAX7221_DISP (uint8_t address , uint8_t data)
{
	MAX7221_WriteCommand(address , data , &SPI_Config);
	_delay_ms(700);
}


void MAX7221_WriteCommand (uint8_t address , uint8_t data , SPI_CFG_t * spicfg)
{
	MCAL_GPIO_TOGGLE_PIN(PORTB ,4);
	MCAL_SPI_SendData(address , spicfg);
	MCAL_SPI_SendData(data , spicfg);
	MCAL_GPIO_TOGGLE_PIN(PORTB ,4);	
}
