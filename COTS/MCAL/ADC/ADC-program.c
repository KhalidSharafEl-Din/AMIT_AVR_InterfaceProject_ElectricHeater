/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : ADC_program.h                              */
/*************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC-private.h"
#include "ADC-config.h"
#include "ADC-interface.h"


void ADC_init(void){
    ADC_vrefSelect(ADC_VREF);
    ADC_setReslution(ADC_RESLUTION);
    ADC_setPrescaler(ADC_PRESCALER);
	ADC_desaibleAutoTrigger();
    ADC_enable();
}

void ADC_enable(void)   {SET_BIT(ADCSRA, ADEN);}

void ADC_disalbe(void)  {CLEAR_BIT(ADCSRA, ADEN);}

void ADC_vrefSelect(u8 vrefSource){
    ADMUX &= 0b00111111;               // Clear Required Bits 
    ADMUX |= (vrefSource << 6);        // Set the new value 
}

void ADC_setReslution(u8 reslution){
    ADMUX &= 0b11011111;               // Clear Required Bits 
    ADMUX |= (reslution << 5);        // Set the new value 
}

void ADC_setPrescaler(u8 prescaler){
    ADCSRA &= 0b11111000;         // Clear Required Bits 
    ADCSRA |= (prescaler);        // Set the new value 
}

void ADC_enableAutoTrigger(u8 autoTriggerSource){
    SET_BIT(ADCSRA, ADATE);
    SFIOR &= 0b00001111;                       // Clear Required Bits 
    SFIOR |= ( autoTriggerSource << 5);        // Set the new value 
}
void ADC_desaibleAutoTrigger(){
    CLEAR_BIT(ADCSRA, ADATE);
}

void ADC_enableInterrupt(){
    SET_BIT(ADCSRA, ADIE);
}
void ADC_desabileInterrupt(){
    CLEAR_BIT(ADCSRA, ADIE);
}



#if ADC_RESLUTION == ADC_8BIT_RESELUTION
u8  ADC_analogRead(u8 Channel){
    // Select required channel 
    CLEAR_BIT(ADCSRA, ADSC);
    ADMUX &= 0b11100000;        // Clear Required Bits 
    ADMUX |= Channel;           // Set the new value
    // Start Conversion
    SET_BIT(ADCSRA, ADSC); 
    // Wait till conversion finish
    while ((CHECK_BIT(ADCSRA, ADSC)) == 1);
    return ADCH;
}
#elif ADC_RESLUTION == ADC_10BIT_RESELUTION
u16 ADC_analogRead10Bit(u8 Channel){
    // Select required channel 
	ADMUX &= 0b11100000;        // Clear Required Bits 
    ADMUX |= Channel;           // Set the new value
    // Start Conversion
    SET_BIT(ADCSRA, ADSC); 
    // Wait till conversion finish
    while ((CHECK_BIT(ADCSRA, ADSC)) == 1);
	u8 lowByte = ADCL;
	u8 highByte = ADCH;
    u16 result =  ((highByte & 0b00000011) << 8) | lowByte ;
	return result;
}
#endif


