/************************************************************************************************
 * @file        SPI_interface.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       SPI Driver - MCAL
 *              Describes the functions and Macros used by the user
 * @version     0.1
 * @date        2022-04-27
 * @copyright   Copyright (c) 2022
 ***********************************************************************************************/
#ifndef _SPI_INTERFACE_
#define _SPI_INTERFACE_
/************************************************************************************************
 * \fn      void MSPI_voidMasterInit(void);
 * \brief   Initiates MCU SPI communication protocol as Master
 * \return  void
 ***********************************************************************************************/
void MSPI_voidMasterInit(void);

/************************************************************************************************
 * \fn      void MSPI_voidSlaveInit(void);
 * \brief   Initiates MCU SPI communication protocol as Slave
 * \return  void
 ***********************************************************************************************/
void MSPI_voidSlaveInit(void);

/************************************************************************************************
 * \fn      MSPI_u8Transceive(u8 copy_u8Data);
 * \brief   Sends Or Receives Data
 * \param   copy_u8Data u8 Data to be sent in Transimit Mode
 * \return  u8 Data to be received in receive mode
 ***********************************************************************************************/
u8 MSPI_u8Transceive(u8 copy_u8Data);

u8 MSPI_u8TransceiveSynch(u8 *copy_pu8DataToBeReceived, u8 *copy_pu8DataToBeSent);
u8 MSPI_u8TransceiveAsynch(u8 *copy_pu8DataToBeReceived, u8 *copy_pu8DataToBeSent, void (*copy_pvNotificationFunc)(void));

#endif