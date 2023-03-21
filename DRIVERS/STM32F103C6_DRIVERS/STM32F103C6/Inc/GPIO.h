/*
 * GPIO.h
 *
 *  Created on: Jan 3, 2023
 *      Author: Bishoy Refaat
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "STM32F103xx.h"


//		|-----------------------------------------------|
//		|======User Type Definitions (structures)=======|
//		|-----------------------------------------------|

typedef enum {FALSE , TRUE}STATE;

typedef struct {

	uint16_t GPIO_PinNumber;  //Specifies the GPIO pins to be configured .
							   //This parameter must be a value of @ref GPIO_PinNumber

	uint8_t GPIO_MODE;   //Specifies the GPIO mode to be configured .
	   	   	   	   	   	  //This parameter must be a value of @ref GPIO_MODE

	uint8_t GPIO_FREQ_SPEED;   //Specifies the GPIO speed to be configured .
	   	   	                     //This parameter must be a value of @ref GPIO_FREQ
}GPIO_PinConfig_t;

/*
typedef struct{
	uint8_t GPIO_PinNumber;   //Number of pins needed to be configured  has no reference
	uint8_t GPIO_MODE;   	  //Specifies the GPIO mode to be configured .
							//This parameter must be a value of @ref GPIO_MODE

	uint8_t GPIO_OUTPUT_SPEED;		//Specifies the GPIO speed to be configured .
									//This parameter must be a value of @ref GPIO_FREQ
}GPIO_PortConfig_t;
*/


//		|-----------------------------------------------|
//		|=======Macros Configurations References========|
//		|-----------------------------------------------|

		/*****@ref GPIO_PinNumber*****/

#define GPIO_PIN_0    ((uint16_t)0)			/*Pin 0 Selected */
#define GPIO_PIN_1    ((uint16_t)1)			/*Pin 1 Selected */
#define GPIO_PIN_2    ((uint16_t)2) 		/*Pin 2 Selected */
#define GPIO_PIN_3    ((uint16_t)3)			/*Pin 3 Selected */
#define GPIO_PIN_4    ((uint16_t)4)			/*Pin 4 Selected */
#define GPIO_PIN_5    ((uint16_t)5)			/*Pin 5 Selected */
#define GPIO_PIN_6    ((uint16_t)6)			/*Pin 6 Selected */
#define GPIO_PIN_7    ((uint16_t)7)			/*Pin 7 Selected */
#define GPIO_PIN_8    ((uint16_t)8)			/*Pin 8 Selected */
#define GPIO_PIN_9    ((uint16_t)9)			/*Pin 9 Selected */
#define GPIO_PIN_10   ((uint16_t)10)		/*Pin 10 Selected */
#define GPIO_PIN_11   ((uint16_t)11)		/*Pin 11 Selected */
#define GPIO_PIN_12   ((uint16_t)12)		/*Pin 12 Selected */
#define GPIO_PIN_13   ((uint16_t)13)		/*Pin 13 Selected */
#define GPIO_PIN_14   ((uint16_t)14)		/*Pin 14 Selected */
#define GPIO_PIN_15   ((uint16_t)15)		/*Pin 15 Selected */
#define GPIO_PIN_ALL  (uint16_t)0xFFFF 		/*Pin ALL Selected */

#define GPIO_PIN_MASK  0x0000FFFFU     /*Pin Mask foe assert test*/



		/*****@ref GPIO_MODE*****/

//In input modes (MODE[1:0]=00)
#define GPIO_MODE_INPUT_ANALOG      0x00000000u		//00 Analog mode
#define GPIO_MODE_INPUT_FLOATING    0x00000001u		//01 Floating input (reset state)
#define GPIO_MODE_INPUT_PULLUP      0x00000002u		//10 Input with pull-up
#define GPIO_MODE_INPUT_PULLDOWN    0x00000002u		//10 Input with pull-down
#define GPIO_MODE_ALTERNATIVE_INPUT GPIO_MODE_INPUT_FLOATING

