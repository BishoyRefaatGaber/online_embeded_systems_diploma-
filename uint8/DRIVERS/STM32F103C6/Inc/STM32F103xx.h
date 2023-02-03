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
#define NVIC_BASE 		0xE000E100
#define NVIC_STIR_BASR 	0xE000EF00

#define NVIC_ISER0		*((volatile uint32_t*)(NVIC_BASE + 0x000))
#define NVIC_ISER1		*((volatile uint32_t*)(NVIC_BASE + 0x004))
#define NVIC_ISER2		*((volatile uint32_t*)(NVIC_BASE + 0x008))

#define NVIC_ICER0		*((volatile uint32_t*)(NVIC_BASE + 0x080))
#define NVIC_ICER1		*((volatile uint32_t*)(NVIC_BASE + 0x084))
#define NVIC_ICER2		*((volatile uint32_t*)(NVIC_BASE + 0x088))

#define NVIC_ISPR0		*((volatile uint32_t*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1		*((volatile uint32_t*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2		*((volatile uint32_t*)(NVIC_BASE + 0x108))

#define NVIC_ICPR0		*((volatile uint32_t*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1		*((volatile uint32_t*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2		*((volatile uint32_t*)(NVIC_BASE + 0x188))

#define NVIC_IABR0		*((volatile uint32_t*)(NVIC_BASE + 0x200))
#define NVIC_IABR1		*((volatile uint32_t*)(NVIC_BASE + 0x204))
#define NVIC_IABR2		*((volatile uint32_t*)(NVIC_BASE + 0x208))



#define NVIC_STIR		*((volatile uint32_t*)(NVIC_STIR_BASR + 0xE00))

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
#define USART1_BASE		0x40013800U
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
#define USART3_BASE 				0x40004800
#define USART2_BASE					0x40004400
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
	volatile uint32_t EXTICR[4];
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


/**************USART Registers**************/

typedef struct{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
}USART_t;



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

#define NVIC		((NVIC_t*))

#define USART1		((USART_t*)USART1_BASE)
#define USART2		((USART_t*)USART2_BASE)
#define USART3		((USART_t*)USART3_BASE)




//---------------------------------------------
//CLOCK ENABLE MACROS
//---------------------------------------------

#define RCC_GPIOA_CLK_EN()  (RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN()  (RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN()  (RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN()  (RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN()  (RCC->APB2ENR |= 1 << 6)
#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR |= 1 << 0)
#define RCC_USART1_CLK_EN()   (RCC->APB2ENR |= 1 << 14)
#define RCC_USART2_CLK_EN()   (RCC->APB1ENR |= 1 << 17)
#define RCC_USART3_CLK_EN()   (RCC->APB1ENR |= 1 << 18)




//*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*
//IVT
//*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*

//EXTI
#define  EXTI0_IRQ		6
#define  EXTI1_IRQ		7
#define  EXTI2_IRQ		8
#define  EXTI3_IRQ		9
#define  EXTI4_IRQ		10
#define  EXTI5_IRQ		23
#define  EXTI6_IRQ		23
#define  EXTI7_IRQ		23
#define  EXTI8_IRQ		23
#define  EXTI9_IRQ		23

#define  USART1_IRQ		37
#define  USART2_IRQ		38
#define  USART3_IRQ		39

#define  EXTI10_IRQ		40
#define  EXTI11_IRQ		40
#define  EXTI12_IRQ		40
#define  EXTI13_IRQ		40
#define  EXTI14_IRQ		40
#define  EXTI15_IRQ		40


//*-*--*-*-*--*-**--*-*--*-*-*-*-*--*-*--*-*-
//NVIC IRQ ENABLE/DISABLE MACROS:
//*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*--*-*--**--
#define NVIC_IRQ6_EXTI0_ENABLE			(NVIC_ISER0 |= 1 << 6)
#define NVIC_IRQ7_EXTI1_ENABLE			(NVIC_ISER0 |= 1 << 7)
#define NVIC_IRQ8_EXTI2_ENABLE			(NVIC_ISER0 |= 1 << 8)
#define NVIC_IRQ9_EXTI3_ENABLE			(NVIC_ISER0 |= 1 << 9)
#define NVIC_IRQ10_EXTI4_ENABLE			(NVIC_ISER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_ENABLE		(NVIC_ISER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_ENABLE		(NVIC_ISER1 |= 1 << 8)  //40-32

#define NVIC_IRQ37_USART1_ENABLE		(NVIC_ISER1 |= 1 << 5)  //37-32
#define NVIC_IRQ38_USART2_ENABLE		(NVIC_ISER1 |= 1 << 6)  //38-32
#define NVIC_IRQ39_USART3_ENABLE		(NVIC_ISER1 |= 1 << 7)  //39-32


#define NVIC_IRQ6_EXTI0_DISABLE			(NVIC_ICER0 |= 1 << 6)
#define NVIC_IRQ7_EXTI1_DISABLE			(NVIC_ICER0 |= 1 << 7)
#define NVIC_IRQ8_EXTI2_DISABLE			(NVIC_ICER0 |= 1 << 8)
#define NVIC_IRQ9_EXTI3_DISABLE			(NVIC_ICER0 |= 1 << 9)
#define NVIC_IRQ10_EXTI4_DISABLE		(NVIC_ICER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_DISABLE		(NVIC_ICER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_DISABLE	(NVIC_ICER1 |= 1 << 8)   //40-32

#define NVIC_IRQ37_USART1_DISABLE	(NVIC_ICER1 |= 1 << 5)	//37-32
#define NVIC_IRQ38_USART2_DISABLE	(NVIC_ICER1 |= 1 << 6)	//38-32
#define NVIC_IRQ39_USART3_DISABLE	(NVIC_ICER1 |= 1 << 7)	//39-32




#endif /* INC_STM32F103XX_H_ */
