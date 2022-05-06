/*************************************************************
 * @file        : EXTI_interface.h
 * @author      : Yasser Mustafa
 * @brief       : External interrupt (EXTI) Driver - MCAL
 * @version     : 0.2
 * @date        : 2022-04-18
 * @copyright   : Copyright (c) 2022
 *************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/** \brief Sense Control for  INT0 */
#define EXTI_LOW_LEVEL		    0
#define EXTI_LOGIC_CHANGE	    1
#define EXTI_FALLING_EDGE	    2
#define EXTI_RISING_EDGE	    3

/** \brief EXTI 0, 1, 2 */
#define EXTI_INT0			        0
#define EXTI_INT1			        1
#define EXTI_INT2			        2

/****************************************************************************************************************
 *  \fn     u8 MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE); 
 *  \brief  Enable External interrupt and set its Sense control
 *  \param  copy_u8EXTI_NUM External interrupt to be Enabled.
 *          it takes the following values:
 * \li \c   EXTI_INT0
 * \li \c   EXTI_INT1
 * \li \c   EXTI_INT2 
 * 
 * \param   copy_u8EXTI_SENSE Sense Control variable  
 *          it takes the following values:
 *          for EXTI_INT0:
 * \li \c   EXTI_LOW_LEVEL
 * \li \c   EXTI_LOGIC_CHANGE
 * \li \c   EXTI_FALLING_EDGE
 * \li \c   EXTI_RISING_EDGE
 *          for EXTI_INT2:
 * \li \c   EXTI_FALLING_EDGE
 * \li \c   EXTI_RISING_EDGE
 *          
 * 
 * \return  Upon Success, Function returns \c OK. OtherWise,
 *          OtherWise, function returns one of the following error flags:
 * \li \c   NOK                 if \c copy_u8EXTI_NUM is not a valid option 
 *                              and/or \c copy_u8EXTI_SENSE     
 *  
 ****************************************************************************************************************/
u8 MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE);

/****************************************************************************************************************
 *  \fn     u8 MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM); 
 *  \brief  Disable External interrupt
 *  \param  copy_u8EXTI_NUM External interrupt to be disabled.
 *          it takes the following values:
 * \li \c   EXTI_INT0
 * \li \c   EXTI_INT1
 * \li \c   EXTI_INT2 
 * 
 * \return  Upon Success, Function returns \c OK. OtherWise,
 *          OtherWise, function returns one of the following error flags:
 * \li \c   NOK                 if \c copy_u8EXTI_NUM is not a valid option   
 *  
 ****************************************************************************************************************/
u8 MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM);


u8 MEXTI_voidSetCallBack(void (*copy_ptrToFunction)(void), u8 copy_u8Index);


#endif
