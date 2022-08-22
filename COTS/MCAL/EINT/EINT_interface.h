/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : INT_interface.h                            */
/*************************************************************/

// Functions prototypes and user defined macros 

#ifndef __INT_INTERFACE_H__
#define __INT_INTERFACE_H__



#define EXT_INT_0   0
#define EXT_INT_1   1
#define EXT_INT_2   2

#define LOW_LEVEL       0
#define LOGICAL_CHANGE  1
#define FALLING_EDGE    2
#define RISING_EDGE     3

#define ENABLE  1
#define DISABLE 0

void INT_init(void);
void INT_enbaleInterrupt(u8 intPin);
void INT_disableInterrupt(u8 intPin);
void INT_SenseControlMode(u8 intPin, u8 SenseControlMode);
void INT_clearFlag(u8 intPin);


#endif