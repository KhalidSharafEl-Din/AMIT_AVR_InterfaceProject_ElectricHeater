/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-24-2022                                  */
/*      Version : 0.1                                        */
/*      File    : LCD_interface.h                            */
/*************************************************************/

#ifndef __LCD_INTERFACE_H__
#define __LCD_INTERFACE_H__
#include "LCD_config.h"
void LCD_Init(void);
void LCD_SendData(u8 Local_u8Data);
void LCD_SendCommand(u8 Local_u8Command);
void LCD_Clear(void);
void LCD_SendString(u8* Local_u8Data);
void LCD_ResetCursor(void);


void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(void);
void LCD_Puts(u8 x, u8 y, char* str);
void LCD_BlinkOn(void);
void LCD_BlinkOff(void);
void LCD_CursorOn(void);
void LCD_CursorOff(void);
void LCD_ScrollLeft(void);
void LCD_ScrollRight(void);
void LCD_CreateChar(u8 lcation, u8* data);
void LCD_PutCustom(u8, u8, u8);
void LCD_Put(u8 data);

void LCD_CursorSet(u8 col, u8 row);



#endif