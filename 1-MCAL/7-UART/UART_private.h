/************************************************************************
 * @file        UART_private.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       USART Driver - MCAL
 * @version     0.1
 * @date        2022-04-25
 * @copyright   Copyright (c) 2022
 ************************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
#define SYS_OSCILLAOR_FREQ  8000000
/************************************************************************************************/
/** \defgroup  Configuration Options                                                            */
/** @{                                                                                          */
#define USART_ASYNCH_MODE   1   /**< Asynchronous mode of operation         */ 
#define USART_SYNCH_MODE    2   /**< Synchronous mode of operation         */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define USART_DISABLED_PARITY       3   /**< Disable Parity                                  */
#define USART_EVEN_PARITY           1   /**< Enable, Even Parity                                  */
#define USART_ODD_PARITY            2   /**< Enable, Odd Parity */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define USART_1_BIT_STOP    1   /**< 1-Bit Stop             */
#define USART_2_BIT_STOP   2   /**< 2-Bit Stop             */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define USART_5_BIT_SIZE       0   /**< Character Size: 5                                     */
#define USART_6_BIT_SIZE       1   /**< Character Size: 6                                     */
#define USART_7_BIT_SIZE       2   /**< Character Size: 7                                     */
#define USART_8_BIT_SIZE      3   /**< Character Size: 8                                    */
#define USART_9_BIT_SIZE      4   /**< Character Size: 9                                    */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ENABLE  1
#define DISABLE 2
/** @}                                                                                          */
/************************************************************************************************/
#define UART_UCSRC_MUSK 0b11111001
#define UART_UCSRB_MUSK 0b11111001
#define USART_UBRR_VAlUE   (u16)((SYS_OSCILLAOR_FREQ /(16UL * USART_BAUD_RATE)) - 1) 
#define USART_U32_TIMEOUT   50000 
#endif 