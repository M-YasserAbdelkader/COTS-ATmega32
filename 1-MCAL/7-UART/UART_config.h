/****************************************************************************************************************
 * @file        UART_config.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       USART Driver - MCAL
 * @version     0.1
 * @date        2022-04-25
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/****************************************************************************************************************
 * \def     USART_MODE_SELECT
 * \brief   USART Mode Select
 *          selects between Asynchronous and Synchronous mode of operation
 * \details The following options are availble:
 * \arg \c  USART_ASYNCH_MODE    Asynchronous mode of operation
 * \arg \c  USART_SYNCH_MODE     Synchronous mode of operation
 ****************************************************************************************************************/
#define USART_MODE_SELECT USART_ASYNCH_MODE

/****************************************************************************************************************
 * \def     USARt_PARITY_MODE
 * \brief   Parity Mode Select
 *          enable and set type of parity generation and check.
 * \details The following options are availble:
 * \arg \c  USART_DISABLED_PARITY   Disabled
 * \arg \c  USART_EVEN_PARITY       Enabled, Even Parity
 * \arg \c  USART_ODD_PARITY        Enabled, Odd Parity
 ****************************************************************************************************************/
#define USARt_PARITY_MODE   USART_ODD_PARITY
/****************************************************************************************************************
 * \def     USART_STOP_BIT_SELECT
 * \brief   Stop Bit Select
 *          selects the number of Stop Bits to be inserted by the Transmitter. The Receiver
 *          ignores this setting.
 * \details The following options are availble:
 * \arg \c  USART_1_BIT_STOP    1-Bit Stop
 * \arg \c  USART_2_BIT_STOP    2-Bit Stop
 ****************************************************************************************************************/
#define USART_STOP_BIT_SELECT USART_1_BIT_STOP

/****************************************************************************************************************
 * \def     USART_CHAR_SIZE
 * \brief   Character Size Select
 *          sets the number of data bits
 *          (Character Size) in a frame the Receiver and Transmitter use.
 * \details The following options are availble:
 * \arg \c  USART_5_BIT_SIZE    5-Bit character size
 * \arg \c  USART_6_BIT_SIZE    6-Bit character size
 * \arg \c  USART_7_BIT_SIZE    7-Bit character size
 * \arg \c  USART_8_BIT_SIZE    8-Bit character size
 * \arg \c  USART_9_BIT_SIZE    9-Bit character size
 ****************************************************************************************************************/
#define USART_CHAR_SIZE USART_5_BIT_SIZE

/****************************************************************************************************************
 * \def     USART_BAUD_RATE
 * \brief   Baud Rate Select
 *          Selects the Baud Rate (f = 8 MHZ)    
 ****************************************************************************************************************/
#define USART_BAUD_RATE     9600  

/****************************************************************************************************************
 * \def     USART_RECIEVE_ENABLE
 * \brief   Enable/ Disable recieve Mode
 * \details The following options are availble:
 * \arg \c  ENABLE    Enable Recieve
 * \arg \c  DISABLE   Disable recieve
 ****************************************************************************************************************/
#define USART_RECIEVE_ENABLE     ENABLE

/****************************************************************************************************************
 * \def     USART_TRANSMIT_ENABLE
 * \brief   Enable/ Disable transmit Mode
 * \details The following options are availble:
 * \arg \c  ENABLE    Enable Transmit
 * \arg \c  DISABLE   Disable Transmit
 ****************************************************************************************************************/
#define USART_TRANSMIT_ENABLE     ENABLE
#endif

