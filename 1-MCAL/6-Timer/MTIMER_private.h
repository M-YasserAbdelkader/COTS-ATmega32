/**********************************************************
 * @file 		: MTIMER_private.h
 * @author 		: Yasser Mustafa
 * @brief 		: TIMER Driver - MCAL
 * @version 	: 0.1
 * @date 		: 2022-04-19
 * @copyright 	: Copyright (c) 2022
 **********************************************************/

#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

#if TIMER_MODE == TIMER_NORMAL_MODE

    #define TIMER_SET_WAVEFORM_MODE()   CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM00);\
                                        CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM01)

#elif TIMER_MODE == TIMER0_PWM_MODE

    #define TIMER_SET_WAVEFORM_MODE()   SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM00);\
                                        CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM01)
#elif TIMER_MODE == TIMER0_CTC_MODE

    #define TIMER_SET_WAVEFORM_MODE()   CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM00);\
                                        SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM01)
#elif TIMER_MODE == TIMER0_FAST_PWM_MODE

    #define TIMER_SET_WAVEFORM_MODE()   SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM00);\
                                        SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_WGM01)

    #if TIMER_OC0_FAST_PWM == TIMER_OC0_FAST_PWM_DISCONNECT

        #define SET_OC0_FAST_PWM()      CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM00);\
                                        CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM01)

    #elif TIMER_OC0_FAST_PWM == TIMER_OC0_CLR_CMP_SET_TOP

        #define SET_OC0_FAST_PWM()      CLR_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM00);\
                                        SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM01)

    #elif TIMER_OC0_FAST_PWM == TIMER_OC0_SET_CMP_CLR_TOP

        #define SET_OC0_FAST_PWM()      SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM00);\
                                        SET_BIT(MTIMER_U8_TCCR0_REGISTER, MTIMER_TCCR_COM01)     
    #endif
#endif



#define Enable  1
#define Disable 0


#endif /* MTIMER_PRIVATE_H_ */
