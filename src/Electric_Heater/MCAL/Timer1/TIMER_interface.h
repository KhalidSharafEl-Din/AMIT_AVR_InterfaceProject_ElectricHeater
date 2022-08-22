/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER_interface.h                               */
/*************************************************************/


#ifndef __TIMER_INTERFACE_H__
#define __TIMER_INTERFACE_H__

#include "STD_TYPES.h"

#define TIMER_0     0
#define TIMER_1     1
#define TIMER_2     2



void TIMER_init(u8 timer);
void TIMER_setMode(u8 timer, u8 mode);
void TIMER_setPrescaler(u8 timer, u8 prescaler);
void TIMER_OV_enable(u8 timer);
void TIMER_OV_disable(u8 timer);

void TIMER_CTC_enable(u8 timer);
void TIMER_CTC_disable(u8 timer);

void TIMER_SetTimerCounter(u8 timer,u8 preload);
void TIMER_SetCompare(u8 timer, u8 compare);


void TIMER_SetOV_CallBack(u8 timer, void (*fun_ptr) (void));
void TIMER_SetCTC_CallBack(u8 timer, void (*fun_ptr) (void));





#endif
