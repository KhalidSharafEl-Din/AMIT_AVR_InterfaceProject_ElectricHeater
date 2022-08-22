/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : USART_program.c                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"

void USART_init(void){
    // Data Length
        #if USART_CSZ == USART_CSZ_5BIT
            CLEAR_BIT(UCSRC,UCSZ0);
            CLEAR_BIT(UCSRC,UCSZ1);
            CLEAR_BIT(UCSRB,UCSZ2);
        #elif USART_CSZ == USART_CSZ_6BIT
            SET_BIT  (UCSRC,UCSZ0);
            CLEAR_BIT(UCSRC,UCSZ1);
            CLEAR_BIT(UCSRB,UCSZ2);
        #elif USART_CSZ == USART_CSZ_7BIT
            CLEAR_BIT(UCSRC,UCSZ0);
            SET_BIT  (UCSRC,UCSZ1);
            CLEAR_BIT(UCSRB,UCSZ2);
        #elif USART_CSZ == USART_CSZ_8BIT
            SET_BIT  (UCSRC,UCSZ0);
            SET_BIT  (UCSRC,UCSZ1);
            CLEAR_BIT(UCSRB,UCSZ2);
        #elif USART_CSZ == USART_CSZ_9BIT
            SET_BIT  (UCSRC,UCSZ0);
            SET_BIT  (UCSRC,UCSZ1);
            SET_BIT  (UCSRB,UCSZ2);
        #endif
    // Parity Type
        #if USART_PARITY == USART_PARITY_DISABLED
            CLEAR_BIT(UCSRC,UPM0);
            CLEAR_BIT(UCSRC,UPM1);
        #elif USART_PARITY == USART_PARITY_EVEN
            CLEAR_BIT(UCSRC,UPM0);
            SET_BIT  (UCSRC,UPM1);
        #elif USART_PARITY == USART_PARITY_ODD
            SET_BIT  (UCSRC,UPM0);
            SET_BIT  (UCSRC,UPM1);
        #endif
    // Number of stop Bits 
        #if USART_STOP == USART_STOP_1BBIT
            CLEAR_BIT(UCSRC,USBS);
        #elif USART_STOP == USART_STOP_2BIT
            SET_BIT  (UCSRC,USBS);
        #endif
    // Type of UART (TX, RX, BOTH)
        #if USART_TYPE == USART_TYPE_RX
            SET_BIT  (UCSRB,RXE);
            CLEAR_BIT(UCSRB,TXE);
        #elif USART_TYPE == USART_TYPE_TX
            SET_BIT  (UCSRB,TXE);
            CLEAR_BIT(UCSRB,RXE);
        #elif USART_TYPE == USART_TYPE_TXRX
            SET_BIT  (UCSRB,RXE);
            SET_BIT(UCSRB,TXE);
        #endif
    // Type of Sync (Async or Sync)
        #if USART_SYNCMODE == USART_SYNCMODE_ASYNC
            CLEAR_BIT(UCSRC,UMSEL);
        #elif USART_SYNCMODE == USART_SYNCMODE_SYNC
            SET_BIT  (UCSRC,UMSEL);
        #endif
    // Type of Event trigger (polling, interrupt)
        #if USART_TRIGGER == USART_TRIGGER_POLLING
            CLEAR_BIT(UCSRB,RXCIE);
            CLEAR_BIT(UCSRB,TXCIE);
            CLEAR_BIT(UCSRB,UDRIE);
        #elif USART_TRIGGER == USART_TRIGGER_INTERRUPT
            SET_BIT  (UCSRB,RXCIE);
            SET_BIT  (UCSRB,TXCIE);
            SET_BIT  (UCSRB,UDRIE);
        #endif
    // Speed mode (Normal or Double)
        #if USART_SYNCMODE == USART_SYNCMODE_ASYNC
            #if USART_SPEED == USART_SPEED_NORMAL
            CLEAR_BIT(UCSRA,U2X);
            #elif USART_SPEED == USART_SPEED_DOUBEL
            SET_BIT  (UCSRA,U2Xs);
            #endif
        #endif

    // Baud Rate Selection
        UBRRH = (USART_BAUDRATE < 8);
        UBRRL = USART_BAUDRATE;


}

void USART_sendByte(u8 Data){
    // Put the data into the buffer
    UDR = Data;
    // Wait for it to be sent
    while (!(CHECK_BIT(UCSRA, TXC)));
}
u8   USART_reciveByte(void){
    
    //wait for the data to be recieved  
    while (!(CHECK_BIT(UCSRA, RXC)));
    //Get Data
    return UDR;
}

u8 USART_getUDR(){
    return UDR;
}

void __vector_13(void) __attribute__((signal , used));
void __vector_13(void)
{
	//CallBackReceive();
}

void __vector_14(void) __attribute__((signal , used));
void __vector_14(void)
{
	//CallBackSend();
}


void USART_sendString(u8 * str){
	while(*str){
		USART_sendByte(*str++);
		CLEAR_BIT(UCSRA,DOR);
	}
}
void USART_reciveString(u8* restr, int len){
	u8 J=0, i=0;
	do{
		*(restr+i)= USART_reciveByte();
		J = *(restr+i);
		i++;
	}while((J!='\n') && (J!='\r'));
	i++;
	*(restr+i) = '\0';
}

