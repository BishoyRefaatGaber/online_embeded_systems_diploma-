/*
 * MAX7221.h
 *
 * Created: 3/18/2023 1:02:24 AM
 *  Author: Bishoy Refaat
 */ 


#ifndef MAX7221_H_
#define MAX7221_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|


#include "ATMEGA32.h"
#include "GPIO.h"
#include "SPI.h"

//		|-----------------------------------------------|
//		|======User Type Definitions (structures)=======|
//		|-----------------------------------------------|


typedef struct 
{
	uint8_t Initial_PowerUp;	//Defines if the MAX7221  in the shutdown mode or the normal operation
					//Specified @ref Initial_PowerUp_define
	
	uint8_t DECODE_MODE;	//Specifies the number of digits needed to be decoded
							//Specified @ref DECODE_MODE_deine
	
	uint8_t Intensity_MODE;	//Specifies the the intensity of the display
							//Specified @ref Intensity_MODE_deine
	
	uint8_t Scan_Limit;		//Specifies the number of digits needed to be displayed
							//Specified @ref Scan_Limit_deine
	
}MAX7221_CFG_t;


//		|------------------------------------------------------------------|
//		|=================Macros Configuration References==================|
//		|------------------------------------------------------------------|

#define Digit0_add		0x1
#define Digit1_add		0x2
#define Digit2_add		0x3
#define Digit3_add		0x4
#define Digit4_add		0x5
#define Digit5_add		0x6
#define Digit6_add		0x7
#define Digit7_add		0x8
#define DecodeMode_add	0x9
#define Intensity_add	0xA
#define ScanLimit_add	0xB
#define Shutdown_add	0xC
#define DisplayTest_add	0xF



		//***********************@ref Initial_PowerUp_define***********************

#define Initial_PowerUp_ShutdownMode 0
#define Initial_PowerUp_NormalOperation 1


		//***********************@ref DECODE_MODE_deine***********************
#define DECODE_MODE_NoDecode	0
#define DECODE_MODE_CodeB_0		0x01
#define DECODE_MODE_CodeB_0_3	0x0F
#define DECODE_MODE_CodeB_0_7	0xFF


		//***********************@ref Intensity_MODE_deine***********************

#define Intensity_MODE_1by16  	0x00
#define Intensity_MODE_2by16  	0x01
#define Intensity_MODE_3by16 	0x02
#define Intensity_MODE_4by16 	0x03
#define Intensity_MODE_5by16 	0x04
#define Intensity_MODE_6by16 	0x05
#define Intensity_MODE_7by16 	0x06
#define Intensity_MODE_8by16 	0x07
#define Intensity_MODE_9by16 	0x08
#define Intensity_MODE_10by16 	0x09
#define Intensity_MODE_11by16 	0x0A
#define Intensity_MODE_12by16 	0x0B
#define Intensity_MODE_13by16 	0x0C
#define Intensity_MODE_14by16 	0x0D
#define Intensity_MODE_15by16 	0x0E
#define Intensity_MODE_16by16 	0x0F

		//***********************@ref Scan_Limit_deine***********************

#define ScanLimitReg_0ONLY	0x00
#define ScanLimitReg_0_1	0x01
#define ScanLimitReg_0_2	0x02
#define ScanLimitReg_0_3	0x03
#define ScanLimitReg_0_4	0x04
#define ScanLimitReg_0_5	0x05
#define ScanLimitReg_0_6	0x06
#define ScanLimitReg_0_7	0x07




//_____________________________

#define DP 1
#define Zero_DR		0
#define One_DR		1
#define Two_DR		2
#define Three_DR	3
#define Four_DR		4
#define Five_DR		5
#define Six_DR		6
#define Seven_DR	7
#define Eight_DR	8
#define Nine_DR		9
#define ___DR		10
#define E_DR 		11
#define H_DR		12
#define L_DR 		13
#define P_DR 		14
#define blank_DR 	15


#define Zero_SR 	0x3F
#define One_SR  	6
#define Two_SR  	5B
#define Three_SR 	4F
#define Four_SR 	66
#define Five_SR 	6D
#define Six_SR  	7D
#define Seven_SR 	7
#define Eight_SR  	7F
#define Nine_SR 	6F
#define ___SR 		80
#define E_SR 		79
#define H_SR  		76
#define L_SR  		38
#define P_SR  		73
#define blank_SR  	0


//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|


void MAX7221_WriteCommand(uint8_t address , uint8_t data , SPI_CFG_t * spicfg);
void MAX7221_INIT(MAX7221_CFG_t *max7221cfg ,SPI_CFG_t * spicfg);
void MAX7221_DISP (uint8_t address , uint8_t data);


#endif /* MAX7221_H_ */