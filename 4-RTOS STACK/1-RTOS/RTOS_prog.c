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

void RTOS_voidCreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, void (*copy_pvTaskFunc)(void))
{
    /* Set Task's Periodicity */
    System_Tasks[copy_u8Priority].Periodicity = copy_u16Periodicity;

    /* Set Task's Notification function */
    System_Tasks[copy_u8Priority].Taskfunc = copy_pvTaskFunc;
}
static void voidScheduler(void)
{
    static u16 local_u16TickCounter = 0;
    u8 local_u8TaskCounter;
    local_u16TickCounter++;

    /* loop on all tasks to check their periodicity*/
    for (local_u8TaskCounter = 0; local_u8TaskCounter < RTOS_TASK_NUMBER; local_u8TaskCounter++)
    {
        if (((65535 - local_u16TickCounter) / System_Tasks[local_u8TaskCounter].Periodicity) == 0)
        {
            local_u16TickCounter = 65535 - local_u16TickCounter;
            break;
        }

        if ((local_u16TickCounter % System_Tasks[local_u8TaskCounter].Periodicity) == 0)
        {
            /* Invoke Task Counter */
            if (System_Tasks[local_u8TaskCounter].Taskfunc == NULL)
            {
                /* Do nothing */
            }
            else
            {
                System_Tasks[local_u8TaskCounter].Taskfunc();
            }
        }
    }
}