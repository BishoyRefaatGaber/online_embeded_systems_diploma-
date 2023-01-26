/*
 * STM32F103xx.h
 *
 *  Created on: Jan 3, 2023
 *      Author: Bishoy Refaat
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
//--------------------------------------------
//includes
//--------------------------------------------

#include "stdint.h"
#include "stdlib.h"


//--------------------------------------------
//base addresses for memories
//--------------------------------------------

#define FLASH_MEMORY_BASE								0x08000000UL
#define System_MEMORY_BASE								0x1FFFF000UL
#define OPTION_Bytes_BASE								0x1FFFF800UL
#define SRAM_MEMORY_BASE								0x20000000UL
#define Peripherals_MEMORY_BASE							0x04000000UL
#define CORTEX_M3_Internal_Peripherals_MEMORY_BASE		0xE0000000UL



//---------------------------------------------
//Base addresses for bus peripherals
//---------------------------------------------


/**************AHB_BUS_ADDRESSES**************/

#define FSMC						0xA0000000UL
#define USB_OTG_FS					0x50000000UL
#define Ethernet					0x40028000UL
#define CRC							0x40023000UL
#define FLASH_Memory_Interface		0x40022000UL
#define RCC_BASE					0x40021000UL
#define DMA2 						0x40020400UL
#define DMA1 						0x40020000UL
#define SDIO 						0x40018000UL


/**************APB2_BUS_ADDRESSES**************/


#define TIM11_timer		0x40015400U
#define TIM10_timer		0x40015000U
#define TIM9_timer		0x40014C00U
#define ADC3			0x40013C00U
#define USART1			0x40013800U
#define TIM8_timer		0x40013400U
#define SPI1			0x40013000U
#define TIM1_timer		0x40012C00U
#define ADC2			0x40012800U
#define ADC1			0x40012400U
#define GPIO_PortG		0x40012000U
#define GPIO_PortF		0x40011C00U
#define GPIO_PortE		0x40011800U
#define GPIO_PortD		0x40011400U
#define GPIO_PortC		0x40011000U
#define GPIO_PortB		0x40010C00U
#define GPIO_PortA		0x40010800U
#define EXTI_BASE 		0x40010400U
#define AFIO_BASE 		0x40010000U


/**************APB1_BUS_ADDRESSES**************/


#define DAC								0x40007400
#define Power_control_PWR 				0x40007000
#define Backup_registers_BKP 			0x40006C00
#define bxCAN1 							0x40006400
#define bxCAN2 							0x40006800
#define Shared_USB_CAN_SRAM_512_bytes 	0x40006000
#define USB_device_FS_registers 		0x40005C00
#define I2C2 							0x40005800
#define I2C1 							0x40005400
#define UART5 							0x40005000
#define UART4 						0x40004C00
#define USART3 						0x40004800
#define USART2						0x40004400
#define SPI3_I2S 					0x40003C00
#define SPI2_I2S 					0x40003800
#define Independent_watchdog_IWDG 	0x40003000
#define Window_watchdog_WWDG  		0x40002C00
#define RTC							0x40002800
#define TIM14_timer					0x40002000
#define TIM13_timer					0x40001C00
#define TIM12_timer					0x40001800
#define TIM7_timer					0x40001400
#define TIM6_timer					0x40001000
#define TIM5_timer 					0x40000C00
#define TIM4_timer 					0x40000800
#define TIM3_timer 					0x40000400
#define TIM2_timer 					0x40000000



//---------------------------------------------
//Peripherals registers
//---------------------------------------------



/**************GPIO Registers**************/

typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_T;


/**************AFIO Registers**************/

typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_T;



/**************EXTI Registers**************/

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
	volatile uint32_t MAPR2;
}EXTI_T;


/**************RCC Registers**************/

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
}RCC_T;




//---------------------------------------------
//Peripherals Instants
//---------------------------------------------


#define GPIOG 		((GPIO_T*)GPIO_PortG)
#define GPIOF 		((GPIO_T*)GPIO_PortF)
#define GPIOE 		((GPIO_T*)GPIO_PortE)
#define GPIOD 		((GPIO_T*)GPIO_PortD)
#define GPIOC 		((GPIO_T*)GPIO_PortC)
#define GPIOB 		((GPIO_T*)GPIO_PortB)
#define GPIOA 		((GPIO_T*)GPIO_PortA)

#define RCC			((RCC_T*)RCC_BASE)
#define EXTI  		((EXTI_T*)EXTI_BASE)
#define AFIO  		((AFIO_T*)AFIO_BASE)


//---------------------------------------------
//CLOCK ENABLE MACROS
//---------------------------------------------



#define RCC_GPIOA_CLK_EN()  (RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN()  (RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN()  (RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN()  (RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN()  (RCC->APB2ENR |= 1 << 6)
#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR |= 1 << 0)




#endif /* INC_STM32F103XX_H_ */
