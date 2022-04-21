/*************************************************************
 * @file        : EXTI_interface.h
 * @author      : Yasser Mustafa
 * @brief       : External interrupt (EXTI) Driver - MCAL
 * @version     : 0.1
 * @date        : 2022-04-18
 * @copyright   : Copyright (c) 2022
 *************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/** \brief Sense Control for  INT0 */
#define EXTI_INTO_LOW_LEVEL		    0
#define EXTI_INTO_LOGIC_CHANGE	    1
#define EXTI_INTO_FALLING_EDGE	    2
#define EXTI_INTO_RISING_EDGE	    3

/** \brief Sense Control for  INT1*/
#define EXTI_INT1_LOW_LEVEL		    0
#define EXTI_INT1_LOGIC_CHANGE	    1
#define EXTI_INT1_FALLING_EDGE	    2
#define EXTI_INT1_RISING_EDGE	    3


/** \brief Sense Control for  INT2 */
#define EXTI_INT2_FALLING_EDGE	    0
#define EXTI_INT2_RISING_EDGE	    1

/** \brief EXTI 0, 1, 2 */
#define EXTI_INT0			        0
#define EXTI_INT1			        1
#define EXTI_INT2			        2

/*************************************************************
 *  \fn     void MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE); 
 *  \brief  Enable External Interrupt
 *  \param  copy_u8EXTI_NUM EXTI_INT0 || EXTI_INT1 || EXTI_INT2
 *  \param  copy_u8EXTI_SENSE 
 *  \return None
*************************************************************/
void MEXTI_voidIntEnable(u8 copy_u8EXTI_NUM, u8 copy_u8EXTI_SENSE);

/*************************************************************
 *  \fn     void MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM); 
 *  \brief  Disable External Interrupt
 *  \param  copy_u8EXTI_NUM EXTI_INT0 || EXTI_INT1 || EXTI_INT2 
 *  \return None
*************************************************************/
void MEXTI_voidIntDisable(u8 copy_u8EXTI_NUM);
void MEXTI_voidSetCallBack(void (*copy_ptrToFunction)(void), u8 copy_u8Index);


#endif
