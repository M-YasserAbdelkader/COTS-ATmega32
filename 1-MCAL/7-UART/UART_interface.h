/************************************************************************
 * @file        UART_interface.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       USART Driver - MCAL -Interface Files
 *              Describes the functions and Macros used by the user
 * @version     0.1
 * @date        2022-04-25
 * @copyright   Copyright (c) 2022
 ************************************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/**
 * @brief Intialize UART device
 * @arg None
 * @return void return
 * \todo configurable
 */
void MUSART_voidInit(void);

/**
 * @brief 
 * 
 */
u8 MUSART_u8SendCharSynch(u16* copy_pu8Data);
u8 MUSART_u8SendCharAsynch(u16 copy_u16Data, void(* copy_pvNotificationFunc)(void));
u8 MUSART_u8SendStringAsynch(u8* copy_pu8String, void(* copy_pvNotificationFunc)(void));
u8 MUSART_u8SendStringSynch(u8* copy_pu8String);

u8 MUSART_u8ReceiveCharSynch(u16* copy_pu8Data);
u8 MUSART_u8ReceiveCharAsynch(u16* copy_pu16Data, void(* copy_pvNotificationFunc)(void));
u8 MUSART_u8Recieve(void);

#endif