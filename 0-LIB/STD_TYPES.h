/*
* HLCD_interface.h
*
* Created on   : Jan 5, 2022
* Author	   : Yasser Mustafa Ahmed
* Program      : Intensive Code Camp
* Organization : ITI Alex
 */
#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;

/** \defgroup Error Status */
/** @{ */
#define OK                      0   /**< Error Status: Ok                   */
#define NOK                     1   /**< Error Status: Not Ok               */
#define TIMEOUT       2   /**< Error Status: Conversion Timeout   */
#define NULL_POINTER            3   /**< Error Status: Null Pointer         */
#define BUSY_FUNCTION           4   /**< Error Status: Null Pointer         */
/** @} */

#define NULL                    (void *) 0
#define IDLE                    0
#define BUSY                    1

#endif
