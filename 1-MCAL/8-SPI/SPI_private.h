/************************************************************************************************
 * @file        SPI_private.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       SPI Driver - MCAL
 *              Describes the register definitions and bits definitions
 * @version     0.1
 * @date        2022-04-27
 * @copyright   Copyright (c) 2022
 ************************************************************************************************/
#ifndef SPI_PRIVATE_
#define SPI_PRIVATE_
/************************************************************************************************/
/** \defgroup SPI SPI Register Definitions                                                      */
/** @{                                                                                          */
#define SPI_SPCR_REGISTER           *((volatile u8 *) 0x2D) /**< SPCR   : SPI Control Register  */
#define SPI_SPSR_REGISTER           *((volatile u8 *) 0x2E) /**< SPSR   : SPI Status Register   */
#define SPI_SPDR_REGISTER           *((volatile u8 *) 0x2F) /**< SPDR   : SPI Data Register     */
/************************************************************************************************/
/** \defgroup SPI_SPCR SPCR Register Bits                                                       */
/** @{                                                                                          */
#define SPI_SPCR_SPIE               7   /**< SPIE   : SPI Interrupt Enable                      */ 
#define SPI_SPCR_SPE                6   /**< SPE    : SPI Enable                                */ 
#define SPI_SPCR_DORD               5   /**< DORD   : Data Order                                */
#define SPI_SPCR_MSTR               4   /**< MSTR   : Master/Slave Select                       */
#define SPI_SPCR_CPOL               3   /**< CPOL   : Clock Polarity                            */
#define SPI_SPCR_CPHA               2   /**< CPHA   : Clock Phase                               */
#define SPI_SPCR_SPR1               1   /**< SPR1   : SPI Clock Rate Select (1)                 */
#define SPI_SPCR_SPR0               0   /**< SPR0   : SPI Clock Rate Select (0)                 */
/** @}                                                                                          */
/************************************************************************************************/
/** \defgroup  SPI_SPSR SPSR Register Bits                                                      */
/** @{                                                                                          */
#define SPI_SPSR_SPIF               7   /**< SPIF : SPI Interrupt Flag                          */ 
#define SPI_SPSR_WCOL               6   /**< WCOL : Write COLlision Flag                        */ 
#define SPI_SPSR_SPI2               0   /**< SPI2 : SPI Clock Rate Select (2)                   */
/** @}                                                                                          */
/** @}                                                                                          */
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/** \defgroup  Configuration Options                                                            */
/** @{                                                                                          */
#define SPI_LSB                 1   /**< the LSB of the data word is transmitted first.         */ 
#define SPI_MSB                 2   /**< the LSB of the data word is transmitted first.         */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define SPI_IDLE_HIGH           1   /**< SCK is high when idle                                  */
#define SPI_IDLE_LOW            2   /**< SCK is LOW when idle                                   */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define SPI_SETUP_ON_LEADING    1   /**< Data is setup on the leading edge of Clock             */
#define SPI_SETUP_ON_TRAILING   2   /**< Data is setup on the Falling edge of Clock             */
//////////////////////////////////////////////////////////////////////////////////////////////////
#define DIVISION_FACTOR_2       4   /**< Division Factor: 2                                     */
#define DIVISION_FACTOR_4       0   /**< Division Factor: 4                                     */
#define DIVISION_FACTOR_8       5   /**< Division Factor: 8                                     */
#define DIVISION_FACTOR_16      1   /**< Division Factor: 16                                    */
#define DIVISION_FACTOR_32      6   /**< Division Factor: 32                                    */
#define DIVISION_FACTOR_64      7   /**< Division Factor: 64                                    */
#define DIVISION_FACTOR_128     3   /**< Division Factor: 128                                   */
/** @}                                                                                          */
/************************************************************************************************/
#define SPI_SPCR_CLOCK_MUSK     0b11111100   /**< SPI Clock Musk Value for SPCR Register        */
#define SPI_SPSR_CLOCK_MUSK     0b11111110   /**< SPI Clock Musk Value for SPSR Register        */



#endif