/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-28-2022                                  */
/*      Version : 0.1                                        */
/*      File    : KeyPad_prog.c                              */
/*************************************************************/

#include "STD_TYPES.h"
#include "Keypad_config.h"
#include "Keypad_private.h"
#include "Keypad_interface.h"
#include "DIO_interface.h"

void KEYPAD_init(void){
	
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_HIGH);
	
    #if KEYPAD_MODE == KEYPAD_INTERNAL_PULL_UP

    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_COL_1, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_COL_2, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_COL_3, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_COL_4, DIO_u8_HIGH);

    #endif


}



u8   KEYPAD_getButton(void){
    //Apply Sequence 1 
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_LOW);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_HIGH);

    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_1) == DIO_u8_LOW){return R1C1;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_2) == DIO_u8_LOW){return R1C2;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_3) == DIO_u8_LOW){return R1C3;}
    //if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_4) == DIO_u8_LOW){return R1C4;}


    // Apply Sequence 2
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_LOW);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_HIGH);

    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_1) == DIO_u8_LOW){return R2C1;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_2) == DIO_u8_LOW){return R2C2;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_3) == DIO_u8_LOW){return R2C3;}
    //if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_4) == DIO_u8_LOW){return R2C4;}    


    // Apply Sequence 3
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_LOW);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_HIGH);

    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_1) == DIO_u8_LOW){return R3C1;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_2) == DIO_u8_LOW){return R3C2;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_3) == DIO_u8_LOW){return R3C3;}
   // if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_4) == DIO_u8_LOW){return R3C4;}  

    // Apply Sequence 4
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_HIGH);
    DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_LOW);

    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_1) == DIO_u8_LOW){return R4C1;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_2) == DIO_u8_LOW){return R4C2;}
    if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_3) == DIO_u8_LOW){return R4C3;}
    //if(DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_COL_4) == DIO_u8_LOW){return R4C4;}  
		
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_1, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_2, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_3, DIO_u8_HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEYPAD_ROW_4, DIO_u8_HIGH);


    return KEYPAD_NULL;
}

