/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : EINT_config.h                               */
/*************************************************************/

// Functions prototypes and user defined macros 

#ifndef __EINT_CONFIG_H__
#define __EINT_CONFIG_H__

// Enable of disable the interrupts 
#define EXT_INT_0_EN   ENABLE     
#define EXT_INT_1_EN   DISABLE
#define EXT_INT_2_EN   ENABLE

// Define Opertating mode 
#define EXT_INT_0_SC  FALLING_EDGE      
#define EXT_INT_1_SC  FALLING_EDGE
#define EXT_INT_2_SC  FALLING_EDGE


#endif