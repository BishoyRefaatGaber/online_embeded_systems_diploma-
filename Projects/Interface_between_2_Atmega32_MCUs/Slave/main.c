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

//#define  SPI_ACT_AS_MASTER
#define  SPI_ACT_AS_SLAVE
USART_CFG_t usartcfg;
SPI_CFG_t spicfg;
uint16_t BUFFER;
void BIRG_USART_RXCIE(void){
	MCAL_USART_ReceiveData(&BUFFER , &usartcfg );
	LCD_WRITE_CHAR(BUFFER);
	MCAL_USART_SendData(&BUFFER , &usartcfg );
	
 	MCAL_SPI_ReceiveData(&BUFFER , &spicfg);
 	MCAL_SPI_SendData(&BUFFER , &spicfg);
	
}

void BIRG_USART_TXCIE(void){

}

void BIRG_USART_UDRIE(void){
	
}

void BIRG_SPI_SLAVE(void){
	#ifdef SPI_ACT_AS_SLAVE
		MCAL_SPI_ReceiveData(&BUFFER , &spicfg);
		MCAL_USART_SendData(&BUFFER , &usartcfg);
		LCD_WRITE_CHAR(BUFFER);
	#endif
}


void INIT(void){
	
	//RS
	struct GPIO_CFG_t gpiocfg;
	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_1;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	
	//EN
	
	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_2;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	
	//DATA

	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_3;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	
	
	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_4;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	
	
	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_5;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	

	gpiocfg.GPIO_PinNumber = GPIO_PinNumber_6;
	gpiocfg.GPIO_Mode = GPIO_Mode_OUTPUT;
	MCAL_GPIO_INIT_PIN(PORTA , &gpiocfg);
	LCD_INIT();

}

int main(void)
{
	INIT();
	usartcfg.INT_CASE = INT_CASE_Disable;
	usartcfg.CLK_MODE = CLK_MODE_ASYNCH;
	usartcfg.BaudRate = BaudRate_8MHZ_NORM_9600;
	usartcfg.ClockPolarity = ClockPolarity_Rising;
	usartcfg.DataSize = DataSize_8;
	usartcfg.Device_ASYNCH_MODE = Device_ASYNCH_MODE_NormalSpeed;
	usartcfg.MPCM_Case = MPCM_Case_Disable;
	usartcfg.Parity = Parity_Disable;
	usartcfg.P_USART_CallBack[0] = BIRG_USART_RXCIE;
	usartcfg.P_USART_CallBack[1] = BIRG_USART_TXCIE;
	usartcfg.P_USART_CallBack[2] = BIRG_USART_UDRIE;
	usartcfg.StopBits = StopBits_1BIT;
	usartcfg.USART_ENABLE = USART_ENABLE_TX_RX;
	MCAL_USART_Init(&usartcfg);
	
	
	spicfg.CPHA = CPHA_FirstEdge;
	spicfg.CPOL = CPOL_High;
	spicfg.DORD = DORD_LSB;
	spicfg.SPRn = SPRn_4;
	spicfg.SPI2X = SPI2X_Disable;
	spicfg.SPE = SPE_Enable;
	
#ifdef SPI_ACT_AS_MASTER
	spicfg.MSTR = MSTR_Master;
	spicfg.SPIE = SPIE_Disable;
	spicfg.PSPI_CallBack = NULL;
#endif	
	
#ifdef SPI_ACT_AS_SLAVE
spicfg.MSTR = MSTR_Slave;
spicfg.SPIE = SPIE_Enable;
spicfg.PSPI_CallBack = BIRG_SPI_SLAVE;
#endif	
	
	MCAL_SPI_Init(&spicfg);
	while (1){
		#ifdef SPI_ACT_AS_MASTER
		MCAL_USART_ReceiveData(&BUFFER , &usartcfg);
		MCAL_USART_SendData(&BUFFER , &usartcfg);
		MCAL_SPI_SendData(&BUFFER , &spicfg);
		LCD_WRITE_CHAR(BUFFER);
		#endif
	}
}
