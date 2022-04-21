/*************************************************************
 * @file      GIE_interface.h
 * @author 	  Yasssr Mustafa
 * @brief 	  Global interrupt Enable (GIE) Driver - MCAL
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/ 

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

/*************************************************************
 *  \fn     void GIE_voidEnable(void); 
 *  \brief  Enable GIE
 *  \param  None
 *  \return None
*************************************************************/
void GIE_voidEnable(void);

/*************************************************************
 *  \fn     void GIE_voidDisable(void); 
 *  \brief  Disable GIE
 *  \param  None
 *  \return None
*************************************************************/
void GIE_voidDisable(void);

#endif