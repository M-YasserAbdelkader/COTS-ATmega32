/******************************************************************************
 * @file 		MTIMER_program.c
 * @author 		Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief 		TIMER Driver - RTOS stack
 * @version 	0.1
 * @date 		2022-04-30
 * @copyright 	Copyright (c) 2022
 ******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTIMER_interface.h"
#include "MTIMER_configuration.h"
#include "MTIMER_private.h"
#include "MTIMER_register.h"


static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void MTIMER0_voidInit(void)
{ 
	/** \brief Set WaveForm Mode */
	TIMER_SET_WAVEFORM_MODE();

	#if TIMER_MODE == TIMER0_CTC_MODE

		#if TIMER_CTC_INTERRUPT == ENABLE

			/** \brief Compare match Interrupt Enable */
			SET_BIT(MTIMER_U8_TIMSK_REGISTER, MTIMER_TIMSK_OCIE0);
			MTIMER_U8_TCNT0_REGISTER = RTIMER0_CMV;

		#endif

	#elif TIMER_MODE == TIMER0_FAST_PWM_MODE

		/** \brief Set Compare output mode, Fast PWM Mode */
		SET_OC0_FAST_PWM();

	#endif

	/** \brief Clock Select/ Prescaler - Enable Timer */
	MTIMER_U8_TCCR0_REGISTER &= 0b11111000; /*  */
	MTIMER_U8_TCCR0_REGISTER |= TIMER_PRESCALAR; 
}

void TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunck)(void))
{
	if(Copy_pvCallBackFunck != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunck;
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc(); 
	}
}
