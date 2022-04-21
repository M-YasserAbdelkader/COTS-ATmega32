/*************************************************************
 * @file    	: EXTI_program.c
 * @author  	: Yasser Mustafa
 * @brief   	: External interrupt (EXTI) Driver - MCAL
 * @version 	: 0.1
 * @date 		: 2022-04-18
 * @copyright 	: Copyright (c) 2022
 *************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTRI_register.h"
#include "EXTI_config.h"


static void (*pf[3])(void)= {NULL, NULL, NULL};

void MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE)
{

	/** \brief Check which external interrupt is to be enabled*/
	switch (copy_u8EXTI_NUM)
	{
			case EXTI_INT0:
					SET_BIT(GICR, GICR_INT_0);
							/** \brief Check which sense mode is to be activated */
							switch(copy_u8EXTI_SENSE)
							{
										case EXTI_INTO_LOW_LEVEL:
																	CLR_BIT(MCUCR, MCUCR_ISC00);
																	CLR_BIT(MCUCR, MCUCR_ISC01);

																	break;

										case EXTI_INTO_LOGIC_CHANGE:
																	SET_BIT(MCUCR, MCUCR_ISC00);
																	CLR_BIT(MCUCR, MCUCR_ISC01);

																	break;

										case EXTI_INTO_FALLING_EDGE:
																	CLR_BIT(MCUCR, MCUCR_ISC00);
																	SET_BIT(MCUCR, MCUCR_ISC01);

																	break;

										case EXTI_INTO_RISING_EDGE:
																	SET_BIT(MCUCR, MCUCR_ISC00);
																	SET_BIT(MCUCR, MCUCR_ISC01);

																	break;
							}

			break;


			case EXTI_INT1:
							switch(copy_u8EXTI_SENSE)
							{
										case EXTI_INT1_LOW_LEVEL:
																	CLR_BIT(MCUCR, MCUCR_ISC10);
																	CLR_BIT(MCUCR, MCUCR_ISC11);
																	SET_BIT(GICR, GICR_INT_1);
																	break;
										case EXTI_INT1_LOGIC_CHANGE:
																	SET_BIT(MCUCR, MCUCR_ISC10);
																	CLR_BIT(MCUCR, MCUCR_ISC11);
																	SET_BIT(GICR, GICR_INT_1);
																	break;
										case EXTI_INT1_FALLING_EDGE:
																	CLR_BIT(MCUCR, MCUCR_ISC10);
																	SET_BIT(MCUCR, MCUCR_ISC11);
																	SET_BIT(GICR, GICR_INT_1);
																	break;
										case EXTI_INT1_RISING_EDGE:
																	SET_BIT(MCUCR, MCUCR_ISC10);
																	SET_BIT(MCUCR, MCUCR_ISC11);
																	SET_BIT(GICR, GICR_INT_1);
																	break;
										}
			break;

			case EXTI_INT2:
										switch(copy_u8EXTI_SENSE)
										{

										case EXTI_INT2_FALLING_EDGE:
																	CLR_BIT(MCUCSR, MCUCSR_INT2);
																	SET_BIT(GICR, GICR_INT_2);
																	break;
										case EXTI_INT2_RISING_EDGE:
																	SET_BIT(MCUCSR, MCUCSR_INT2);
																	SET_BIT(GICR, GICR_INT_2);
																	break;

										}
			break;

	}
}



void MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM)
{
	switch(copy_u8EXTI_NUM)
	{
							case EXTI_INT0:
											CLR_BIT(GICR, GIFR_INT_0);
											break;
							case EXTI_INT1:
											CLR_BIT(GICR, GIFR_INT_1);
											break;
							case EXTI_INT2:
											CLR_BIT(GICR, GIFR_INT_2);
											break;

	}
}



void __vector_1(void)		__attribute__((signal));
void __vector_1(void)
{
	if(pf[EXTI_INT0] != NULL)
	{
		pf[EXTI_INT0]();
	}

}

void __vector_2(void)		__attribute__((signal));
void __vector_2(void)
{
	if(pf[EXTI_INT1] != NULL)
	{
		pf[EXTI_INT1]();
	}
}

void __vector_3(void)		__attribute__((signal));
void __vector_3(void)
{
	if(pf[EXTI_INT2] != NULL)
	{
		pf[EXTI_INT2]();
	}
}


void MEXTI_voidSetCallBack(void (*copy_ptrToFunction)(void), u8 copy_u8Index)
{
	pf[copy_u8Index] = copy_ptrToFunction;

}




