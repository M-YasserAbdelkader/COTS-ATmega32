/**
 * @file UART_prog.c
 * @author Yasser Mustafa (yassermessi01@gmail.com)
 * @brief UART interface
 * @note MCAL Layer 
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/**
 * @brief Intialize UART device
 * @arg None
 * @return void return
 * 
 */
void USART_voidInit(void);

/**
 * @brief 
 * 
 */
void USART_voidSend(u8 copy_u8Data);

#endif