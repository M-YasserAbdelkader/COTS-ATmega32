/****************************************************************************************************************
 * @file        RTOS_interface.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       RTOS Stack
 * @version     0.1
 * @date        2022-04-30
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef _RTOS_INTERFACE_H_
#define _RTOS_INTERFACE_H_

void RTOS_voidStart(void);

void RTOS_voidCreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, void (*copy_pvTaskFunc)(void));

#endif