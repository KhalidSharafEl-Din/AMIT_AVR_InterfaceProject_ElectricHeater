/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER2_private.h                           */
/*************************************************************/


#ifndef __TIMER2_PRIVATE_H__
#define __TIMER2_PRIVATE_H__

// REGISTERS 
    // Common Regristers 
    #define SFIOR  *((volatile u8*)0x50)
    #define TIMSK  *((volatile u8*)0x59)
    #define TIFR   *((volatile u8*)0x58)
    
    // Timer 0
    #define TCCR2  *((volatile u8*)0x45)
    #define TCNT2  *((volatile u8*)0x44)
    #define OCR2   *((volatile u8*)0x43)


// BITS 
    // Common Registers 
        // SFIOR

        //TIMSK
            #define OCIE2   7   // Timer 2: Timer Output compare Interrupt Enable 
            #define TOIE2   6   // Timer 2: Timer Overflow Interrupt Enable 
            #define TICIE1  5
            #define OCIE1A  4
            #define OCIE1B  3
            #define TOIE1   2
            #define OCIE0   1   // Timer 0: Timer Output Compare Interrupt Enable 
            #define TOIE0   0   // Timer 0: Timer overflow Interrupt Enable
        //TIFR
            #define OCF2    7   // Timer 2: Output Compare flag
            #define TOV2    6   // Timer 2: Timer overflow flag
            #define ICF1    5
            #define OCF1A   4
            #define OCF1B   3
            #define TOV1    2
            #define OCF0    1   // Timer 0: Out Compare Flag  
            #define TOV0    0   // Timer 0: Timer overflow Flag 

    // Timer 2 
        // TCCR2
            #define FOC2    7   // Forced Compare Match 
            #define WGM20   6   // Waveform Generation Mode 
            #define COM21   5   // Compare Out Mode 
            #define COM20   4
            #define WGM21   3
            #define CS22    2   // CLock Select
            #define CS21    1
            #define CS20    0

// OPtions 
    // Timer Mode (Waver Form Generation Mode)
        #define TIMER2_NORMAL 		0
        #define TIMER2_PHASE_PWM 	1
        #define TIMER2_CTC 			2
        #define TIMER2_FAST_PWM     3

    // Prescaler
        #define TIMER_2_PRESCALER_0           0
        #define TIMER_2_PRESCALER_1			  1
        #define TIMER_2_PRESCALER_8			  2
        #define TIMER_2_PRESCALER_64		  3
        #define TIMER_2_PRESCALER_256	      4
        #define TIMER_2_PRESCALER_1024	      5
        #define TIMER_2_PRESCALER_ECS_FALL	  6
        #define TIMER_2_PRESCALER_ECS_RISE	  7

    // Timer Events (No Action, Toggle, Clear, Set)
        #define TIMER2_TE_NOEVENT 		0
        #define TIMER2_TE_TOGGLE	    1
        #define TIMER2_TE_CLEAR		    2
        #define TIMER2_TE_SET	        3

#endif