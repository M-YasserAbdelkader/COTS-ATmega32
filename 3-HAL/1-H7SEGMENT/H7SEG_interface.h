/*
 * H7SEG_interface.h
 *
 *  Created on: Jan 17, 2022
 *      Author: yasse
 */

#ifndef INCLUDE_3_HAL_1_H7SEGMENT_H7SEG_INTERFACE_H_
#define INCLUDE_3_HAL_1_H7SEGMENT_H7SEG_INTERFACE_H_

#define H7SEGMENT_NUMBER_INIT	H7SEGMENT_ZERO

#define ZERO	H7SEGMENT_ZERO
#define ONE		H7SEGMENT_ONE
#define TWO		H7SEGMENT_TWO
#define THREE	H7SEGMENT_THREE
#define FOUR	H7SEGMENT_FOUR
#define FIVE	H7SEGMENT_FIVE
#define SIX		H7SEGMENT_SIX
#define SEVEN	H7SEGMENT_SEVEN
#define EIGHT	H7SEGMENT_EIGHT
#define NINE	H7SEGMENT_NINE

/************************************************************************/
/*	Function: H7seg_voidInit											*/
/*	I/p Parameters: Nothing 											*/
/*	O/P Parameters: Nothing												*/
/************************************************************************/
void H7Seg_voidInit(void);

/************************************************************************/
/*	Function: H7Seg_voidDispalyNumber									*/
/*	I/p Parameters: Number to display 									*/
/*	O/P Parameters: Nothing												*/
/************************************************************************/
/*	Options																*/
/*	copy_u8Number: 	From: ZERO	To:	NINE								*/
/************************************************************************/
void H7Seg_voidDispalyNumber(u8 copy_u8Number);


#endif /* INCLUDE_3_HAL_1_H7SEGMENT_H7SEG_INTERFACE_H_ */
