/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : USART_config.h                             */
/*************************************************************/

#ifndef __USART_CONFIG_H__
#define __USART_CONFIG_H__

// Options 

    // Charachter Size Options
    /*  
        USART_CSZ_5BIT
        USART_CSZ_6BIT
        USART_CSZ_7BIT
        USART_CSZ_5BIT
        USART_CSZ_9BIT
    */
   #define USART_CSZ USART_CSZ_9BIT

    // Parity type Options
    /*  
        USART_PRAITY_DISAPLED
        USART_PRAITY_EVEN    
        USART_PRAITY_ODD
    */     
   #define USART_PARITY USART_PRAITY_DISAPLED

    // STOP Bits Options
    /*  
        USART_STOP_1BIT
        USART_STOP_2BIT 
    */
   #define USART_STOP USART_STOP_1BIT

    // USART Type (RX, TX, BOTH)
    /*  
        USART_TYPE_RX  
        USART_TYPE_TX  
        USART_TYPE_TXRX
    */
   #define USART_TYPE USART_TYPE_TXRX
   
    // USART Sync Mode (SYNC, ASYNC)
    /*  
        USART_SYNCMODE_ASYNC
        USART_SYNCMODE_SYNC 
    */
   #define USART_SYNCMODE  USART_SYNCMODE_ASYNC


    // USART Trigger Mode (Polling, Interrupt)
    /*  
        USART_TRIGGER_POLLING  
        USART_TRIGGER_INTERRUPT
    */
   #define USART_TRIGGER  USART_TRIGGER_POLLING


   // USART Speed Mode (Normal, Double)
    /*  
        USART_SPEED_NORMAL
        USART_SPEED_DOUBLE
    */
   #define USART_SPEED  USART_SPEED_NORMAL
  
   // USART Buad Rate  (@ 16 MHZ)
    /*  
        USART_BR_16M_2400   
        USART_BR_16M_4800   
        USART_BR_16M_9600   
        USART_BR_16M_28800  
        USART_BR_16M_576000 
        USART_BR_16M_1152000
    */
   #define USART_BAUDRATE USART_BR_16M_9600

#endif