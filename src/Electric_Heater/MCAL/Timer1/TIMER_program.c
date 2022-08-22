/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER_program.h                               */
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (*TIMER_0_OV_CallBack) (void) ;
void (*TIMER_0_CTC_CallBack) (void) ;

void (*TIMER_1_OV_CallBack) (void) ;
//void (*TIMER_0_CTC_CallBack) (void) ;

void (*TIMER_2_OV_CallBack) (void) ;
void (*TIMER_2_CTC_CallBack) (void) ;

void TIMER_init(u8 timer){
    // Select Opreation Mode 
    
    // Select Prescaler 
}


void TIMER_setMode(u8 timer, u8 mode){
    switch (timer){
        case 0: 
            switch (mode){
            case TIMER_NORMAL:
                CLEAR_BIT(TCCR0 , WGM00);
		        CLEAR_BIT(TCCR0 , WGM01);
                break;
            case TIMER_PHASE_PWM:
                SET_BIT  (TCCR0 , WGM00);
		        CLEAR_BIT(TCCR0 , WGM01);
            case TIMER_CTC:
                CLEAR_BIT(TCCR0 , WGM00);
		        SET_BIT  (TCCR0 , WGM01);
            case TIMER_FAST_PWM:
                SET_BIT  (TCCR0 , WGM00);
		        SET_BIT  (TCCR0 , WGM01);
            default: break;
            }  
                break;
        case 1:
                // TBI
                break;
        case 2:
                switch (mode){
            case TIMER_NORMAL:
                CLEAR_BIT(TCCR0 , WGM00);
		        CLEAR_BIT(TCCR0 , WGM01);
                break;
            case TIMER_PHASE_PWM:
                SET_BIT  (TCCR0 , WGM00);
		        CLEAR_BIT(TCCR0 , WGM01);
            case TIMER_CTC:
                CLEAR_BIT(TCCR0 , WGM00);
		        SET_BIT  (TCCR0 , WGM01);
            case TIMER_FAST_PWM:
                SET_BIT  (TCCR0 , WGM00);
		        SET_BIT  (TCCR0 , WGM01);
            default: break;
            }  
                break;
        default:break;
    }
     
}
void TIMER_setPrescaler(u8 timer, u8 prescaler){
    switch (timer){
        case 0: 
            TCCR0 &= 0b00000111;    // Clear Required Bits 
            TCCR0 |= prescaler;     // Set the new value 
            break;
        case 1:
            //TBI 
            break;
        case 2:
            TCCR2 &= 0b00000111;    // Clear Required Bits 
            TCCR2 |= prescaler;     // Set the new value 
            break;
        default:                     break;
    }
}

void TIMER_OV_enable(u8 timer){
    switch (timer){
        case 0: 
                SET_BIT(TIMSK,TOIE0);break;
        case 1:
                SET_BIT(TIMSK,TOIE1);break;
        case 2:
                SET_BIT(TIMSK,TOIE2);break;
        default:                     break;
    }
}
void TIMER_OV_disable(u8 timer){
    switch (timer){
        case 0: 
                CLEAR_BIT(TIMSK,TOIE0);break;
        case 1:
                CLEAR_BIT(TIMSK,TOIE1);break;
        case 2:
                CLEAR_BIT(TIMSK,TOIE2);break;
        default:                       break;
    }
}

void TIMER_CTC_enable(u8 timer){
    switch (timer){
        case 0: 
                SET_BIT(TIMSK,OCIE0);break;
        case 1:
                SET_BIT(TIMSK,OCIE1A);break;
        case 2:
                SET_BIT(TIMSK,OCIE2);break;
        default:                     break;
    }
}
void TIMER_CTC_disable(u8 timer){
    switch (timer){
        case 0: 
                CLEAR_BIT(TIMSK,OCIE0);break;
        case 1:
                CLEAR_BIT(TIMSK,OCIE1A);break;
        case 2:
                CLEAR_BIT(TIMSK,OCIE2);break;
        default:
            break;
    }
}

void TIMER_SetTimerCounter(u8 timer,u8 preload){
    switch (timer){
        case 0: 
                TCNT0 = preload; break;
        case 1:
                // TBI
                break;

        case 2:
                TCNT2 = preload; break;
        default:
            break;
    }
}



void TIMER_SetCompare(u8 timer, u8 compare){
    switch (timer){
        case 0: 
                OCR0 = compare; break;
        case 1:
                // TBI
                break;

        case 2:
                OCR2 = compare; break;
        default:
            break;
    }
}


void TIMER_SetOV_CallBack(u8 timer, void (*fun_ptr) (void)){
    switch (timer){
        case 0: 
                TIMER_0_OV_CallBack = fun_ptr;
                break;
        case 1:
                TIMER_1_OV_CallBack = fun_ptr;
                break;
        case 2:
                TIMER_2_OV_CallBack = fun_ptr;
                break;
        default:
            break;
    }
}

void TIMER_SetCTC_CallBack(u8 timer, void (*fun_ptr) (void)){
    switch (timer){
        case 0: 
                TIMER_0_CTC_CallBack = fun_ptr;
                break;
        case 1:
                // TBI
                break;
        case 2:
                TIMER_2_CTC_CallBack = fun_ptr;
                break;
        default:
            break;
    }
}

// TIMER 0
void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	TIMER_0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	TIMER_0_CTC_CallBack();
}


// TIMER 1
void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	TIMER_1_OV_CallBack();
}

// TIMER 2
void __vector_5(void) __attribute__((signal , used));
void __vector_5(void)
{
	TIMER_2_OV_CallBack();
}

void __vector_4(void) __attribute__((signal , used));
void __vector_4(void)
{
	TIMER_2_CTC_CallBack();
}





