/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : ADC_interface.h                            */
/*************************************************************/

// Functions prototypes and user defined macros 

#ifndef __ADC_INTERFACE_H__
#define __ADC_INTERFACE_H__

#include "STD_TYPES.h"

void ADC_init(void);
void ADC_enable(void);
void ADC_disalbe(void);
void ADC_vrefSelect(u8 vrefSource);
void ADC_setReslution(u8 reslution);
void ADC_setPrescaler(u8 prescaler);
void ADC_enableAutoTrigger(u8 autoTriggerSource);
void ADC_desaibleAutoTrigger(void);
void ADC_enableInterrupt(void);
void ADC_desabileInterrupt(void);


#if ADC_RESLUTION == ADC_8BIT_RESELUTION
u8  ADC_analogRead(u8 Channel);
#elif ADC_RESLUTION == ADC_10BIT_RESELUTION
u16 ADC_analogRead10Bit(u8 Channel);
#endif

// ADC Resultion Options 
#define ADC_8BIT_RESELUTION     1
#define ADC_10BIT_RESELUTION    0

// Auto Trigger Options 
#define ADC_AT_FREERUNNING          0
#define ADC_AT_ANALOGCOMP           1
#define ADC_AT_EXINT_REQ_0          2
#define ADC_AT_TIMER_0_COMP         3
#define ADC_AT_TIMER_0_OV           4
#define ADC_AT_TIMER_1_COMP         5
#define ADC_AT_TIMER_1_OV           6
#define ADC_AT_TIMER_1_CAPEVENT     7

// Vref Options 
#define ADC_VREF_AREF       0
#define ADC_VREF_AVCC       1
#define ADC_VREF_INTERNAL   3

// Prescaler Options 
#define ADC_PRESCALER_2     1
#define ADC_PRESCALER_4     2
#define ADC_PRESCALER_8     3
#define ADC_PRESCALER_16    4
#define ADC_PRESCALER_32    5
#define ADC_PRESCALER_64    6
#define ADC_PRESCALER_128   7

#endif