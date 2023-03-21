/*
 * USART.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bishoy Refaat
 */

#ifndef USART_DRIVER_INC_USART_H_
#define USART_DRIVER_INC_USART_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "STM32F103xx.h"
#include "GPIO.h"
#include "RCC.h"


//		|-----------------------------------------------|
//		|======User Type Definitions (structures)=======|
//		|-----------------------------------------------|


typedef struct {

	uint16_t UE;		//Enable or disable the USART
							// Configurable @ref UE_define


	uint16_t RE_TE;	   //Specifies which mode of USART to be configured transmit or receive
							// Configurable @ref RE_TE_define

	uint32_t USART_BaudRate;	//Specifies the baud rate of USART
								// Configurable @ref USART_BaudRate_define


	uint16_t M;	//Specifies the number of data bits per frame
							//Configurable @ref M_define

	uint16_t PS_PCE;			//Specifies the parity of the USART
							//Configurable @ref PS_PCE_define

	uint16_t STOP;		//Specifies the number of the stop bits  of the USART
							//Configurable @ref STOP_define

	uint16_t Flow_CTRL;		//Specifies the flow control of the USART
							//Configurable @ref USART_Flow_CTRL_define

	uint16_t IRQ_Enable;		//Enable or disable USART IRQ TX/RX
							//Configurable @ref USART_IRQ_Enable_define


	void(*P_IRQ_CALL_BACK)(void); 		//Set the C function which will be called once the IRQ happen .



}USART_CFG_t;




//		|-----------------------------------------------|
//		|========Macros Configurations References=======|
//		|-----------------------------------------------|

		/*****@ref UE_define*****/
#define UE_Enable		(1 << 13)
#define UE_Disable		0

		/*****@ref RE_TE_define*****/
#define RE_TE_TX		(1 << 3)
#define RE_TE_RX		(1 << 2)
#define RE_TE_TXRX	(1 << 2 | 1 << 3)


		/*****@ref USART_BaudRate_define*****/

#define USART_BaudRate_2400		2400
#define USART_BaudRate_9600		9600
#define USART_BaudRate_19200	19200
#define USART_BaudRate_57600	57600
#define USART_BaudRate_115200	115200
#define USART_BaudRate_230400	230400
#define USART_BaudRate_460800	460800
#define USART_BaudRate_921600	921600
#define USART_BaudRate_2250000	2250000
#define USART_BaudRate_4500000	4500000


		/*****@ref M_define*****/
#define M_8bit	0
#define M_9bit	(1 << 12)


		/*****@ref USART_Parity_define*****/
#define PS_PCE_EN_Odd		(0b11 << 9)
#define PS_PCE_EN_Even		(0b10 << 9)
#define PS_PCE_DISABLE		0


		/*****@ref STOP_define*****/

#define STOP_Half			(1 << 12)
#define STOP_One			(0)
#define STOP_OneAndHalf		(3 << 12)
#define STOP_Two			(2 << 12)


		/*****@ref USART_Flow_CTRL_define*****/
#define	USART_Flow_CTRL_NONE 		(0)
#define	USART_Flow_CTRL_RTS			(1 << 8)
#define	USART_Flow_CTRL_CTS			(1 << 9)
#define	USART_Flow_CTRL_CTS_RTS		(0b11 << 8)



		/*****@ref USART_IRQ_Enable_define*****/
#define USART_IRQ_Enable_NONE 		(0)
#define USART_IRQ_Enable_TXE 		(0b01000 << 4) 	//Transmit data register empty
#define USART_IRQ_Enable_TC 		(0b00100 << 4)		//Transmission complete
#define USART_IRQ_Enable_RXNEIE 	(0b00010 << 4)		//Receive data ready to be read & overrun error detected
#define USART_IRQ_Enable_PE 		(0b10000 << 4)		//Parity error



//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL EXTI DRIVER"=================|
//		|------------------------------------------------------------------|

enum USART_Polling_mechanism{
	USART_enable,
	USART_disable
};

/**================================================================
* @Fn - MCAL_USART_INIT
* @brief - Initialize USART
* @param[in] - USART number (1 , 2 , 3) & registers
* @param[in] - USART pin configurations
*/
void MCAL_USART_INIT(USART_t * USARTx , USART_CFG_t * USART_Config);


/**================================================================
* @Fn - MCAL_USART_RESET
* @brief - Reset USART
* @param[in] - USART number (1 , 2 , 3) & registers
*/
void MCAL_USART_RESET(USART_t * USARTx);


/**================================================================
* @Fn - MCAL_USART_GPIO_SetPins
* @brief - Set the GPIO pins according to the chosen USART
* @param[in] - USART number (1 , 2 , 3) & registers
* @param[in] - USART pin configurations
*/
void MCAL_USART_GPIO_SetPins(USART_t * USARTx ,USART_CFG_t * USART_Config);



/**================================================================
* @Fn - MCAL_USART_SendData
* @brief - Send data from the microcontroller to another peripheral cross USART
* @param[in] - USART number (1 , 2 , 3) & registers
* @param[in] - Pointer to the buffer used to store data
* @param[in] - Check if the polling mechanism enabled or not
* @param[in] - USART pin configurations
*/
void MCAL_USART_SendData(USART_t * USARTx , uint16_t * PTxBuffer , enum USART_Polling_mechanism  PollingEn ,USART_CFG_t * USART_Config);



/**================================================================
* @Fn - MCAL_USART_ReceiveData
* @brief - Receive data from a particular peripheral to microcontroller cross USART
* @param[in] - USART number (1 , 2 , 3) & registers
* @param[in] - Pointer to the buffer used to store data
* @param[in] - Check if the polling mechanism enabled or not
* @param[in] - USART pin configurations
*/
void MCAL_USART_ReceiveData(USART_t * USARTx , uint16_t * PTxBuffer , enum USART_Polling_mechanism  PollingEn , USART_CFG_t * USART_Config);



/**================================================================
* @Fn - MCAL_USART_WAIT_TC
* @brief - Check if the transmission completed
* @param[in] - USART number (1 , 2 , 3) & registers
*/
void MCAL_USART_WAIT_TC(USART_t * USARTx);



//todo void MCAL_USART_LIN_INIT();
//todo void MCAL_USART_INIT();
//todo void MCAL_USART_DMA_INIT();
//todo void MCAL_USART_LIN_INIT();





#endif /* USART_DRIVER_INC_USART_H_ */
