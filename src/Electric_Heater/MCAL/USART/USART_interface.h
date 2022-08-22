/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : USART_interface.h                          */
/*************************************************************/

#ifndef __USART_INTERFACE_H__
#define __USART_INTERFACE_H__

#include "STD_TYPES.h"

void USART_init(void);

void USART_sendByte(u8 Data);
u8   USART_reciveByte(void);

void USART_sendString(char* str);
void USART_reciveString(char* restr, int len);

u8 USART_getUDR();

void USART_void_SetCBReceive( void (*ptr) (void) );
void USART_void_SetCBSend( void (*ptr) (void) );

#endif