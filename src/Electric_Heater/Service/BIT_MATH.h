#ifndef __BIT_MATH_H_
#define __BIT_MATH_H_

#define SET_BIT(Var, BitNo)			Var = (Var |  (1 << BitNo))
#define CLEAR_BIT(Var, BitNo)		Var = (Var & ~(1 << BitNo))
#define TOGGLE_BIT(Var, BitNo)      Var = (Var ^  (1 << BitNo))
#define CHECK_BIT(Var, BitNo)       ( (Var >> BitNo) & 1 )
#define ASSIGN_PORT(Var, Val)       Var = Val


#define CONC_BIT(B7,B6,B5,B4,B3,B2,B1,B0) CONC_BIT_H(B7,B6,B5,B4,B3,B2,B1,B0)  // Replace 
#define CONC_BIT_H(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0   // Concatencante 


#endif