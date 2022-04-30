/****************************************************************************************************************
 * @file        SPI_config.h
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       SPI Driver - MCAL
 *              Sets the preconfiguration needed for functions
 * @version     0.1
 * @date        2022-04-27
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/
#ifndef _SPI_CONFIG_
#define _SPI_CONFIG_

/****************************************************************************************************************
 * \def     SPI_DATA_ORDER
 * \brief   Select Data Order
 * \details The following options are availble:
 * \arg \c  SPI_LSB     the LSB of the data word is transmitted first.
 * \arg \c  SPI_MSB     the MSB of the data word is transmitted first.
 ****************************************************************************************************************/
#define SPI_DATA_ORDER      SPI_LSB

/****************************************************************************************************************
 * \def     SPI_CLOCK_POLARITY
 * \brief   Select Clock Polarity
 * \details The following options are availble:
 * \arg \c  SPI_IDLE_HIGH   SCK is high when idle
 * \arg \c  SPI_IDLE_LOW    SCK is low when idle.
 * ////////////////////////////////////////////////////////////////////
 * //    Clock Polarity  //   Leading Edge    //   Trailing Edge     //
 * ////////////////////////////////////////////////////////////////////
 * //    SPI_IDLE_LOW    //      Rising      //     Falling          //
 * //    SPI_IDLE_HIGH   //      Falling     //      Rising          //
 * ////////////////////////////////////////////////////////////////////
 *        
 ****************************************************************************************************************/
#define SPI_CLOCK_POLARITY  SPI_IDLE_HIGH

/****************************************************************************************************************
 * \def     SPI_CLOCK_PHASE
 * \brief   Select Clock Phase
 * \details The following options are availble:
 * \arg \c  SPI_SETUP_ON_LEADING    Data is setup on the leading edge and sampled on trailing edge of the clock
 * \arg \c  SPI_SETUP_ON_TRAILING   Data is setup on the trailing edge and sampled on leading edge of the clock
 * ////////////////////////////////////////////////////////////////////////////
 * //    Clock phase             //   Leading Edge   //   Trailing Edge      //
 * ////////////////////////////////////////////////////////////////////////////
 * //    SPI_SETUP_ON_LEADING    //      Sample      //     Setup            //
 * //    SPI_SETUP_ON_TRAILING   //      Setup       //     Sample           //
 * ////////////////////////////////////////////////////////////////////////////
 *        
 ****************************************************************************************************************/
#define SPI_CLOCK_PHASE     SPI_SETUP_ON_LEADING

/****************************************************************************************************************
 * \def     SPI_DATA_ORDER
 * \brief   Select SPI Clock Rate 
 * \details The following options are availble:
 * \arg \c  DIVISION_FACTOR_2     Clock Rate: f/2
 * \arg \c  DIVISION_FACTOR_4     Clock Rate: f/4
 * \arg \c  DIVISION_FACTOR_8     Clock Rate: f/8
 * \arg \c  DIVISION_FACTOR_16    Clock Rate: f/16
 * \arg \c  DIVISION_FACTOR_32    Clock Rate: f/32
 * \arg \c  DIVISION_FACTOR_64    Clock Rate: f/64
 * \arg \c  DIVISION_FACTOR_128   Clock Rate: f/128
 ****************************************************************************************************************/
#define SPI_CLOCK_RATE  DIVISION_FACTOR_2
#endif