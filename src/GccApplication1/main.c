/*
 * ElectricHeater.c
 *
 * Created: 30/06/2022 06:29:35 
 * Author : Mahmoud Moheb
 */ 

#define  F_CPU 1000000UL
#include <stdlib.h>
#include "Services/STD_types.h"
#include "Services/BIT_MATH.h"
#include "DIO.H"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/TIMER0/TIMER0_int.h"
#include "MCAL/GIE/GIE_int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/EEPROM/EEPROM_int.h"
#include <util/delay.h>
  
  
int i=0,l=0,flag=0,flagg=0;
int EXTI_flag = 0,EXTI2_flag = 1;
unsigned short int ADC_val;
float currenttemperature=0.0;
float desiredtemperature=60.0;
char arr1[1];
int j=0,K=0;

void EXTI0_ISR (void)
{
	Lable0:
	if(desiredtemperature<75.0 && EXTI_flag == 1)
	{
		desiredtemperature += 5.0;
	}
	itoa((int)desiredtemperature,arr1,10); //function used to convert int data type to array of characters
	EEPROM_write(0,arr1[0]);
	EEPROM_write(1,arr1[1]);
	flag=1;
	EEPROM_write(20,'1');
	flag = EEPROM_read(20)-'0';
	flagg = EEPROM_read(30)-'0';
	while(PIND & (1<<2));
	for(j=0;j<=8;j++)
	{
			EXTI_flag = 1;
			for(K=0;K<=12;K++)
			{
				if(PIND & (1<<2))
				{
					goto Lable0;
				}
				PORTD &=~ (1<<0);
				PORTD |= (1<<1);
				PORTC = arr1[0]-'0';
				_delay_ms(10);
				PORTC = arr1[1]-'0';
				PORTD &=~ (1<<1);
				PORTD &=~ (1<<0);
				_delay_ms(10);
			}
			for(K=0;K<=12;K++)
			{	
				if(PIND & (1<<2))
				{
					goto Lable0;
				}
				PORTD |= (1<<0);
				PORTD |= (1<<1);
				PORTC = arr1[0]-'0';
				_delay_ms(10);
				PORTC = arr1[1]-'0';
				PORTD |= (1<<1);
				PORTD |= (1<<0);
				_delay_ms(10);
			}
			EXTI_flag = 0;
	}
}

void EXTI1_ISR (void)
{
	Lable1:
	if(desiredtemperature>35.0 && EXTI_flag == 1)
	{
		desiredtemperature -= 5.0;
	}
	itoa((int)desiredtemperature,arr1,10); //function used to convert int data type to array of characters
	EEPROM_write(0,arr1[0]);
	EEPROM_write(1,arr1[1]);
	flag=1;
	EEPROM_write(20,'1');
	flag = EEPROM_read(20)-'0';
	flagg = EEPROM_read(30)-'0';
	while(PIND & (1<<3));
	for(j=0;j<=8;j++)
	{
		EXTI_flag = 1;
		for(K=0;K<=12;K++)
		{
			if(PIND & (1<<3))
			{
				goto Lable1;
			}
			PORTD &=~ (1<<0);
			PORTD |= (1<<1);
			PORTC = arr1[0]-'0';
			_delay_ms(10);
			PORTC = arr1[1]-'0';
			PORTD &=~ (1<<1);
			PORTD &=~ (1<<0);
			_delay_ms(10);
		}
		for(K=0;K<=12;K++)
		{
			if(PIND & (1<<3))
			{
				goto Lable1;
			}
			PORTD |= (1<<0);
			PORTD |= (1<<1);
			PORTC = arr1[0]-'0';
			_delay_ms(10);
			PORTC = arr1[1]-'0';
			PORTD |= (1<<1);
			PORTD |= (1<<0);
			_delay_ms(10);
		}
		EXTI_flag = 0;
	}
	
}

void EXTI2_ISR (void){
	if(EXTI2_flag == 1){
		
		while(PINB & (1<<2)){}
		EXTI2_flag = 0;
		
	} else {
		EXTI2_flag = 1;
	}	
}


void T0_ISR (void)
{
	i++;
	l++;
	TIMER0_SetTimerCounter(246);
	if(i==10)
	{
		ADC_val = ADC_read('0');
		currenttemperature = (((float)ADC_val * 5.0)/1023.0)/0.01;
		i=0;
	}
}


int main(void)
{
	DDRB &=~ (1<<2);
	DDRC=0b00001111;
	DDRD=0b01110011;
	char arr0[1];
	ADC_init();
	TIMER0_SetOV_CallBack(T0_ISR);
	TIMER0_init();
	TIMER0_SetTimerCounter(246);
	TIMER0_OV_enable();
	EXTI0_Set_CallBack(EXTI0_ISR);
	EXTI0_voidInit();
	EXTI0_voidEnable();
	EXTI1_Set_CallBack(EXTI1_ISR);
	EXTI1_voidInit();
	EXTI1_voidEnable();
	EXTI2_Set_CallBack(EXTI2_ISR);
	EXTI2_voidInit();
	EXTI2_voidEnable();
	GIE_voidEnable();
	_delay_ms(150);
	if((int)currenttemperature<36)
	{
		itoa((int)desiredtemperature,arr1,10); //function used to convert int data type to array of characters
		EEPROM_write(0,arr1[0]);
		EEPROM_write(1,arr1[1]);
	}
	arr1[0] = EEPROM_read(0);
	arr1[1] = EEPROM_read(1);
	desiredtemperature=atof(arr1);
	while (1)
	{		
		if(EXTI2_flag == 0)
		{
			PORTD |=  (1<<0);
			PORTD |=  (1<<1);
			PORTD &=~ (1<<4);
			PORTD &=~ (1<<5);
			PORTD &=~ (1<<6);
		}
		else
		{
			if((int)currenttemperature>35)
			{
				flag = EEPROM_read(20)-'0';
				flagg = EEPROM_read(30)-'0';
			}
			if(flag==1)
			{
				//case if current < desired
				if(((int)currenttemperature<(int)desiredtemperature)&&flagg==0)
				{
					if(l>=99)
					{
						PORTD ^=  (1<<4);
						l=0;
					}
					PORTD |=  (1<<5);
					PORTD &=~ (1<<6);
				}
				else if(((int)currenttemperature>(int)desiredtemperature)&&flagg==0)
				{
					PORTD |=  (1<<4);
					PORTD &=~ (1<<5);
					PORTD |=  (1<<6);
				}
				else
				{
					flagg=1;
					EEPROM_write(30,'1');
					PORTD &=~  (1<<4);
					PORTD &=~  (1<<5);
					PORTD &=~ (1<<6);

					if((int)currenttemperature <= (int)(desiredtemperature - 5.0))
					{
						flagg=0;
						EEPROM_write(30,'0');
					}
					else if((int)currenttemperature > (int)desiredtemperature)
					{
						flagg=0;
						EEPROM_write(30,'0');
					}
				}
			}
			itoa((int)currenttemperature,arr0,10); //function used to convert int data type to array of characters
			PORTD &=~ (1<<0);
			PORTD |= (1<<1);
			PORTC = arr0[0]-'0';
			_delay_ms(10);
			PORTC = arr0[1]-'0';
			PORTD &=~ (1<<1);
			PORTD &=~ (1<<0);
			_delay_ms(10);
		}	
	}
}