//In output mode (MODE[1:0]>00)
#define GPIO_MODE_OUTPUT_GENERAL_PUSHPULL      0x00000000u   //00 General purpose output push-pull
#define GPIO_MODE_OUTPUT_GENERAL_OPENDRAIN     0x00000001u   //01 General purpose output Open-drain
#define GPIO_MODE_OUTPUT_ALTERNATE_PUSHPULL    0x00000002u   //10 Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_ALTERNATE_OPENDRAIN   0x00000003u   //11 Alternate function output Open-drain



		/*****@ref GPIO_FREQ*****/

//MODEy[1:0]
#define GPIO_FREQ_IN      0x00000000u   //00 Input mode (reset state)
#define GPIO_FREQ_10MHZ   0x00000001u   //01 Output mode, max speed 10 MHz
#define GPIO_FREQ_2MHZ    0x00000002u   //10 Output mode, max speed 2 MHz
#define GPIO_FREQ_50MHZ   0x00000003u   //11 Output mode, max speed 50 MHz


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
void MCAL_GPIO_INIT_PIN(GPIO_T * GPIOx , GPIO_PinConfig_t * PIN);
//void MCAL_GPIO_INIT_PORT(GPIO_T * GPIOx ,GPIO_PortConfig_t *PORT_CONFIG);



/**================================================================
* @Fn - MCAL_GPIO_RESET
* @brief - PORT needed to be reset -> takes values included GENERIC MACROS  GPIO_RESET section in GPIO header
* @param[in] - portx
*/
void MCAL_GPIO_RESET(uint8_t GPIOx_RESET);



/**================================================================
* @Fn - MCAL_GPIO_READ_PIN
* @brief - Read a pin from portx
* @param[in] - portx
* @param[out] - Pin number in portx (the first parameter)
* @retval- 8 bit return value read from the pin (the second parameter)
*/
uint8_t MCAL_GPIO_READ_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER);



/**================================================================
* @Fn - MCAL_GPIO_READ_PORT
* @brief - Read the whole port
* @param[in] - portx
* @retval- 16 bit value read from portx
*/
uint16_t MCAL_GPIO_READ_PORT(GPIO_T * GPIOx);



/**================================================================
* @Fn - MCAL_GPIO_WRITE_PIN
* @brief - Write a value in a specific pin portx
* @param[in] - portx
* @param[in] - number of a specific pint in portx
* @param[out] - 8 bit value Written to pinx in portx
*/
void MCAL_GPIO_WRITE_PIN(GPIO_T * GPIOx , uint8_t PIN_NUMBER , uint8_t VAL);



/**================================================================
* @Fn - MCAL_GPIO_WRITE_PORT
* @brief - Write a value in the whole port
* @param[in] - portx
* @param[out] - 8 bit value Written to portx
*/
void MCAL_GPIO_WRITE_PORT(GPIO_T * GPIOx , uint16_t VAL);



/**================================================================
* @Fn - MCAL_GPIO_TOGGLE_PIN
* @brief - toggle a specific pin
* @param[in] - portx
* @param[in] - pin number
*/
void MCAL_GPIO_TOGGLE_PIN(GPIO_T * GPIOx , uint16_t PIN_NUMBER);



/**================================================================
* @Fn - MCAL_GPIO_LOCK_PIN
* @brief - lock the value of a specific pin
* @param[in] - portx
* @param[out] - pin number needed to be locked
* @retval - 8 bit value for lock
*/
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_T * GPIOx , uint16_t PIN_NUMBER);



//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

          /*********GPIO_RESET*********/
#define GPIO_REGISTER_SIZE  4

#define GPIOA_RESET  2
#define GPIOB_RESET  3
#define GPIOC_RESET  4
#define GPIOD_RESET  5
#define GPIOE_RESET  6
//#define GPIOA_RESET  2


#endif /* INC_GPIO_H_ */
