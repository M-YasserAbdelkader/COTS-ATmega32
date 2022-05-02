/****************************************************************************************************************
 * @file        RTOS_private.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       RTOS stack
 * @version     0.1
 * @date        2022-04-30
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef _RTOS_PRIVATE_H_
#define _RTOS_PRIVATE_H_

typedef struct
{
    u16 Periodicity;
    void (*Taskfunc)(void);
    u8 State;
    u16 FirstDelay;
} Task_t;


#define TASK_RESUMED    1
#define TASK_SUSPENDED  0

#define TASK_TIME       0

static void voidScheduler(void);
#endif