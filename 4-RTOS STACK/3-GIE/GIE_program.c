/*************************************************************
 * @file      GIE_interface.c
 * @author 	  Yasssr Mustafa
 * @brief 	  Global interrupt Enable (GIE) Driver - MCAL
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/ 


#include	"STD_types.h"
#include	"BIT_MATH.h"
#include 	"GIE_interface.h"
#include 	"GIE_register.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG, SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG, SREG_I);
}


