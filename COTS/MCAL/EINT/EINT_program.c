/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-01-2022                                  */
/*      Version : 0.1                                        */
/*      File    : EINT_program.c                              */
/*************************************************************/


#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "EINT_private.h"
#include "EINT_config.h"
#include "EINT_interface.h"

void INT_init(void){
// Setting up INT0
    #if EXT_INT_0_EN == ENABLE 
        #if   EXT_INT_0_SC == LOW_LEVEL         // 00
            CLEAR_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
        #elif EXT_INT_0_SC == LOGICAL_CHANGE    // 01
            SET_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
        #elif EXT_INT_0_SC == FALLING_EDGE      // 10
            CLEAR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        #elif EXT_INT_0_SC == RISING_EDGE       // 11
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
        #endif

            SET_BIT(GICR,INT0);  
    #endif

// Setting up INT1
    #if EXT_INT_1_EN == ENABLE 
        #if   EXT_INT_1_SC == LOW_LEVEL         // 00
            CLEAR_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        #elif EXT_INT_1_SC == LOGICAL_CHANGE    // 01
            SET_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
        #elif EXT_INT_1_SC == FALLING_EDGE      // 10
            CLEAR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        #elif EXT_INT_1_SC == RISING_EDGE       // 11
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
        #endif

            SET_BIT(GICR,INT1);  
    #endif


// Setting up INT2
    #if EXT_INT_2_EN == ENABLE
        #if EXT_INT_1_SC == FALLING_EDGE      
            CLEAR_BIT(MCUCSR, ISC10);
        #elif EXT_INT_1_SC == RISING_EDGE       
            SET_BIT(MCUCSR, ISC10);
        #endif
            SET_BIT(GICR,INT2);  
    #endif


}


void INT_enbaleInterrupt(u8 intPin){
    if      (intPin == EXT_INT_0){SET_BIT(GICR,INT0);}
    else if (intPin == EXT_INT_1){SET_BIT(GICR,INT1);}
    else if (intPin == EXT_INT_2){SET_BIT(GICR,INT2);}
}


void INT_disableInterrupt(u8 intPin){
    if      (intPin == EXT_INT_0){CLEAR_BIT(GICR,INT0);}
    else if (intPin == EXT_INT_1){CLEAR_BIT(GICR,INT1);}
    else if (intPin == EXT_INT_2){CLEAR_BIT(GICR,INT2);}
}


void INT_SenseControlMode(u8 intPin, u8 SenseControlMode){
    if      (intPin == EXT_INT_0){

        switch (SenseControlMode){
            case LOW_LEVEL:                    // 00
                CLEAR_BIT(MCUCR, ISC00);
                CLEAR_BIT(MCUCR, ISC01);        break;   
            case LOGICAL_CHANGE :              // 01
                SET_BIT(MCUCR, ISC00);
                CLEAR_BIT(MCUCR, ISC01);        break;
            case FALLING_EDGE:                 // 10
                CLEAR_BIT(MCUCR, ISC00);
                SET_BIT(MCUCR, ISC01);          break;
            case RISING_EDGE:                  // 11
                SET_BIT(MCUCR, ISC00);
                SET_BIT(MCUCR, ISC01);          break;
            default:                            break;
        }
        
    }else if (intPin == EXT_INT_1){
        switch (SenseControlMode){
            case LOW_LEVEL:                    // 00
                CLEAR_BIT(MCUCR, ISC10);
                CLEAR_BIT(MCUCR, ISC11);        break;   
            case LOGICAL_CHANGE :              // 01
                SET_BIT(MCUCR, ISC10);
                CLEAR_BIT(MCUCR, ISC11);        break;
            case FALLING_EDGE:                 // 10
                CLEAR_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);          break;
            case RISING_EDGE:                  // 11
                SET_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);          break;
            default:                            break;
        }
    }else if (intPin == EXT_INT_2){
        switch (SenseControlMode){
            case FALLING_EDGE:                 // 10
                CLEAR_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);          break;
            case RISING_EDGE:                  // 11
                SET_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);          break;
            default:                            break;
        }
    }
}



void INT_clearFlag(u8 intPin){
    if      (intPin == EXT_INT_0){CLEAR_BIT(GIFR,INTF0);}
    else if (intPin == EXT_INT_1){CLEAR_BIT(GIFR,INTF1);}
    else if (intPin == EXT_INT_2){CLEAR_BIT(GIFR,INTF2);}   
}
