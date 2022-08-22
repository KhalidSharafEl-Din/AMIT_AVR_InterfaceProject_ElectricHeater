/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-03-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : GIE_private.h                              */
/*************************************************************/
#ifndef __GIE_PRIVATE_H__
#define __GIE_PRIVATE_H__

// Defien the SREG Register address
#define SREG *((volatile u8*) 0x5F)

// the bit of GIE
#define GIE 7

#endif