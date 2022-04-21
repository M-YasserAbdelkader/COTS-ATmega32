/**
 * @file UART_prog.c
 * @author Yasser Mustafa (yassermessi01@gmail.com)
 * @brief UART Registers
 * @note MCAL Layer 
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _UART_REGISTER_H_
#define _UART_REGISTER_H_
/**
 * @brief USART I/O Data Register 
 * 
 */
#define UART_UDR_REGISTER       0x2C

/**
 * @brief USART Control and Status Register A
 * 
 */
#define UART_UCSRA_REGISTER     0x2B 

/**
 * @brief USART Recieve Complete
 * Reads 1 when there are unread data in the receive buffer
 * Reads 0 when receive buffer is empty 
 * 
 */
#define UART_UCSRA_RXC          7

/**
 * @brief USART Transmit Complete
 * Reads 1 when the entire data is shifted and sent and no new data is present 
 * 
 */
#define UART_UCSRA_TXC          6

/**
 * @brief USART Data Register Empty
 * If UDRE is one, the buffer is empty, and therefore ready to be written.
 * 
 */
#define UART_UCSRA_UDRE         5


/**
 * @brief USART Control and Status Register B
 * 
 */
#define UART_UCSRB_REGISTER     0x2A

/**
 * @brief RXEN Receiver Enable
 * 
 */
#define UART_UCSRB_RXEN         4
/**
 * @brief TXEN: Transmitter Enable
 * 
 */
#define UART_UCSRB_TXEN         3

/**
 * @brief UCSZ2: Character Size
 * 
 */
#define UART_UCSRB_UCSZ2         2

/**
 * @brief USART Control and Status Register C
 * 
 */
#define UART_UCSRC_REGISTER     0x40

/**
 * @brief USART Baud Rate Registers - UBRRL and UBRRH
 * 
 */
#define UART_UBRRL_REGISTER     0x29
#define UART_UBRRH_REGISTER     0x40


#endif