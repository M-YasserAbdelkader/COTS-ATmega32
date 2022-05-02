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

/****************************************************************************************************************
 * \fn      void RTOS_voidStart(void);
 * \brief   Starts RTOS
 * \return  None
 ****************************************************************************************************************/
void RTOS_voidStart(void);

u8 RTOS_u8CreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, void (*copy_pvTaskFunc)(void), u16 copy_u16FirstDelay);

/****************************************************************************************************************
 * \fn      void RTOS_voidSuspendTask(u8 copy_u8Priority);
 * \brief   Suspend  Ready Task Given its priority
 * \param   copy_u8Priority u8 Priority
 * \return  None
 ****************************************************************************************************************/
void RTOS_voidSuspendTask(u8 copy_u8Priority);

/****************************************************************************************************************
 * \fn      void RTOS_voidResumeTask(u8 copy_u8Priority);
 * \brief   Resume suspended Task Given its priority
 * \param   copy_u8Priority u8 Priority
 * \return  None
 ****************************************************************************************************************/
void RTOS_voidResumeTask(u8 copy_u8Priority);

/****************************************************************************************************************
 * \fn      void RTOS_voidDeleteTask(u8 copy_u8Priority);
 * \brief   Delete Ready or Suspended Task Given its priority
 * \param   copy_u8Priority u8 Priority
 * \return  None
 ****************************************************************************************************************/
void RTOS_voidDeleteTask(u8 copy_u8Priority);

#endif