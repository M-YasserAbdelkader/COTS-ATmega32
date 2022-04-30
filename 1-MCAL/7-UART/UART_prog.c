/************************************************************************
 * @file        UART_program.c
 * @author      Yasser M. Abdelkader (m.abdelkader.yasser@gmail.com)
 * @brief       USART Driver - MCAL
 * @version     0.1
 * @date        2022-04-25
 * @copyright   Copyright (c) 2022
 ************************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include"UART_interface.h"
#include"UART_private.h"
#include"UART_register.h"
#include"UART_config.h"

static u16* USART_pu16Reading = NULL; 
static void (*USART_pvCallBackNotificationFunc)(void) = NULL;

void MUSART_voidInit(void)
{
    u8 local_u8UCSRCRegisterValue = 0;
    u16 local_u8UbrrValue = USART_UBRR_VAlUE;

    /* Access UCSRC Register for write operation */
    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_URSEL);

    /* choose mode of operation */
#if USART_MODE_SELECT == USART_ASYNCH_MODE

    CLR_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UMSEL);
    
#elif USART_MODE_SELECT == USART_SYNCH_MODE

    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UMSEL);
#elif

#error "'Wrong Mode of Operation Selection"
#endif

    /* Choose Partiy mode */
#if USARt_PARITY_MODE == USART_EVEN_PARITY

    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM1);
    CLR_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM0); 

#elif USARt_PARITY_MODE == USART_ODD_PARITY

    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM1);
    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM0);

#elif USARt_PARITY_MODE == USART_DISABLED_PARITY

    CLR_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM1);
    CLR_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UPM0);
#else
#error "Wrong Parity Mode Select"
#endif

    /* Choose Number of Stop bit(s) */
#if     USART_STOP_BIT_SELECT == USART_1_BIT_STOP
    CLR_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_USBS);
#elif   USART_STOP_BIT_SELECT == USART_2_BIT_STOP
    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_USBS);
#else
#error "Wron  Stop Bit(s) Selection"
#endif
    

    /* Choose Character Size (8-bit) */ 
#if (USART_CHAR_SIZE >= USART_5_BIT_SIZE) && (USART_CHAR_SIZE <= USART_8_BIT_SIZE)

    CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_UCSZ2);
    local_u8UCSRCRegisterValue &= UART_UCSRC_MUSK;
    local_u8UCSRCRegisterValue |= (USART_CHAR_SIZE << 1); 

#elif USART_CHAR_SIZE == USART_9_BIT_SIZE

    SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_UCSZ2);
    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UCSZ1);
    SET_BIT(local_u8UCSRCRegisterValue, UART_UCSRC_UCSZ0);
#else
#error "Wrong Character Size Selection"
#endif

    /* Update UCSRC Register */
    UART_UCSRC_REGISTER = local_u8UCSRCRegisterValue;
    
    /*choose Baud Rate (9600 bps) f = 8 MHZ */
    UART_UBRRL_REGISTER = (u8)local_u8UbrrValue;
    local_u8UCSRCRegisterValue >>= 8;
    CLR_BIT(local_u8UCSRCRegisterValue, 7);
    UART_UBRRH_REGISTER = (u8)local_u8UCSRCRegisterValue;  

    /* Enable/Disable Receiver */
#if     USART_TRANSMIT_ENABLE == ENABLE

    SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXEN);

#elif   USART_TRANSMIT_ENABLE == DISABLE

    CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXEN);

#else
#error "Wrnog Recieve Enable/ Disable Selection"
#endif

    /* Enable/Disable Transmitter */
#if     USART_TRANSMIT_ENABLE == ENABLE

    SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXEN);

#elif   USART_TRANSMIT_ENABLE == DISABLE

    CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXEN);

#else
#error "Wrnog Transmit Enable/ Disable Selection"
#endif
}

u8 MUSART_u8SendCharSynch(u16* copy_pu16Data)
{
    u8 local_u8ErrorState = OK;
    u32 local_u32TimeoutCounter = USART_U32_TIMEOUT;
    if (copy_pu16Data == NULL)
    {
        local_u8ErrorState = NULL_POINTER;
    }
    else
    {
        /* wait till Data register is empty*/
        while ((GET_BIT(UART_UCSRA_REGISTER, UART_UCSRA_UDRE) == 0) && (local_u32TimeoutCounter != 0))
        {
            local_u32TimeoutCounter--;
        }
        if (local_u32TimeoutCounter == 0)
        {
            local_u8ErrorState = TIMEOUT;
        }
        else
        {
            /* write Data to data buffer register */
#if USART_CHAR_SIZE == USART_9_BIT_SIZE

            if (GET_BIT(*copy_u8Data, 8) == 0)
            {
                CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXB8);
            }
            else
            {
                SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXB8);    
            }
#endif

            UART_UDR_REGISTER = (u8)*copy_pu16Data; 
        }
        
    }
    return local_u8ErrorState;
}

