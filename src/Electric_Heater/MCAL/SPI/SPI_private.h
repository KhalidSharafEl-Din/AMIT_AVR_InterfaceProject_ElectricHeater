/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-30-2022                                  */
/*      Version : 0.1                                        */
/*      File    : SPI_private.h                              */
/*************************************************************/

#ifndef __USART_PRIVATE_H__
#define __USART_PRIVATE_H__

// Registers 
    #define SPDR   *((volatile u8*)0x2C)
    #define SPSR   *((volatile u8*)0x2B)
    #define SPCR   *((volatile u8*)0x2A)
    
// Bits 
    // SPCR 
    #define SPIE     7
    #define SPE      6
    #define DORD     5
    #define MSTR     4
    #define CPOL     3
    #define CPHA     2
    #define SPR1     1
    #define SPR0     0

    // SPCR 
    #define SPIF     7
    #define WCOL     6
    #define SPI2X    0


// Options 
    // SPI Node Mode 
        #define SPI_Node_MODE_SLAVE   0 
        #define SPI_Node_MODE_MASTER  1 

    // Data Order (MSB, LSB)
        #define SPI_DORD_MSB        0 
        #define SPI_DORD_LSB        1 

    // Clock Polarity 
        #define SPI_CPOL_LOW        0
        #define SPI_CPOL_HIGH       1
    
    // Clock Phase
        #define SPI_CPHA_LEADING    0
        #define SPI_CPHA_TRALLING   1

    // Speed (Freq Prescaler)
        #define SPI_PRESCALER_4     0
        #define SPI_PRESCALER_16    1
        #define SPI_PRESCALER_64    2
        #define SPI_PRESCALER_128   3
        //Double Speed
        #define SPI_PRESCALER_2     4
        #define SPI_PRESCALER_8     5
        #define SPI_PRESCALER_32    6
        #define SPI_PRESCALER_64D   7

    // Enable / Disable Intrrupts 
        #define SPI_OP_MODE_POLLING   0
        #define SPI_OP_MODE_INTERRUPT 1

    // Enable / Disable SPI 
        #define SPI_STATUS_DISABLE  0
        #define SPI_STATUS_ENABLE   1

#endif