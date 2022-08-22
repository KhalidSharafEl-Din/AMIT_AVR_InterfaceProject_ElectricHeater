/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-30-2022                                  */
/*      Version : 0.1                                        */
/*      File    : SPI_interface.h                            */
/*************************************************************/

#ifndef __USART_INTERFACE_H__
#define __USART_INTERFACE_H__

// Options 
    // SPI Node Mode 
    /* 
        SPI_Node_MODE_SLAVE   0 
        SPI_Node_MODE_MASTER  1 
    */
    #define SPI_Node_MODE SPI_Node_MODE_SLAVE 

    // Data Order (MSB, LSB)
    /* 
        SPI_DORD_MSB        0 
        SPI_DORD_LSB        1 
    */
    #define SPI_DORD SPI_DORD_LSB 


    // Clock Polarity 
    /* 
        SPI_CPOL_LOW        0
        SPI_CPOL_HIGH       1
    */
    #define SPI_CPOL SPI_CPOL_LOW

    // Clock Phase
    /*
        SPI_CPHA_LEADING    0
        SPI_CPHA_TRALLING   1
    */
    #define SPI_CPHA SPI_CPHA_LEADING

    // Speed (Freq Prescaler)
    /*   SPI_PRESCALER_4     0
         SPI_PRESCALER_16    1
         SPI_PRESCALER_64    2
         SPI_PRESCALER_128   3
      //Double Speed
         SPI_PRESCALER_2     4
         SPI_PRESCALER_8     5
         SPI_PRESCALER_32    6
         SPI_PRESCALER_64D   7
    */
    #define SPI_PRESCALER SPI_PRESCALER_4
    
    // Enable / Disable Intrrupts 
    /* 
        SPI_OP_MODE_POLLING   0
        SPI_OP_MODE_INTERRUPT 1
    */
    #define SPI_OP_MODE SPI_OP_MODE_POLLING

    // Enable / Disable SPI 
    /* 
        SPI_STATUS_DISABLE  0
        SPI_STATUS_ENABLE   1
    */
    #define SPI_STATUS SPI_STATUS_ENABLE
    
#endif