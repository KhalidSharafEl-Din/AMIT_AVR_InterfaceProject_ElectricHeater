/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER_0_private.h                               */
/*************************************************************/


#ifndef __TIMER_0_PRIVATE_H__
#define __TIMER_0_PRIVATE_H__

// REGISTERS 
    // Common Regristers 
    #define SFIOR  *((volatile u8*)0x50)
    #define TIMSK  *((volatile u8*)0x59)
    #define TIFR   *((volatile u8*)0x58)
    
    // Timer 0
    #define OCR0   *((volatile u8*)0x5C)
    #define TCCR0  *((volatile u8*)0x53)
    #define TCNT0  *((volatile u8*)0x52)

    // Timer 1 
    #define TCCR1A *((volatile u8*)0x4F)
    #define TCCR1B *((volatile u8*)0x4E)
    #define TCNT1A *((volatile u8*)0x4D)
    #define TCNT1B *((volatile u8*)0x4C)
    #define OCR1AH *((volatile u8*)0x4B)
    #define OCR1AL *((volatile u8*)0x4A)
    #define OCR1BH *((volatile u8*)0x49)
    #define OCR1BL *((volatile u8*)0x48)
    #define ICR1H  *((volatile u8*)0x47)
    #define ICR1L  *((volatile u8*)0x46)
  
    // Timer 2 
    #define TCCR2  *((volatile u8*)0x45)
    #define TCNT2  *((volatile u8*)0x44)
    #define OCR2   *((volatile u8*)0x43)
    #define ASSR   *((volatile u8*)0x42)

// BITS 
    // Common Registers 
        // SFIOR

        //TIMSK
            #define OCIE2   7
            #define TOIE2   6
            #define TICIE1  5
            #define OCIE1A  4
            #define OCIE1B  3
            #define TOIE1   2
            #define OCIE0   1
            #define TOIE0   0
        //TIFR

    // Timer 0 
        // TCCR0
            #define FOC0    7   // Forced Compare Match 
            #define WGM00   6   // Waveform Generation Mode 
            #define COM01   5   // Compare Out Mode 
            #define COM00   4
            #define WGM01   3
            #define CS02    2   // CLock Select
            #define CS01    1
            #define CS00    0
    // Timer 1 
        // TCCR1A

        // TCCR1B

    // Timer 2
        // TCCR2
            #define FOC2    7
            #define WGM20   6
            #define COM21   5
            #define COM20   4
            #define WGM21   3
            #define CS22    2
            #define CS21    1
            #define CS20    0



#define TIMER_NORMAL 		0
#define TIMER_PHASE_PWM 	1
#define TIMER_CTC 			2
#define TIMER_FAST_PWM 	    3

#define TIMER_0_PRESCALER_0           0
#define TIMER_0_PRESCALER_1			  1
#define TIMER_0_PRESCALER_8			  2
#define TIMER_0_PRESCALER_64		  3
#define TIMER_0_PRESCALER_256	      4
#define TIMER_0_PRESCALER_1024	      5
#define TIMER_0_PRESCALER_ECS_FALL	  6
#define TIMER_0_PRESCALER_ECS_RISE	  7

#define TIMER_1_PRESCALER_0           0
#define TIMER_1_PRESCALER_1			  1
#define TIMER_1_PRESCALER_8			  2
#define TIMER_1_PRESCALER_64		  3
#define TIMER_1_PRESCALER_256	      4
#define TIMER_1_PRESCALER_1024	      5
#define TIMER_1_PRESCALER_ECS_FALL	  6
#define TIMER_1_PRESCALER_ECS_RISE	  7

#define TIMER_2_PRESCALER_0           0
#define TIMER_2_PRESCALER_1			  1
#define TIMER_2_PRESCALER_8			  2
#define TIMER_2_PRESCALER_32		  3
#define TIMER_2_PRESCALER_64	      4
#define TIMER_2_PRESCALER_128	      5
#define TIMER_2_PRESCALER_265    	  6
#define TIMER_2_PRESCALER_1024	      7

#endif