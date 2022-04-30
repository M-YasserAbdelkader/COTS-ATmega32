/****************************************************************************************************************
 * @file        MADC_interface.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_
/****************************************************************************************************************
 *  \fn     void MADC_voidADCInit(void); 
 *  \brief  Intiate ADC Prephiral
 *  \return None
****************************************************************************************************************/
void MADC_voidADCInit(void);

/****************************************************************************************************************
 *  \fn     u16 MADC_u16GetChannelReading(u8 copy_u8Channel); 
 *  \brief  Get Channel Reading
 *  \param  copy_u8Channel ADC Channel to be read.
 *          it takes the following values:
 * \li \c   ADC0_SINGLE_ENDED_INPUT
 * \li \c   ADC1_SINGLE_ENDED_INPUT
 * \li \c   ADC2_SINGLE_ENDED_INPUT
 * \li \c   ADC3_SINGLE_ENDED_INPUT
 * \li \c   ADC4_SINGLE_ENDED_INPUT
 * \li \c   ADC5_SINGLE_ENDED_INPUT
 * \li \c   ADC6_SINGLE_ENDED_INPUT 
 * \li \c   ADC7_SINGLE_ENDED_INPUT
 * 
 * \param   copy_pu16Reading Address of the \c u16 variable 
 *          to store ADC Reading 
 * 
 * \return  Upon Success, Function returns 0. OtherWise,
 *          OtherWise, function returns one of the following error flags:
 * \li \c   BUSY_FUNCTION       if previous conversion is in progress
 * \li \c   NULL_POINTER        if \c copy_pu16Reading is a null pointer
 * \li \c   NOK                 if \c copy_u8Channel is not a valid option
 * \li \c   TIMEOUT             if Timeout occured during conversion      
 *  
 ****************************************************************************************************************/
u8 MADC_u8StartConversionSynch(u8 copy_u8Channel, u16* copy_pu16Reading);

u8 MADC_u8StartConversionAsynch(u8 copy_u8Channel, u16* copy_pu16Reading, void (*copy_pvNotificationFunc)(void));

u8 MADC_u8StartChainConversionAsynch();

/***************************************************************************************************************/
/** \defgroup copy_u8Channel Analog Channels */ 
/** @{ */
#define ADC0_SINGLE_ENDED_INPUT			0   /**< ADC0 */
#define ADC1_SINGLE_ENDED_INPUT			1   /**< ADC1 */
#define ADC2_SINGLE_ENDED_INPUT			2   /**< ADC2 */
#define ADC3_SINGLE_ENDED_INPUT			3   /**< ADC3 */
#define ADC4_SINGLE_ENDED_INPUT			4   /**< ADC4 */
#define ADC5_SINGLE_ENDED_INPUT			5   /**< ADC5 */
#define ADC6_SINGLE_ENDED_INPUT			6   /**< ADC6 */
#define ADC7_SINGLE_ENDED_INPUT			7   /**< ADC7 */
/** @} */
/***************************************************************************************************************/

#endif /* INCLUDE_1_MCAL_5_ADC_MADC_INTERFACE_H_ */
