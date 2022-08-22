/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER2_program.h                               */
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"

void (*TIMER_2_OV_CallBack) (void) ;
void (*TIMER_2_CTC_CallBack) (void) ;

void TIMER2_init(){
    // Select Opreation Mode 
        TIMER2_setMode(TIMER2_OP_MODE);
    // Select Prescaler 
        TIMER2_setPrescaler(TIMER2_PRESCALER);
    // Timer Events (No Action, Toggle, Clear, Set)
        TIMER2_setTE(TIMER2_TE);
    // Interrupts 
        CLEAR_BIT(TIMSK, OCIE2);
        CLEAR_BIT(TIMSK, TOIE2);
    // Clearing Flags
        CLEAR_BIT(TIFR, OCF2); 
        CLEAR_BIT(TIFR, TOV2); 
    // Clear Registers 
        TCNT2 = 0; 
        OCR2 = 0;
}


void TIMER2_setMode(u8 mode){
   
    switch (mode){
		case TIMER2_NORMAL:
		CLEAR_BIT(TCCR2 , WGM20);
		CLEAR_BIT(TCCR2 , WGM21);
		break;
		case TIMER2_PHASE_PWM:
		SET_BIT  (TCCR2 , WGM20);
		CLEAR_BIT(TCCR2 , WGM21);
		break;
		case TIMER2_CTC:
		CLEAR_BIT(TCCR2 , WGM20);
		SET_BIT  (TCCR2 , WGM21);
		break;
		case TIMER2_FAST_PWM:
		SET_BIT  (TCCR2 , WGM20);
		SET_BIT  (TCCR2 , WGM21);
		break;
    default: break;
    }     
}

void TIMER2_setTE(u8 timerEvent){
   
    switch (timerEvent){
		case TIMER2_TE_NOEVENT:
		CLEAR_BIT(TCCR2 , COM20);
		CLEAR_BIT(TCCR2 , COM21);
		break;
		case TIMER2_TE_TOGGLE:
		SET_BIT  (TCCR2 , COM20);
		CLEAR_BIT(TCCR2 , COM21);
		break;
		case TIMER2_TE_CLEAR:
		CLEAR_BIT(TCCR2 , COM20);
		SET_BIT  (TCCR2 , COM21);
		break;
		case TIMER2_TE_SET:
		SET_BIT  (TCCR2 , COM20);
		SET_BIT  (TCCR2 , COM21);
		break;
		default: break;
    }     
}

void TIMER2_setPrescaler(u8 prescaler){
    TCCR2 &= 0b11111000;    // Clear Required Bits 
    TCCR2 |= prescaler;     // Set the new value 
       
}

void TIMER2_OV_enable(){ 
    SET_BIT(TIMSK,TOIE2);

}
void TIMER2_OV_disable(){
    CLEAR_BIT(TIMSK,TOIE2);
}

void TIMER2_CTC_enable(){
    SET_BIT(TIMSK,OCIE2);
}
void TIMER2_CTC_disable(){
     CLEAR_BIT(TIMSK,OCIE2);
}

void TIMER2_SetTimerCounter(u8 preload){
    TCNT2 = preload;
}


void TIMER2_SetCompare(u8 compare){
    OCR2 = compare;
}

void TIMER2_SetOV_CallBack(void (*fun_ptr) (void)){
    TIMER_2_OV_CallBack = fun_ptr;
}

void TIMER2_SetCTC_CallBack(void (*fun_ptr) (void)){
   
    TIMER_2_CTC_CallBack = fun_ptr;
}


void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	TIMER_2_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	TIMER_2_CTC_CallBack();
}





