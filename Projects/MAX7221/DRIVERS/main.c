/*
 * DRIVERS.c
 *
 * Created: 2/6/2023 4:11:34 PM
 * Author : Bishoy Refaat
 */ 

#include "ATMEGA32.h"
#include "EXTI.h"
#include "GPIO.h"
#include "USART.h"
#include "LCD_DRIVER.h"
#include "KEYPAD_DRIVER.h"
#include "SEVEN_SEG.h"
#include "SPI.h"
#include "MAX7221.h"



#define  SPI_ACT_AS_MASTER
SPI_CFG_t spicfg;
uint16_t BUFFER;
MAX7221_CFG_t MAX7221cfg;



int main(void)
{
	spicfg.CPHA = CPHA_FirstEdge;
	spicfg.CPOL = CPOL_High;
	spicfg.DORD = DORD_MSB;
	spicfg.SPRn = SPRn_4;
	spicfg.SPI2X = SPI2X_Disable;
	spicfg.SPE = SPE_Enable;
	
#ifdef SPI_ACT_AS_MASTER
	spicfg.MSTR = MSTR_Master;
	spicfg.SPIE = SPIE_Disable;
	spicfg.PSPI_CallBack = NULL;
#endif	
	
		
	MCAL_SPI_Init(&spicfg);



	MCAL_GPIO_TOGGLE_PIN(PORTB ,4);
	MCAL_SPI_SendData(0x9 , &spicfg);
	MCAL_SPI_SendData(0xFF , &spicfg);
	MCAL_GPIO_TOGGLE_PIN(PORTB ,4);






	MAX7221cfg.Initial_PowerUp = Initial_PowerUp_NormalOperation;
	MAX7221cfg.DECODE_MODE = DECODE_MODE_CodeB_0_7;
	MAX7221cfg.Intensity_MODE = Intensity_MODE_16by16;
	MAX7221cfg.Scan_Limit = ScanLimitReg_0_7;
	MAX7221_INIT(&MAX7221cfg , &spicfg);
	
uint8_t tmp;

	MAX7221_DISP (Digit0_add , blank_DR);
	MAX7221_DISP (Digit1_add , blank_DR);
	MAX7221_DISP (Digit2_add , blank_DR);
	MAX7221_DISP (Digit3_add , blank_DR);
	MAX7221_DISP (Digit4_add , blank_DR);
	MAX7221_DISP (Digit5_add , blank_DR);
	MAX7221_DISP (Digit6_add , blank_DR);
	MAX7221_DISP (Digit7_add , blank_DR);
	while (1){
		
		
		MAX7221_DISP (Digit2_add , H_DR);
		MAX7221_DISP (Digit3_add , E_DR);
		MAX7221_DISP (Digit4_add , L_DR);
		MAX7221_DISP (Digit5_add , P_DR);
					
		MAX7221_DISP (Digit0_add , blank_DR);
		MAX7221_DISP (Digit1_add , blank_DR);
		MAX7221_DISP (Digit2_add , blank_DR);
		MAX7221_DISP (Digit3_add , blank_DR);
		MAX7221_DISP (Digit4_add , blank_DR);
		MAX7221_DISP (Digit5_add , blank_DR);
		MAX7221_DISP (Digit6_add , blank_DR);
		MAX7221_DISP (Digit7_add , blank_DR);
					
			
	}
}
