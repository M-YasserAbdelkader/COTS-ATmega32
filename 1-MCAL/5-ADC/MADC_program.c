/*
 * Author: Yasser Mustafa
 * Layer: MCAL
 * Component: ADC
 * Version: 1.00
 * Date: JAN 22th 2022
 */

#include "../../2-LIB/STD_TYPES.h"
#include "../../2-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "../../1-MCAL/5-ADC/MADC_interface.h"
#include "../../1-MCAL/5-ADC/MADC_register.h"
#include "../../1-MCAL/5-ADC/MADC_configuration.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"

void MADC_voidADCInit(void)
{
	// Select Refrence Voltage

	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);

	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

	//Left Adjust Result
	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_ADLAR);

	//Disable Auto Triggering
	CLR_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADATE);

	//Select Prescaler
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADPS2);
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADPS1);
	CLR_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADPS0);

	//Enable ADC
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADEN);

}


u8 MADC_u8GetChannelReading(u8 copy_u8Channel)
{


	ADC_U8_ADMUX_REGISTER &= 0b11100000;
	ADC_U8_ADMUX_REGISTER |=copy_u8Channel;

	// Start Conversion
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC);

	//Polling till ADSC is zero
	while (GET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC) == 1);
	//Read MSBs in High register

	return ADC_U8_ADCH_REGISTER;
}

