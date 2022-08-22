/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : USART_private.h                            */
/*************************************************************/

#ifndef __USART_PRIVATE_H__
#define __USART_PRIVATE_H__

// Registers 
    #define UDR    *((volatile u8*)0x2C)
    #define UCSRA  *((volatile u8*)0x2B)
    #define UCSRB  *((volatile u8*)0x2A)
    #define UCSRC  *((volatile u8*)0x40)
    #define UBRRH  *((volatile u8*)0x40)
    #define UBRRL  *((volatile u8*)0x29)


// Bits 
    // UCSRA 
    #define RXC     7
    #define TXC     6
    #define UDRE    5
    #define FE      4
    #define DOR     3
    #define PE      2
    #define U2X     1
    #define MPCM    0

    // UCSRB 
    #define RXCIE   7
    #define TXCIE   6
    #define UDRIE   5
    #define RXE     4
    #define TXE     3
    #define UCSZ2   2
    #define RXB8    1
    #define TXB8    0

    // UCSRC 
    #define URSEL   7
    #define UMSEL   6
    #define UPM1    5
    #define UPM0    4
    #define USBS    3
    #define UCSZ1   2
    #define UCSZ0   1
    #define UCPOL   0


// Options 
    // Charachter Sizes 
    #define USART_CSZ_5BIT  0
    #define USART_CSZ_6BIT  1
    #define USART_CSZ_7BIT  2
    #define USART_CSZ_8BIT  3
    #define USART_CSZ_9BIT  7

    // Parity Types
    #define USART_PRAITY_DISAPLED 0
    #define USART_PRAITY_EVEN     2
    #define USART_PRAITY_ODD      3

    // STOP Bits 
    #define USART_STOP_1BIT       0
    #define USART_STOP_2BIT       1

    // Type of UART (TX, RX, BOTH)
    #define USART_TYPE_RX         0
    #define USART_TYPE_TX         1
    #define USART_TYPE_TXRX       2

    // Type of Sync (Async or Sync)
    #define USART_SYNCMODE_ASYNC  0
    #define USART_SYNCMODE_SYNC   1

    // Type Event trigger (polling, interrupt)
    #define USART_TRIGGER_POLLING      0
    #define USART_TRIGGER_INTERRUPT    1

    // Speed mode (Normal or Double)
    #define USART_SPEED_NORMAL         0
    #define USART_SPEED_DOUBLE         1

    // Baud Rate Selection (For 16MHZ)
    #define USART_BR_16M_2400       416
    #define USART_BR_16M_4800       207
    #define USART_BR_16M_9600       103
    #define USART_BR_16M_28800      34
    #define USART_BR_16M_576000     16
    #define USART_BR_16M_1152000    8





#endif