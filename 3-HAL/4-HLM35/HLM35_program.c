/**********************************************************
 * @file        HLM35_program.c
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       LM35 Driver - HAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/

#include "STD_TYPES.h"

#include "HLM35_interface.h"
#include "HLM35_config.h"
#include "HLM35_private.h"
#include "MADC_interface.h"

void HLM35_voidInit(void)
{
    MADC_voidADCInit();
}
u16 HLM35_u16GetSensorReading(void)
{
    u16 local_u16MilliVolt = 0;
     local_u16MilliVolt =(u16) ((u32)MADC_u16GetChannelReading(HLM35_CHANNEL) * 5000UL)/256UL;
    return local_u16MilliVolt/10;
}