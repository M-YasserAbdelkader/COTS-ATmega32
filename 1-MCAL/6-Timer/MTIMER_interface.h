/**********************************************************
 * @file 		: MTIMER_interface.h
 * @author 		: Yasser Mustafa
 * @brief 		: TIMER Driver - MCAL
 * @version 	: 0.1
 * @date 		: 2022-04-19
 * @copyright 	: Copyright (c) 2022
 **********************************************************/
#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

/**********************************************************
 *  \fn     void MTIMER0_voidInit(void); 
 *  \brief  Initiate Timer/Counter0
 *  \param  None
 *  \return None
**********************************************************/
void MTIMER0_voidInit(void);

/**********************************************************
 *  \fn     MTIMER0_voidSetCompareMatchValue(u8 copy_u8Value); 
 *  \brief  Set Compare Match Value 
 *  \param  copy_u8Value  u8 Compare match value
 *  \return None
**********************************************************/
void MTIMER0_voidSetCompareMatchValue(u8 copy_u8Value);

void TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunck)(void));

/** \brief Timer waveform Generation Mode */
#define TIMER0_NORMAL_MODE                      0
#define TIMER0_PWM_MODE                         1
#define TIMER0_CTC_MODE                         2
#define TIMER0_FAST_PWM_MODE                    3
/**********************************************************/

/** \brief Compare Output Mode, non-PMW Mode */
#define TIMER_OC0_DISCONNECT                    0
#define TIMER_OC0_TOGGLE                        1
#define TIMER_OC0_CLEAR                         2
#define TIMER_OC0_SET                           3
/**********************************************************/

/** \brief Compare Output Mode, Fast PMW Mode */
#define TIMER_OC0_FAST_PWM_DISCONNECT            0
#define TIMER_OC0_CLR_CMP_SET_TOP                1
#define TIMER_OC0_SET_CMP_CLR_TOP                2
/**********************************************************/

/** \brief Timer Prescalars */
#define TIMER_CLK_STP                           0
#define TIMER_CLK_1                             1
#define TIMER_CLK_8                             2
#define TIMER_CLK_64                            3
#define TIMER_CLK_256                           4
#define TIMER_CLK_1024                          5
#define TIMER_CLK_EXTT0_FALLING_EDGE            6
#define TIMER_CLK_EXTT0_RISING_EDGE             7



#endif /* MTIMER_INTERFACE_H_ */
