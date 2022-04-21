/*
 * H7SEG_program.c
 *
 *  Created on: Jan 17, 2022
 *      Author: yasse
 */

#include "../../2-LIB/STD_TYPES.h"
#include "../../2-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "H7SEG_interface.h"
#include "H7SEG_configuration.h"
#include "H7SEG_private.h"

/************************************************************************/
/*	Function: H7seg_voidInit											*/
/*	I/p Parameters: Nothing 											*/
/*	O/P Parameters: Nothing												*/
/************************************************************************/
void H7Seg_voidInit(void)
{
	MDIO_voidInit();
	MDIO_voidSetPortDirection(H7SEGMENT_PORT, 0xff);
	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_NUMBER_INIT);
}

/************************************************************************/
/*	Function: H7Seg_voidDispalyNumber									*/
/*	I/p Parameters: Number to display 									*/
/*	O/P Parameters: Nothing												*/
/************************************************************************/
void H7Seg_voidDispalyNumber(u8 copy_u8Number)
{
	switch(copy_u8Number)
	{
	case ZERO: 	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_ZERO); break;
	case ONE:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_ONE); break;
	case TWO:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_TWO); break;
	case THREE:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_THREE); break;
	case FOUR:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_FOUR); break;
	case FIVE:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_FIVE); break;
	case SIX:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_SIX); break;
	case SEVEN:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_SEVEN); break;
	case EIGHT:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_EIGHT); break;
	case NINE:	MDIO_voidSetPortValue(H7SEGMENT_PORT, H7SEGMENT_NINE); break;
	}
}
