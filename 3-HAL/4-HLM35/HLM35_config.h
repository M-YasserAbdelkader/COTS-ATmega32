/**********************************************************
 * @file        HLM35_config.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       LM35 Driver - HAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/

/**********************************************************************
 * \def     HLM35_CHANNEL
 * \brief   Select LM35 Channel
 * \details The following options are availble:
 * \arg \c  ADC0_SINGLE_ENDED_INPUT  ADC0
 * \arg \c  ADC1_SINGLE_ENDED_INPUT  ADC1
 * \arg \c  ADC2_SINGLE_ENDED_INPUT  ADC2
 * \arg \c  ADC3_SINGLE_ENDED_INPUT  ADC3
 * \arg \c  ADC4_SINGLE_ENDED_INPUT  ADC4
 * \arg \c  ADC5_SINGLE_ENDED_INPUT  ADC5
 * \arg \c  ADC6_SINGLE_ENDED_INPUT  ADC6
 * \arg \c  ADC7_SINGLE_ENDED_INPUT  ADC7
 **********************************************************************/
#define HLM35_CHANNEL   ADC0_SINGLE_ENDED_INPUT