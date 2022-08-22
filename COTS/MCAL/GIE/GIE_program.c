/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 7-03-2022                                  */
/*      Version : 0.2V                                       */
/*      File    : GIE_program.c                              */
/*************************************************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"

void GIE_enable(void){
    SET_BIT(SREG, GIE);
}
void GIE_disable(void){
    CLEAR_BIT(SREG, GIE);
}
