/*************************************************************
 * @file        : EXTI_register.h
 * @author      : Yasser Mustafa
 * @brief       : External interrupt (EXTI) Driver - MCAL
 * @version     : 0.1
 * @date        : 2022-04-18
 * @copyright   : Copyright (c) 2022
 *************************************************************/

#ifndef EXTRI_REGISTER_H_
#define EXTRI_REGISTER_H_



#define GICR						*((volatile u8 *) 0x5b)

#define GICR_INT_1				    7
#define GICR_INT_0				    6
#define GICR_INT_2				    5

#define	GIFR						*((volatile u8 *) 0x5a)

#define GIFR_INT_1				    7
#define GIFR_INT_0				    6
#define GIFR_INT_2				    5


#define MCUCR						*((volatile u8 *) 0x55)

#define MCUCR_ISC00			        0
#define MCUCR_ISC01			        1
#define MCUCR_ISC10			        2
#define MCUCR_ISC11			        3


#define	MCUCSR					    *((volatile u8 *) 0x54)

#define MCUCSR_INT2			        6

#define GICR_INT0			        0
#define GICR_INT1			        1
#define GICR_INT2			        2




#define NULL				        (void*) 0

#endif
