/****************************************************************************************************************
 * @file        UART_register.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       USART Driver - MCAL
 * @version     0.1
 * @date        2022-04-25
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef _UART_REGISTER_H_
#define _UART_REGISTER_H_
/****************************************************************************************************************/
/** \defgroup \c USART Register Definitions                                                                     */
/** @{                                                                                                          */
#define UART_UDR_REGISTER           *((volatile u8 *) 0x2C) /**< UDR    : USART Data Register                   */
#define UART_UCSRA_REGISTER         *((volatile u8 *) 0x2B) /**< UCSRA  : USART Control and Status Register A   */
#define UART_UCSRB_REGISTER         *((volatile u8 *) 0x2A) /**< UCSRB  : USART Control and Status Register B   */
#define UART_UCSRC_REGISTER         *((volatile u8 *) 0x40) /**< UCSRC  : USART Control and Status Register C   */
#define UART_UBRRL_REGISTER         *((volatile u8 *) 0x29) /**< UBRRL  : USART Baud Rate Register Low          */
#define UART_UBRRH_REGISTER         *((volatile u8 *) 0x40) /**< UBRRH  : USART Baud Rate Register High         */
/****************************************************************************************************************/
/** \defgroup \c UCSRA UCSRA Register Bits                                                                      */
/** @{                                                                                                          */
#define UART_UCSRA_RXC              7   /**< RXC    : USART Recieve Complete flag                               */ 
#define UART_UCSRA_TXC              6   /**< TXC    : USART Transmit Complete flag                              */ 
#define UART_UCSRA_UDRE             5   /**< UDRE   : USART Data Register Empty flag                            */
/** \todo Complete Register definitions                                                                         */
/** @}                                                                                                          */
/****************************************************************************************************************/
/** \defgroup \c UCSRB UCSRB Register Bits                                                                      */
/** @{                                                                                                          */
#define UART_UCSRB_RXCIE            7   /**< RXCIE  : RX Complete Interrupt Enable                              */
#define UART_UCSRB_TXCIE            6   /**< TXCIE  : TX Complete Interrupt Enable                              */
#define UART_UCSRB_UDRIE            5   /**< UDRIE  : USART Data Register Empty Interrupt Enable                */
#define UART_UCSRB_RXEN             4   /**< RXEN   : Receiver Enable                                           */
#define UART_UCSRB_TXEN             3   /**< TXEN   : Receiver Enable                                           */
#define UART_UCSRB_UCSZ2            2   /**< UCSZ2  : Character Size (2)                                        */ 
#define UART_UCSRB_RXB8             1   /**< RXB8: Receive Data Bit 8                                           */
#define UART_UCSRB_TXB8             0   /**< TXB8: Transmit Data Bit 8                                          */
/** @}                                                                                                          */
/****************************************************************************************************************/
/** \defgroup \c UCSRC UCSRC Register Bits                                                                      */
/** @{                                                                                                          */
#define UART_UCSRC_URSEL            7   /**< URSEL  : Register Select                                           */
#define UART_UCSRC_UMSEL            6   /**< UMSEL  : USART Mode Select                                         */
#define UART_UCSRC_UPM1             5   /**< UPM1   : Parity Mode (1)                                           */
#define UART_UCSRC_UPM0             4   /**< UPM2   : Parity Mode (2)                                           */
#define UART_UCSRC_USBS             3   /**< USBS   : Stop Bit Select                                           */
#define UART_UCSRC_UCSZ1            2   /**< UCSZ1  : Stop Bit Select(1)                                        */
#define UART_UCSRC_UCSZ0            1   /**< UCSZ0  : Stop Bit Select(0)                                        */
/** \todo Complete Register definitions                                                                         */
/** @}                                                                                                          */
/** @}                                                                                                          */
/****************************************************************************************************************/




#endif