u8 MUSART_u8ReceiveCharSynch(u16* copy_pu16Data)
{
    u8 local_u8ErrorState = OK;
    u32 local_u32TimeoutCounter = USART_U32_TIMEOUT;
    if (GET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXCIE) != 0)
    {
        local_u8ErrorState = BUSY_FUNCTION;
    }
    else
    {
    /* check input validity*/
    if (copy_pu16Data == NULL)
    {
        local_u8ErrorState = NULL_POINTER;
    }
    else
    {
        *copy_pu16Data = 0;
        /* Wait till Receiving is compelete or timeout occurs */
        while ((GET_BIT(UART_UCSRA_REGISTER, UART_UCSRA_RXC) == 0) && (local_u32TimeoutCounter != 0))
        {
            local_u32TimeoutCounter--;
        }
        /* Check if timeout occured */
        if (local_u32TimeoutCounter == 0)
        {
            local_u8ErrorState = TIMEOUT;
        }
        else
        {
#if USART_CHAR_SIZE == USART_9_BIT_SIZE

            /* check and update 9th bit*/
            if (GET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_BXB8) == 0)
            {
                CLR_BIT(*copy_pu16Data, 8);
            }
            else
            {
                SET_BIT(*copy_pu16Data, 8);    
            }
#endif
            /* Read the 8 bit data from data buffer register */
            *copy_pu16Data &= 0xff00;
            *copy_pu16Data |= (u8)UART_UDR_REGISTER;
        }
    }
    }
    
    /* Return Error State*/
    return local_u8ErrorState;   
}

u8 MUSART_u8SendCharAsynch(u16 copy_u16Data, void(* copy_pvNotificationFunc)(void))
{
    u8 local_u8ErrorState = OK;

    /* Check input validity */
    if (copy_pvNotificationFunc == NULL)
    {
        local_u8ErrorState = NULL_POINTER;
    }
    else
    {
        if (GET_BIT(UART_UCSRA_REGISTER, UART_UCSRA_UDRE) == 0)
        {
            local_u8ErrorState = BUSY_FUNCTION;
        }
        else
        {
            USART_pvCallBackNotificationFunc = copy_pvNotificationFunc;

            /* Enable Data Register Empty Interrupt */
            SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_UDRIE);
#if USART_CHAR_SIZE == USART_9_BIT_SIZE

            if (GET_BIT(*copy_u8Data, 8) == 0)
            {
                CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXB8);
            }
            else
            {
                SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_TXB8);    
            }
#endif

            UART_UDR_REGISTER = (u8)copy_u16Data; 

        }
        
    }

    return local_u8ErrorState;
    
}
void __vector_14(void)	 __attribute__((signal));
void __vector_14(void)
{
    /* Disable Data Register Empty Interrupt */
    CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_UDRIE);

    /*Invoke callback notification function */
	USART_pvCallBackNotificationFunc();
}

u8 MUSART_u8ReceiveCharAsynch(u16* copy_pu16Data, void(* copy_pvNotificationFunc)(void))
{
    u8 local_u8ErrorState = OK;

    if (GET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXCIE) != 0)
    {
        local_u8ErrorState = BUSY_FUNCTION;
    }
    else
    {
        /* Check input validity */
        if ((copy_pu16Data == NULL) || (copy_pvNotificationFunc == NULL))
        {
            local_u8ErrorState = NULL_POINTER;
        }
        else
        {
            *copy_pu16Data = 0;
            if (GET_BIT(UART_UCSRA_REGISTER, UART_UCSRA_RXC) == 0)
            {
                USART_pu16Reading = copy_pu16Data;
                USART_pvCallBackNotificationFunc = copy_pvNotificationFunc;

                /* Receive Complete Interrupt */
                SET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXCIE);
            }
        
        }  
    }
    return local_u8ErrorState;
}

void __vector_13(void)	 __attribute__((signal));
void __vector_13(void)
{
    /* Disable Data Register Empty Interrupt */
    CLR_BIT(UART_UCSRB_REGISTER, UART_UCSRB_RXCIE);
#if USART_CHAR_SIZE == USART_9_BIT_SIZE

            /* check and update 9th bit*/
            if (GET_BIT(UART_UCSRB_REGISTER, UART_UCSRB_BXB8) == 0)
            {
                CLR_BIT(*copy_pu16Data, 8);
            }
            else
            {
                SET_BIT(*USART_pu16Reading, 8);    
            }
#endif
            /* Read the 8 bit data from data buffer register */
            *USART_pu16Reading &= 0xff00;
            *USART_pu16Reading |= (u8)UART_UDR_REGISTER;
            USART_pvCallBackNotificationFunc();
}