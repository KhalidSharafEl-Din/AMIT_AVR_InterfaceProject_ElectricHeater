/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-24-2022                                  */
/*      Version : 0.1                                        */
/*      File    : LCD_prog.c                                 */
/*************************************************************/
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "util/delay.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_Praivate.h"

#include "DIO_interface.h"
#include "DIO_config.h"


#if LCD_u8_MODE == LCD_u8_8BIT
void LCD_Init(void){
    // initialization of hardware 
    _delay_ms(35);
    LCD_voidSendCommand(0b00111000);			// SetFunction Command : DB7,DB6,DB5 >> 001, DB4 >> 8-bit Mode, DB3 >> 2 lines,  DB2 >> 5x8 Dots
    _delay_ms(1);
    LCD_voidSendCommand(0b00001111);			// Display Control Command : DB7-DB3 >> 00001, DB2 >> Display On, DB1 >> Curser On, DB0 >> Blink On 
    _delay_ms(1);
    LCD_voidSendCommand(0b00000001);            // Clear Command 
    _delay_ms(2);
    LCD_voidSendCommand(0b00000110);            // Entry Mode Set : DB7-DB2 >> 000001, DB1 >> Increase, DB0 >> Cursuor OFF
}

 void LCD_SendData(u8 Local_u8Data){
    // RS -> HIGH
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
    // RW -> LOW
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
    // Write command 
    DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8Data);
    // enable pules 
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
    _delay_ms(1);
}

 void LCD_voidSendCommand(u8 Local_u8Command){
    // RS -> LOW
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
    // RW -> LOW
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
    // Write command
    DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8Command);
    // enable pules
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
    _delay_ms(1);

}
#elif LCD_u8_MODE == LCD_u8_4BIT
void LCD_Init(void){
    // initialization of hardware 
    _delay_ms(35);
	LCD_SendCommand(0b00110011);			// Set Funtion for 4 bit operation 
	LCD_SendCommand(0b00110010);
	
    LCD_SendCommand(0b00101000);			// SetFunction Command : DB7,DB6,DB5 >> 001, DB4 >> 4-bit Mode, DB3 >> 2 lines,  DB2 >> 5x8 Dots
    _delay_ms(1);
    LCD_SendCommand(0b00001100);			// Display Control Command : DB7-DB3 >> 00001, DB2 >> Display On, DB1 >> Curser off, DB0 >> Blink off
    _delay_ms(1);
    LCD_SendCommand(0b00000001);            // Clear Command
    _delay_ms(2);
    LCD_SendCommand(0b00000110);            // Entry Mode Set : DB7-DB2 >> 000001, DB1 >> Increase, DB0 >> Cursuor OFF
// 	
// 	_delay_ms(35);
//     LCD_SendCommand(0x33);														[0011 0011]
//     _delay_ms(1);
//     LCD_SendCommand(0x32);				// Send For 4 bit init of LCD			[0011 0010]
//     _delay_ms(1);
//     LCD_SendCommand(0x28);				// 2 lines, 5*7 matrix in 4 bit mode	[0010 1000]
//     _delay_ms(2);
//     LCD_SendCommand(0x0c);				// Display on cursor off				[0000 1100]
//     _delay_ms(2);
//     LCD_SendCommand(0x06);				// Increment Cursor shift lift			[0000 0110]
//     _delay_ms(2);
//     LCD_SendCommand(0x01);				// Clear Screen							[0000 0001]
}


void LCD_SendData(u8 Local_u8Data){
	u8 Local_u8_Temp;
	// RS -> HIGH
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
	// RW -> LOW
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
	
	// Write command  HIGH Nibble
	Local_u8_Temp = Local_u8Data & 0xF0;
	DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8_Temp);
	// enable pules
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
	_delay_ms(1);
	

	// Write command  LOW Nibble
	Local_u8_Temp = Local_u8Data << 4;
	DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8_Temp);
	// enable pules
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
	_delay_ms(1);
}


void LCD_SendCommand(u8 Local_u8Command){
	u8 Local_u8_Temp;
	// RS -> LOW
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
	// RW -> LOW
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
	
	// Write command  HIGH Nibble
	Local_u8_Temp = Local_u8Command & 0xF0;
	DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8_Temp);
	// enable pules
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
	_delay_ms(1);
	

	// Write command  LOW Nibble
	Local_u8_Temp = Local_u8Command << 4;
	DIO_VoidSetPortValue(DIO_u8_PORTA, Local_u8_Temp);
	// enable pules
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
	_delay_ms(1);

}
#endif

void LCD_SendString(u8* Local_u8Data){
    u8 Local_u8Index =0;
    while( Local_u8Data[Local_u8Index] != '\0'){
        LCD_SendData(Local_u8Data[Local_u8Index]);
        Local_u8Index++;
    }
}

void LCD_Clear(void){
    LCD_SendCommand(LCD_CLEARDISPLAY);
	_delay_ms(5);
}

void LCD_Puts(u8 x, u8 y, char* str){
	LCD_CursorSet(x, y);
	while (*str){
		if(LCD_Opts.currentX >= _LCD_COLS){
			LCD_Opts.currentX = 0;
			LCD_Opts.currentY++;
			LCD_CursorSet(LCD_Opts.currentX, LCD_Opts.currentY);
		}
		
		if(*str == '\n'){
			LCD_Opts.currentY++;
			LCD_CursorSet(LCD_Opts.currentX, LCD_Opts.currentY);
		}else if ( *str == '\r'){
			LCD_CursorSet(0, LCD_Opts.currentY);
		}else{
			LCD_SendData(*str);
			LCD_Opts.currentX++;
		}
		str++;
	}
}

//############################################################
// Display Control Functions 
void LCD_DisplayOn(){
	
	LCD_Opts.DisplayControl |= LCD_DISPLAYON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);		
}
	
void LCD_DisplayOff(){
	
	LCD_Opts.DisplayControl |= ~LCD_DISPLAYON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);
}

void LCD_BlinkOn(){
	
	LCD_Opts.DisplayControl |= LCD_BLINKON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);
}

void LCD_BlinkOff(){
	
	LCD_Opts.DisplayControl |= ~LCD_BLINKON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);
}

void LCD_CursorOn(){
	
	LCD_Opts.DisplayControl |= LCD_CURSORON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);
}

void LCD_CursorOff(){
	
	LCD_Opts.DisplayControl |= ~LCD_CURSORON;
	LCD_SendCommand(LCD_DISPLAYCONTROL | LCD_Opts.DisplayControl);
}

//############################################################
// Display Cursor Shift 
void LCD_ScrollLeft(){
	LCD_SendCommand(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

void LCD_ScrollRight(){
	LCD_SendCommand(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

//############################################################
void LCD_CreateChar(u8 location, u8* data){
	u8 i; 
	location &= 0x07;
	LCD_SendCommand(LCD_SETCGRAMADDR | (location << 3));
	for(i = 0; i < 8; i++){
		LCD_Put(data[i]);
	}
}

void LCD_PutCustom(u8 x, u8 y, u8 location){
	
	LCD_CursorSet(x, y);
	LCD_SendData(location);
}


void LCD_CursorSet(u8 col, u8 row){
	u8 row_offsets[] = {0x00, 0x40, 0x14, 0x54};
		if ( row >= _LCD_ROWS)
			{row = 0;} 
	LCD_Opts.currentX = col;  
	LCD_Opts.currentY = row;
	LCD_SendCommand(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void LCD_Put(u8 Data){
	LCD_SendData(Data);
}