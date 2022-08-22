/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-18-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : DIO_interface.h                            */
/*************************************************************/

// Functions prototypes and user defined macros 

#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__


#define DIO_u8_OUTPUT    1 
#define DIO_u8_INPUT     0

#define DIO_u8_HIGH    1 
#define DIO_u8_LOW     0


#define DIO_u8_PIN0  0
#define DIO_u8_PIN1  1
#define DIO_u8_PIN2  2
#define DIO_u8_PIN3  3
#define DIO_u8_PIN4  4
#define DIO_u8_PIN5  5
#define DIO_u8_PIN6  6
#define DIO_u8_PIN7  7

#define DIO_u8_PORTA   5
#define DIO_u8_PORTB   6
#define DIO_u8_PORTC   7
#define DIO_u8_PORTD   8

void DIO_VoidInit(void);
void DIO_VoidSetPinValue(u8 DIO_u8Port, u8 DIO_u8Pin, u8 DIO_u8Val);
void DIO_VoidSetPortValue(u8 DIO_u8_PORT, u8 DIO_u8Val);
u8   DIO_u8GetPinValue(u8 DIO_u8Port, u8 DIO_u8Pin);

#endif