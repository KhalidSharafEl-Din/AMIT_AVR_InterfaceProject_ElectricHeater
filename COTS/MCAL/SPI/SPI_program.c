/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : SPI_program.c                              */
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

void SPI_init(){
    // SPI  Node Mode 
        #if   SPI_NODE_MODE == SPI_NODE_MODE_MASTER
            SET_BIT(SPCR, MSTR);
        #elif SPI_NODE_MODE == SPI_NODE_MODE_MASTER
            CLEAR_BIT(SPCR, MSTR);
        #endif
    // Data Order (MSB, LSB)
        #if   SPI_DORD == SPI_DORD_LSB
            SET_BIT(SPCR, DORD);
        #elif SPI_DORD == SPI_DORD_MSB
            CLEAR_BIT(SPCR, DORD);
        #endif
    // Clock Polarity 
        #if   SPI_CPOL == SPI_CPOL_HIGH
            SET_BIT(SPCR, CPOL);
        #elif SPI_CPOL == SPI_CPOL_LOW
            CLEAR_BIT(SPCR, CPOL);
        #endif
    // Clock Phase
        #if   SPI_CPHA == SPI_CPHA_TRAILLING
            SET_BIT(SPCR, CPHA);
        #elif SPI_CPHA == SPI_CPHA_LEADING
            CLEAR_BIT(SPCR, CPHA);
        #endif

    // Speed (Freq Prescaler)
        #if  SPI_SPEED == SPI_PRESCALER_4
            CLEAR_BIT(SPCR, SPR0);
            CLEAR_BIT(SPCR, SPR1);
            CLEAR_BIT(SPSR, SPI2X);
        #elif SPI_SPEED == SPI_PRESCALER_16
            SET_BIT  (SPCR, SPR0);
            CLEAR_BIT(SPCR, SPR1);
            CLEAR_BIT(SPSR, SPI2X);
        #elif SPI_SPEED == SPI_PRESCALER_64
            CLEAR_BIT(SPCR, SPR0);
            SET_BIT  (SPCR, SPR1);
            CLEAR_BIT(SPSR, SPI2X); 
        #elif SPI_SPEED == SPI_PRESCALER_128
            SET_BIT  (SPCR, SPR0);
            SET_BIT  (SPCR, SPR1);
            CLEAR_BIT(SPSR, SPI2X);  
        #elif SPI_SPEED == SPI_PRESCALER_2
            CLEAR_BIT(SPCR, SPR1);
            CLEAR_BIT(SPCR, SPR0);
            SET_BIT  (SPSR, SPI2X);
        #elif SPI_SPEED == SPI_PRESCALER_8
            SET_BIT  (SPCR, SPR1);
            CLEAR_BIT(SPCR, SPR0);
            SET_BIT  (SPSR, SPI2X); 
        #elif SPI_SPEED == SPI_PRESCALER_32
            CLEAR_BIT(SPCR, SPR1);
            SET_BIT  (SPCR, SPR0);
            SET_BIT  (SPSR, SPI2X);
        #elif SPI_SPEED == SPI_PRESCALER_64D
            SET_BIT  (SPCR, SPR1);
            SET_BIT  (SPCR, SPR0);
            SET_BIT  (SPSR, SPI2X);
        #endif

    // Enable / Disable Intrrupts
        #if   SPI_OP_MODE == SPI_OP_MODE_INTERRUPT
            SET_BIT(SPCR, SPIE);
        #elif SPI_OP_MODE == SPI_OP_MODE_POLLING
            CLEAR_BIT(SPCR, SPIE);
        #endif

    // Enable / Disable SPI 
        #if  SPI_STATUS == SPI_STATUS_ENABLE
            SET_BIT(SPCR, SPE);
        #elif SPI_STATUS == SPI_STATUS_DISABLE
            CLEAR_BIT(SPCR, SPE);
        #endif

}

u8 SPI_u8DataTransfere(u8 Data){
    SPDR = Data;                        // Send data to be transfered  
    while(!(CHECK_BIT(SPSR, SPIF)));    // Wait till it's send 
    return SPDR;                        // Return the new byte recived

}