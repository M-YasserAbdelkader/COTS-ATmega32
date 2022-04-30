/**********************************************************
 * @file        MADC_program.c
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "MADC_register.h"
#include "MADC_configuration.h"
#include "MADC_private.h"

static u16* ADC_pu16Reading = NULL; 
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;


void MADC_voidADCInit(void)
{
/* Select ADC Reference Voltage */
#if ADC_REFERENCE_VOLTAGE == ADC_AREF

	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#elif ADC_REFERENCE_VOLTAGE == ADC_AVCC

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#elif ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_2_56V

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#else
#error "Wrong Reference Voltage Selection"
#endif

/* Adjust Result  */
#if ADC_RESULT_ADJUST == ADC_LEFT_ADJUST

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_ADLAR);

#elif ADC_RESULT_ADJUST == ADC_LEFT_ADJUST

	CLEAR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_ADLAR);

#else
#error "Wrong Adjust Result Selection"
#endif


	/*  Disable Auto Triggering (Not Configurable for now ) */ 
	CLR_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADATE);

	/* Set Prescaler */
	ADC_U8_ADCSRA_REGISTER &= ADC_PRESCALAR_MUSK;
	ADC_U8_ADCSRA_REGISTER |= ADC_PRESCALER;

	/* Enable Prescaler */
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADEN);

}


u8 MADC_u8StartConversionSynch(u8 copy_u8Channel, u16* copy_pu16Reading)
{

	u8 local_u8ErrorState = OK;
	u32 local_u32Counter = ADC_U32_TIMEOUT;
	/* Check ADC Conversion Status*/
	if (GET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC) != 0)
	{
		local_u8ErrorState = BUSY_FUNCTION;
	}
	else
	{
		if (copy_pu16Reading == NULL)
		{
			/* Return Error Status: Null Pointer */
			local_u8ErrorState = NULL_POINTER; 
		}
		else if (copy_u8Channel < ADC0_SINGLE_ENDED_INPUT || copy_u8Channel > ADC7_SINGLE_ENDED_INPUT)
		{
			/* Return Error Status: NOK */
			local_u8ErrorState = NOK;
		}
		else
		{
			/* Set ADC Channel */
			ADC_U8_ADMUX_REGISTER &= ADC_CHANNEL_REGISTER_MUSK;
			ADC_U8_ADMUX_REGISTER |=copy_u8Channel;
		
			/* Start Conversiotn */
			SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC);
		
			/* Polling Till converstion is complete or Timeout occurs */
			while ((GET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC) != 0) && (local_u32Counter != 0))
			{
				local_u32Counter--;
			}
			if (local_u32Counter == 0)
			{
				/* Return Error Status: Timeout */
				local_u8ErrorState = TIMEOUT;
			}
			else
			{
				/* Clear ADC conversion Complete Interrupt Flag */
				SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADIF);

			#if ADC_RESULT_ADJUST == ADC_LEFT_ADJUST
				/* Get 8-bit High ADC register reading */
				*copy_pu16Reading = 0;
				*copy_pu16Reading = (u16)ADC_U8_ADCH_REGISTER;	
			#elif ADC_RESULT_ADJUST == ADC_RIGHT_ADJUST
				/* Get 16-bit ADC registers (LOW + High) reading */
				*copy_pu16Reading = ADC_U16_ADCL_REGISTER;
			#else
			#error "Wrong Adjust Result Select"
			#endif	
		}
	}
	
	}
return local_u8ErrorState;
}

u8 MADC_u8StartConversionAsynch(u8 copy_u8Channel, u16* copy_pu16Reading, void (*copy_pvNotificationFunc)(void))
{
	u8 local_u8ErrorStatus = OK;

	/* Check ADC Conversion Status*/
	if (GET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC) != 0)
	{
		local_u8ErrorStatus = BUSY_FUNCTION;
	}
	else
	{
		if ((copy_pu16Reading == NULL) || (copy_pvNotificationFunc == NULL))
		{
			/* Return Error Status: Null Pointer */
			local_u8ErrorStatus = NULL_POINTER;
		}
		else
		{
			/* Initialize Reading Variable globally*/
			ADC_pu16Reading = copy_pu16Reading;

			/* Initialize callbck notification function globally*/
			ADC_pvCallBackNotificationFunc = copy_pvNotificationFunc;
		
			/* Set ADC Channel */
			ADC_U8_ADMUX_REGISTER &= ADC_CHANNEL_REGISTER_MUSK;
			ADC_U8_ADMUX_REGISTER |=copy_u8Channel;

			/* Enable ADC Conversion compelete interrupt */
			SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADIE);
		
			/* Start Conversiotn */
			SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC);
		}
	}

	return local_u8ErrorStatus;
	
}

void __vector_16(void)	 __attribute__((signal));
void __vector_16(void)
{
	/* Read ADC Result */
	#if ADC_RESULT_ADJUST == ADC_LEFT_ADJUST
		/* Get 8-bit High ADC register reading */
		*ADC_pu16Reading = 0;
		*ADC_pu16Reading = (u16)ADC_U8_ADCH_REGISTER;	
	#elif ADC_RESULT_ADJUST == ADC_RIGHT_ADJUST

		/* Get 16-bit ADC registers (LOW + High) reading */
		*ADC_pu16Reading = ADC_U16_ADCL_REGISTER;
	#else
	#error "Wrong Adjust Result Select"
	#endif

	/*Invoke callback notification function */
	ADC_pvCallBackNotificationFunc();

	/* Disable ADC Conversion compelete interrupt */
	CLR_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADIE);
}