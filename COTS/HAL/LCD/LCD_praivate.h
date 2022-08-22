/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-24-2022                                  */
/*      Version : 0.1                                        */
/*      File    : LCD_private.h                               */
/*************************************************************/
#ifndef __LCD_PRIVATE_H__
#define __LCD_PRIVATE_H__
//#############################################################
typedef struct {
	u8 DisplayControl;
	u8 DisplayFunction;
	u8 DisplayMode;
	u8 currentX;
	u8 currentY;
}LCD_Options;

//############################################################
// Private Functions
// static void LCD_SendData(u8 Local_u8Data);
// static void LCD_SendCommand(u8 Local_u8Command);

//############################################################
// Private Variable
static LCD_Options LCD_Opts;
//############################################################
// Commands 
#define LCD_CLEARDISPLAY		0X01
#define LCD_RETURNHOME          0x02
#define LCD_ENTRYMODESET        0x04
#define LCD_DISPLAYCONTROL      0x08
#define LCD_CURSORSHIFT         0x10
#define LCD_FUNCTIONSET         0x20
#define LCD_SETCGRAMADDR        0x40
#define LCD_SETDDRAMADDR        0x80
//############################################################
// Flags for display entry mode 
#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00
//############################################################
// Flags for display on/offf control 
#define LCD_DISPLAYON           0x04
#define LCD_CURSORON            0x02
#define LCD_BLINKON             0x01
//############################################################
// Flags for display/cursor shift
#define LCD_DISPLAYMOVE         0x08
#define LCD_CURSORMOVE          0x00
#define LCD_MOVERIGHT           0x04
#define LCD_MOVELEFT            0x00
//############################################################
// Flags for for function set 
#define LCD_8BITMODE            0x10
#define LCD_4BITMODE            0x00
#define LCD_2LINE               0x08
#define LCD_1LINE               0x00
#define LCD_5x10DOTS            0x04
#define LCD_5x8DOTS             0x00


#define LCD_u8_4BIT 4
#define LCD_u8_8BIT 8

#endif