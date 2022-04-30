/******************************************************************************
 * @file 		MTIMER_configuration.h
 * @author 		Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief 		TIMER Driver - RTOS stack
 * @version 	0.1
 * @date 		2022-04-30
 * @copyright 	Copyright (c) 2022
 ******************************************************************************/
#ifndef MTIMER_CONFIGURATION_H_
#define MTIMER_CONFIGURATION_H_

/******************************************************************************
 * \def     TIMER_MODE
 * \brief   Selects Prescalar 
 * \param   TIMER_CLK_STP                   No Clock Source
 * \param   TIMER_CLK_1                     Clock   
 * \param   TIMER_CLK_8                     Clock/8
 * \param   TIMER_CLK_64                    clock/64
 * \param   TIMER_CLK_256                   clock/256
 * \param   TIMER_CLK_1024                  clock /1024
 * \param   TIMER_CLK_EXTT0_FALLING_EDGE    Clock on Falling Edge on T0
 * \param   TIMER_CLK_EXTT0_RISING_EDGE     Clock on rising Edge on T0
 ******************************************************************************/
#define TIMER_PRESCALAR TIMER_CLK_64

/******************************************************************************
 * \def     TIMER_MODE
 * \brief   Selects WaveForm Generation Mode
 * \param   TIMER_NORMAL_MODE       Noramal Mode
 * \param   TIMER0_PWM_MODE         PWM, Phase Correct
 * \param   TIMER0_CTC_MODE         Compare Match 
 * \param   TIMER0_FAST_PWM_MODE    Fast PWM
 ******************************************************************************/
#define TIMER_MODE  TIMER0_CTC_MODE

/******************************************************************************
 * \if TIMER_MODE == TIMER0_CTC_MODE
 * 
 *      \def TIMER_CTC_INTERRUPT
 *      \brief Enable/Disable Compare Match Interrupt
 *      \param ENABLE  Enable interrupt
 *      \param Disable Disable interrupt
 * 
 *  \elseif TIMER_MODE == TIMER0_FAST_PWM_MODE
 * 
 *      \def TIMER_OC0_FAST_PWM 
 *      \brief Compare Output Mode, Fast PWM Mode
 * 
 *      \param TIMER_OC0_FAST_PWM_DISCONNECT
 *              Normal Port Operation, OC0 disconnected
 *      \param TIMER_OC0_CLR_CMP_SET_TOP
 *              Clear OC0 on Compare Match, Set OC0 at top
 *      \param TIMER_OC0_SET_CMP_CLR_TOP
 *              Set Oc0 on compare match, Clear OC0 at top
 *  \endif 
 ******************************************************************************/
#if TIMER_MODE == TIMER0_CTC_MODE

    #define TIMER_CTC_INTERRUPT     ENABLE 

#elif TIMER_MODE == TIMER0_FAST_PWM_MODE

    #define TIMER_OC0_FAST_PWM  TIMER_OC0_CLR_CMP_SET_TOP

#endif




#endif /* MTIMER_CONFIGURATION_H_ */
