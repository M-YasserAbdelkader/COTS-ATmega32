/****************************************************************************************************************
 * @file        SPI_programe.c
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       SPI Driver - MCAL
 *              Functions Implementation
 * @version     0.1
 * @date        2022-04-27
 * @copyright   Copyright (c) 2022
 ****************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidMasterInit(void)
{
    /* Disable interrupt*/
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_SPIE);

    /* Choose Data Order */
#if     SPI_DATA_ORDER == SPI_LSB
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#elif   SPI_DATA_ORDER == SPI_MSB
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#else
#warning "SPI Data Order is not configured correctly. SPI_LSB is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#endif

    /* Select Master SPI Mode */
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_MSTR);

    /* Choose Clock Polarity */
#if     SPI_CLOCK_POLARITY ==  SPI_IDLE_HIGH
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#elif   SPI_CLOCK_POLARITY ==  SPI_IDLE_LOW
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#else
#waring "SPI Clock polarity is not configured correctly. SPI_IDLE_LOW is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#endif
    

    /* choose Clock Phase ( Leading Edge -> Setup - Trailing Edge -> Sample) */    
#if     SPI_CLOCK_PHASE ==  SPI_SETUP_ON_LEADING
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#elif   SPI_CLOCK_PHASE ==  SPI_SETUP_ON_TRAILING
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#else
#waring "SPI Clock Phase is not configured correctly. SPI_SETUP_ON_TRAILING is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#endif 

    /* Set Clock Rate */
#if (SPI_CLOCK_RATE >=  DIVISION_FACTOR_4) && (SPI_CLOCK_RATE <=  DIVISION_FACTOR_64)   
    SPI_SPSR_REGISTER &= SPI_SPSR_CLOCK_MUSK;
    SPI_SPSR_REGISTER |= SPI_CLOCK_RATE / 4;
    SPI_SPCR_REGISTER &= SPI_SPCR_CLOCK_MUSK;
    SPI_SPCR_REGISTER |= SPI_SPCR_CLOCK_MUSK % 4;
#else
#error "Clock Rate is not cofigured properly"
#endif  

    /* Enable SPI*/
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_SPE);
}
void MSPI_voidSlaveInit(void)
{
        /* Disable interrupt*/
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_SPIE);
    /* Choose Data Order */
#if     SPI_DATA_ORDER == SPI_LSB
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#elif   SPI_DATA_ORDER == SPI_MSB
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#else
#warning "SPI Data Order is not configured correctly. SPI_LSB is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_DORD);
#endif

    /* Select Slave SPI Mode*/
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_MSTR);

    /* Choose Clock Polarity */
#if     SPI_CLOCK_POLARITY ==  SPI_IDLE_HIGH
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#elif   SPI_CLOCK_POLARITY ==  SPI_IDLE_LOW
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#else
#waring "SPI Clock polarity is not configured correctly. SPI_IDLE_LOW is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPOL);
#endif

    /* choose Clock Phase ( Leading Edge -> Setup - Trailing Edge -> Sample) */    
#if     SPI_CLOCK_PHASE ==  SPI_SETUP_ON_LEADING
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#elif   SPI_CLOCK_PHASE ==  SPI_SETUP_ON_TRAILING
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#else
#waring "SPI Clock Phase is not configured correctly. SPI_SETUP_ON_TRAILING is configured by default"
    CLR_BIT(SPI_SPCR_REGISTER, SPI_SPCR_CPHA);
#endif 

    /* Enable SPI*/
    SET_BIT(SPI_SPCR_REGISTER, SPI_SPCR_SPE);

}
u8 MSPI_u8Transceive(u8 copy_u8Data)
{
 SPI_SPDR_REGISTER = copy_u8Data;

 /* Polling till serial transfer is complete */
 /** \todo Time out constraint */
 while (GET_BIT(SPI_SPSR_REGISTER, SPI_SPSR_SPIF) == 0);

 /* Return Exchanged data*/
 return SPI_SPDR_REGISTER;
}