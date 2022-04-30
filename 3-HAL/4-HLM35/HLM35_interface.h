/**********************************************************
 * @file        HLM35_interface.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       LM35 Driver - HAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/

/**********************************************************
 *  \fn     void HLM35_voidInit(void);
 *  \brief  Intialize LM35 
 *  \return None
**********************************************************/
void HLM35_voidInit(void);    

/**********************************************************
 *  \fn     u16 HLM35_u16GetSensorReading(void); 
 *  \brief  Gets LM35 Temperature Sensor Reading 
 *  \param  \c void
 *  \return \c u16 Temperature Reading
**********************************************************/
u16 HLM35_u16GetSensorReading(void);