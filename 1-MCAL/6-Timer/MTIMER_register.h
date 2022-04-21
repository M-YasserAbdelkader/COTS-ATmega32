/**********************************************************
 * @file        : MTIMER_register.h
 * @author      : Yasser Mustafa
 * @brief       : TIMER Driver - MCAL
 * @version     : 0.1
 * @date        : 2022-04-19
 * @copyright   : Copyright (c) 2022
 **********************************************************/
#ifndef MTIMER_REGISTER_H_
#define MTIMER_REGISTER_H_

/**********************************************************
 * \def     : MTIMER_U8_TCCR0_REGISTER
 * \brief   : Timer/Counter0 Control Register 
 * 
 * \def     : MTIMER_U8_TCNT0_REGISTER
 * \brief   : Timer/Counter 0 Register
 * 
 * \def     : MTIMER_U8_OCR0_REGISTER
 * \brief   : Output Compare Register
 * 
 * \def     : MTIMER_U8_TIFR
 * \brief   : Timer/Counter Interrupt mask Register
 **********************************************************/
#define	MTIMER_U8_TCCR0_REGISTER		*((volatile u8*)	0x53)


/*
 * Waveform Generation Mode
 * Options:
 * WGM00 = 0	WGM01 = 0		--->	Normal
 * WGM00 = 1	WGM01 = 0		--->	PWM, Phase Correct
 * WGM00 = 0	WGM01 = 1		--->	CTC
 * WGM00 = 1	WGM01 = 1		--->	Fast PWM
 */
#define MTIMER_TCCR_WGM00				6
#define MTIMER_TCCR_WGM01				3

/*
 * Compare Match Output Mode
 * Options:
 * COM00 = 0	COM01 = 0	--->	Normal Port Operation, OC0 Disconnected
 * COM00 = 0	COM01 = 0	--->	Toggle OC0 on compare match
 * COM00 = 0	COM01 = 1	--->	Clear OC0 on compare match
 * COM00 = 1	COM01 = 1	--->	Set OC0 On compare match
 */
#define MTIMER_TCCR_COM00				4
#define MTIMER_TCCR_COM01				5

/*
 * Clock Select
 * Options:
 * CS00 = 0		CS01 = 0	CS02 = 0		---> No clock Source
 * CS00 = 0		CS01 = 0	CS02 = 1		---> clkI/O/(No prescaling)
 * CS00 = 0		CS01 = 1	CS02 = 0		---> clkI/O/8 (From prescaler)
 * CS00 = 0		CS01 = 1	CS02 = 1		---> clkI/O/64 (From prescaler)
 * CS00 = 1		CS01 = 0	CS02 = 0		---> clkI/O/256 (From prescaler)
 * CS00 = 1		CS01 = 0	CS02 = 1		---> clkI/O/1024 (From prescaler)
 * CS00 = 1		CS01 = 1	CS02 = 0		---> External clock source on T0 pin. Clock on falling edge.
 * CS00 = 1		CS01 = 1	CS02 = 1		---> External clock source on T0 pin. Clock on rising edge.
 */
#define MTIMER_TCCR_CS00				0
#define MTIMER_TCCR_CS01				1
#define MTIMER_TCCR_CS02				2

#define MTIMER_U8_TCNT0_REGISTER		*((volatile u8*)	0x52)


#define MTIMER_U8_OCR0_REGISTER			*((volatile u8*)	0x5C)

#define MTIMER_U8_TIMSK_REGISTER		*((volatile u8*)	0x59)

/*
 * Timer/Counter0 Output Compare Match Interrupt Enable
 * Options:
 * OCIE0 = 0 ---> Interrupt Disable
 * OCIE0 = 1 ---> Interrupt Enable
 */
#define MTIMER_TIMSK_OCIE0		1

/*
 * Timer/Counter0 Overflow Interrupt Enable
 * Options:
 * OCIE0 = 0 ---> Interrupt Disable
 * OCIE0 = 1 ---> Interrupt Enable
 */
#define MTIMER_TIMSK_TOIE0		0


#define MTIMER_U8_TIFR			*((volatile u8*)	0x53)

#define NULL		(void *) 0

#endif /* MTIMER_REGISTER_H_ */
