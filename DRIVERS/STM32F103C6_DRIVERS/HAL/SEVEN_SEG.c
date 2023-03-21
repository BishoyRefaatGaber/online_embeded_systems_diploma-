/*
 * SEVEN_SEG.c
 *
 * Created: 2/6/2023 4:11:34 PM
 * Author : Bishoy Refaat
 */

//      |-----------------------------------------------|
//      |===================Includes====================|
//      |-----------------------------------------------|
#include "SEVEN_SEG.h"




//      |-----------------------------------------------|
//      |=============GENERIC VARIABLES=================|
//      |-----------------------------------------------|


//                             0      1      2      3      4      5      6      7      8      9
volatile uint8_t SEG [10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F }; //7SEG values



//      |------------------------------------------------------------------|
//      |=============APIs Supported by "MCAL GPIO DRIVER"=================|
//      |------------------------------------------------------------------|

void SEVEN_SEG_Display_NUM(uint8_t NUM){
    uint8_t _1st;
    uint8_t _2nd;

    _2nd = NUM / 10;
    _1st = NUM - 10 * _2nd;

    int i;
    for (i = 0 ; i < 15 ; i++){
    SEVEN_SEG_CONTROL = (SEVEN_SEG_CONTROL & ~(0b11 << SEVEN_SEG_CONTROL_SHIFT)) | (0b01 << SEVEN_SEG_CONTROL_SHIFT);
    SEVEN_SEG_OUT = (SEVEN_SEG_OUT & ~(0x7F << SEVEN_SEG_OUT_SHIFT)) | (SEG[_1st] << SEVEN_SEG_OUT_SHIFT);
//    SEVEN_SEG_CONTROL = (SEVEN_SEG_CONTROL & ~(0b11 << SEVEN_SEG_CONTROL_SHIFT)) | (0b10 << SEVEN_SEG_CONTROL_SHIFT);
//    SEVEN_SEG_OUT = (SEVEN_SEG_OUT & ~(0x7F << SEVEN_SEG_OUT_SHIFT)) | (SEG[_2nd] << SEVEN_SEG_OUT_SHIFT);
    }
}
