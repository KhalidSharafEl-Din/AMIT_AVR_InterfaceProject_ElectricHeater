/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-24-2022                                  */
/*      Version : 0.1                                        */
/*      File    : LCD_config.h                               */
/*************************************************************/
#ifndef __LCD_CONFIG_H__
#define __LCD_CONFIG_H__

#define _LCD_COLS         16
#define _LCD_ROWS         2

#define LCD_u8_Rs_Port   DIO_u8_PIN1
#define LCD_u8_Rw_Port   DIO_u8_PIN2
#define LCD_u8_En_Port   DIO_u8_PIN3

#define LCD_u8_Rs_Pin     DIO_u8_PORTB
#define LCD_u8_Rw_Pin     DIO_u8_PORTB
#define LCD_u8_En_Pin     DIO_u8_PORTB

#define LCD_u8_DATA_PORT DIO_u8_PORTA

#define LCD_u8_D0_PORT   DIO_u8_PORTA
#define LCD_u8_D1_PORT   DIO_u8_PORTA
#define LCD_u8_D2_PORT   DIO_u8_PORTA
#define LCD_u8_D3_PORT   DIO_u8_PORTA
#define LCD_u8_D4_PORT   DIO_u8_PORTA
#define LCD_u8_D5_PORT   DIO_u8_PORTA
#define LCD_u8_D6_PORT   DIO_u8_PORTA
#define LCD_u8_D7_PORT   DIO_u8_PORTA

#define LCD_u8_D0_PIN   DIO_u8_PIN0
#define LCD_u8_D1_PIN   DIO_u8_PIN1
#define LCD_u8_D2_PIN   DIO_u8_PIN2
#define LCD_u8_D3_PIN   DIO_u8_PIN3
#define LCD_u8_D4_PIN   DIO_u8_PIN4
#define LCD_u8_D5_PIN   DIO_u8_PIN5
#define LCD_u8_D6_PIN   DIO_u8_PIN6
#define LCD_u8_D7_PIN   DIO_u8_PIN7

// LCD_u8_4BIT or LCD_u8_8BIT
#define LCD_u8_MODE     LCD_u8_4BIT

#endif