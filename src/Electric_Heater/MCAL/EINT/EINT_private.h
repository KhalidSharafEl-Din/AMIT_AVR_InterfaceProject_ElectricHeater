/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : EINT_private.h                              */
/*************************************************************/

// Functions prototypes and user defined macros 

#ifndef __EINT_PRIVATE_H__
#define __EINT_PRIVATE_H__


#define SREG    *((volatile u8*)0x5F)

// External interrupts registers 
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)
#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR  *((volatile u8*)0x54)


// Bits in MCUCR
#define ISC00 0 
#define ISC01 1 
#define ISC10 2 
#define ISC11 3

// Bits in MCUCSR
#define ISC2  6

// Bits in GICR
#define INT0     6
#define INT1     7
#define INT2     5

// Bits in GIFR
#define INTF0     6
#define INTF1     7
#define INTF2     5

#endif