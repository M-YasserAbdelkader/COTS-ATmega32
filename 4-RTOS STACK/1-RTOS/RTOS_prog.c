/****************************************************************************************************************
 * @file        RTOS_prog.c
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       RTOS Stack
 * @version     0.1
 * @date        2022-04-30
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#include "STD_TYPES.h"

#include "MTIMER_interface.h"
#include "GIE_interface.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

Task_t System_Tasks[RTOS_TASK_NUMBER] = {{0}};

void RTOS_voidStart(void)
{
    /* Set Calll back func of Timer0 to voidSheduler */
    TIMER0_u8SetCallBack(&voidScheduler);

    /* Enable Global Interrupt */
    GIE_voidEnable();

    /* Initiate Timer 0 as part of RTOS stack */
    MTIMER0_voidInit();
}

u8 RTOS_u8CreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, void (*copy_pvTaskFunc)(void), u16 copy_u16FirstDelay)
{
    u8 local_u8ErrorState = OK;

    /* Check if the requered priority is empty or used by another task */
    if (System_Tasks[copy_u8Priority].Taskfunc != NULL)
    {
        /* Priority is Reserved. Do not Create Task */
        local_u8ErrorState = NOK;
    }
    else
    {
        /* Set Task's Periodicity */
        System_Tasks[copy_u8Priority].Periodicity = copy_u16Periodicity;

        /* Set Task's Notification function */
        System_Tasks[copy_u8Priority].Taskfunc = copy_pvTaskFunc;

        /* Initialize task state */
        System_Tasks[copy_u8Priority].State = TASK_RESUMED;

        /* Impelemt first delay for each task*/
        System_Tasks[copy_u8Priority].FirstDelay = copy_u16FirstDelay;
    }
    return local_u8ErrorState;
}
static void voidScheduler(void)
{
    u8 local_u8TaskCounter;

    /* loop on all tasks to check their periodicity*/
    for (local_u8TaskCounter = 0; local_u8TaskCounter < RTOS_TASK_NUMBER; local_u8TaskCounter++)
    {
        /* Invoke Task Counter */
        if (System_Tasks[local_u8TaskCounter].Taskfunc == NULL)
        {
            continue;
        }

        /* Check if task is suspended */
        if (TASK_SUSPENDED == System_Tasks[local_u8TaskCounter].State)
        {
            continue;
        }

        if (System_Tasks[local_u8TaskCounter].FirstDelay != TASK_TIME)
        {
            /* Decrement First Delay */
            System_Tasks[local_u8TaskCounter].FirstDelay--;
        }
        else
        {
            System_Tasks[local_u8TaskCounter].Taskfunc();
            System_Tasks[local_u8TaskCounter].FirstDelay = System_Tasks[local_u8TaskCounter].Periodicity - 1;
        }
    }
}

void RTOS_voidSuspendTask(u8 copy_u8Priority)
{
    /* Update Task's State */
    System_Tasks[copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 copy_u8Priority)
{
    /* Update Task's State */
    System_Tasks[copy_u8Priority].State = TASK_RESUMED;
}

void RTOS_voidDeleteTask(u8 copy_u8Priority)
{
    System_Tasks[copy_u8Priority].Taskfunc = NULL;
}