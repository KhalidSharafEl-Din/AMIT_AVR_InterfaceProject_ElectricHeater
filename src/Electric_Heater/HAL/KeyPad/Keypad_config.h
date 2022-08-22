/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : KeyPad_config.h                            */
/*************************************************************/


#ifndef __KEYPAD_CONFIG_H__
#define __KEYPAD_CONFIG_H__

#include "DIO_interface.h"

#define KEYPAD_PORT     DIO_u8_PORTC

#define KEYPAD_ROW_1    DIO_u8_PIN0
#define KEYPAD_ROW_2    DIO_u8_PIN1
#define KEYPAD_ROW_3    DIO_u8_PIN2
#define KEYPAD_ROW_4    DIO_u8_PIN3


#define KEYPAD_COL_1    DIO_u8_PIN4
#define KEYPAD_COL_2    DIO_u8_PIN5
#define KEYPAD_COL_3    DIO_u8_PIN6
#define KEYPAD_COL_4    DIO_u8_PIN7


// KEYPAD Keys 
#define R1C1    '1'
#define R1C2    '2'
#define R1C3    '3'
#define R1C4    'A'

#define R2C1    '4'
#define R2C2    '5'
#define R2C3    '6'
#define R2C4    'B'

#define R3C1    '7'
#define R3C2    '8'
#define R3C3    '9'
#define R3C4    'C'


#define R4C1    '*'
#define R4C2    '0'
#define R4C3    '#'
#define R4C4    'D'



// KEYPAD_INTERNAL_PULL_UP or KEYPAD_EXTERNAL_PULL_UP

#define KEYPAD_MODE KEYPAD_INTERNAL_PULL_UP

#endif // __KEYPAD_CONFIG_H__