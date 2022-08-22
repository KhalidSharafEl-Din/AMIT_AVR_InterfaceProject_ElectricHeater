/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER2_interface.h                               */
/*************************************************************/


#ifndef __TIMER2_INTERFACE_H__
#define __TIMER2_INTERFACE_H__

#include "STD_TYPES.h"
#define F_CPU 16000000UL

void TIMER2_init();
void TIMER2_setMode(u8 mode);
void TIMER2_setTE(u8 timerEvent);
void TIMER2_setPrescaler(u8 prescaler);
void TIMER2_OV_enable();
void TIMER2_OV_disable();

void TIMER2_CTC_enable();
void TIMER2_CTC_disable();

void TIMER2_SetTimerCounter(u8 preload);
void TIMER2_SetCompare(u8 compare);

void TIMER2_SetOV_CallBack( void (*fun_ptr) (void));
void TIMER2_SetCTC_CallBack( void (*fun_ptr) (void));


#endif
