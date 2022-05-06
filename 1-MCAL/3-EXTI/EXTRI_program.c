/*************************************************************
 * @file    	: EXTI_program.c
 * @author  	: Yasser Mustafa
 * @brief   	: External interrupt (EXTI) Driver - MCAL
 * @version 	: 0.2
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

static void (*pf[3])(void) = {NULL, NULL, NULL};

u8 MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE)
{

	u8 local_u8ErrorState = OK;
	/* Validate Input */
	if (copy_u8EXTI_NUM > EXTI_INT2)
	{
		local_u8ErrorState = NOK;
	}
	else if ((copy_u8EXTI_NUM <= EXTI_INT1) && (copy_u8EXTI_SENSE > EXTI_RISING_EDGE))
	{
		local_u8ErrorState = NOK;
	}
	else if ((copy_u8EXTI_NUM == EXTI_INT2) && ((copy_u8EXTI_SENSE > EXTI_RISING_EDGE) || copy_u8EXTI_SENSE < EXTI_FALLING_EDGE))
	{
		local_u8ErrorState = NOK;
	}
	else
	{
		/** \brief Check which external interrupt is to be enabled*/
		switch (copy_u8EXTI_NUM)
		{
		case EXTI_INT0:
			SET_BIT(GICR, GICR_INT_0);
			/** \brief Check which sense mode is to be activated */
			switch (copy_u8EXTI_SENSE)
			{
			case EXTI_LOW_LEVEL:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				CLR_BIT(MCUCR, MCUCR_ISC01);
				break;

			case EXTI_LOGIC_CHANGE:
				SET_BIT(MCUCR, MCUCR_ISC00);
				CLR_BIT(MCUCR, MCUCR_ISC01);
				break;

			case EXTI_FALLING_EDGE:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				break;

			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				break;
			}
			break;

		case EXTI_INT1:
			switch (copy_u8EXTI_SENSE)
			{
			case EXTI_LOW_LEVEL:
				CLR_BIT(MCUCR, MCUCR_ISC10);
				CLR_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT_1);
				break;

			case EXTI_LOGIC_CHANGE:
				SET_BIT(MCUCR, MCUCR_ISC10);
				CLR_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT_1);
				break;

			case EXTI_FALLING_EDGE:
				CLR_BIT(MCUCR, MCUCR_ISC10);
				SET_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT_1);
				break;

			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR, MCUCR_ISC10);
				SET_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT_1);
				break;
			}
			break;

		case EXTI_INT2:
			switch (copy_u8EXTI_SENSE)
			{
			case EXTI_FALLING_EDGE:
				CLR_BIT(MCUCSR, MCUCSR_INT2);
				SET_BIT(GICR, GICR_INT_2);
				break;

			case EXTI_RISING_EDGE:
				SET_BIT(MCUCSR, MCUCSR_INT2);
				SET_BIT(GICR, GICR_INT_2);
				break;
			}
			break;
		}
	}
	return local_u8ErrorState;
}

u8 MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM)
{
	u8 local_u8ErrorState = OK;
	if (copy_u8EXTI_NUM > EXTI_INT2)
	{
		local_u8ErrorState = NOK;
	}
	else
	{
		switch (copy_u8EXTI_NUM)
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
	return local_u8ErrorState;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (pf[EXTI_INT0] != NULL)
	{
		pf[EXTI_INT0]();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (pf[EXTI_INT1] != NULL)
	{
		pf[EXTI_INT1]();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (pf[EXTI_INT2] != NULL)
	{
		pf[EXTI_INT2]();
	}
}

u8 MEXTI_voidSetCallBack(void (*copy_ptrToFunction)(void), u8 copy_u8Index)
{
	u8 local_u8ErrorState = OK;
	
	/* Check input Validity */
	if (copy_ptrToFunction == NULL)
	{
		local_u8ErrorState = NULL_POINTER;
	}
	else if (copy_u8Index > EXTI_INT2)
	{
		local_u8ErrorState = NOK;
	}
	else
	{
		pf[copy_u8Index] = copy_ptrToFunction;
	}
	return local_u8ErrorState;
}
