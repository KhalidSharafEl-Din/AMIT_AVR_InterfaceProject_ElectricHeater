/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER2_config.h                           */
/*************************************************************/


#ifndef __TIMER2_CONFIG_H__
#define __TIMER2_CONFIG_H__

// Options 

    // Select Timer Mode 
        /*Range
        TIMER2_NORMAL
        TIMER2_PHASE_PWM
        TIMER2_CTC
        TIMER2_FAST_PWM	
        */
       #define TIMER2_OP_MODE   TIMER2_FAST_PWM

    // Select Prescaler
        /*Range
        TIMER_2_PRESCALER_0       
        TIMER_2_PRESCALER_1			  
        TIMER_2_PRESCALER_8
        TIMER_2_PRESCALER_64 
        TIMER_2_PRESCALER_256	    
        TIMER_2_PRESCALER_1024	   
        TIMER_2_PRESCALER_ECS_FALL
        TIMER_2_PRESCALER_ECS_RISE
        */
       #define TIMER2_PRESCALER   TIMER_2_PRESCALER_1024

    // Timer Events (No Action, Toggle, Clear, Set)
        /*Range
        TIMER2_TE_NOEVENT
        TIMER2_TE_TOGGLE	
        TIMER2_TE_CLEAR		
        TIMER2_TE_SET	   
        */
       #define TIMER2_TE   TIMER2_TE_CLEAR
    
#endif