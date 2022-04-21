/*
 * Author: Yasser Mustafa
 * Layer: MCAL
 * Component: ADC
 * Version: 1.00
 * Date: JAN 22th 2022
 */
#ifndef INCLUDE_1_MCAL_5_ADC_MADC_INTERFACE_H_
#define INCLUDE_1_MCAL_5_ADC_MADC_INTERFACE_H_


/*
 * Analog channel Bits
 */
#define ADC0_SINGLE_ENDED_INPUT			0
#define ADC1_SINGLE_ENDED_INPUT			1
#define ADC2_SINGLE_ENDED_INPUT			2
#define ADC3_SINGLE_ENDED_INPUT			3
#define ADC4_SINGLE_ENDED_INPUT			4
#define ADC5_SINGLE_ENDED_INPUT			5
#define ADC6_SINGLE_ENDED_INPUT			6
#define ADC7_SINGLE_ENDED_INPUT			7


void MADC_voidADCInit(void);

u8 MADC_u8GetChannelReading(u8 copy_u8Channel);

#endif /* INCLUDE_1_MCAL_5_ADC_MADC_INTERFACE_H_ */
