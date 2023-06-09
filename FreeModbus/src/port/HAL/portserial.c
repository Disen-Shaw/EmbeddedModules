/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"

/* ----------------------- static functions ---------------------------------*/
static void prvvUARTTxReadyISR(void);
static void prvvUARTRxISR(void);

/* ----------------------- Start implementation -----------------------------*/
void vMBPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{
    /* If xRXEnable enable serial receive interrupts. If xTxENable enable
     * transmitter empty interrupts.
     */
    if (xRxEnable)
        __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
    else
        __HAL_UART_DISABLE_IT(&huart2, UART_IT_RXNE);

    if (xTxEnable)
        __HAL_UART_ENABLE_IT(&huart2, UART_IT_TXE);
    else
        __HAL_UART_DISABLE_IT(&huart2, UART_IT_TXE);
}

BOOL xMBPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity)
{
    // Initialized already in HAL usart.c
    return TRUE;
}

BOOL xMBPortSerialPutByte(CHAR ucByte)
{
    /* Put a byte in the UARTs transmit buffer. This function is called
     * by the protocol stack if pxMBFrameCBTransmitterEmpty( ) has been
     * called. */
    if (HAL_UART_Transmit(&huart2, (uint8_t*)&ucByte, 1, 10) != HAL_OK)
        return FALSE;
    else
        return TRUE;
}

BOOL xMBPortSerialGetByte(CHAR* pucByte)
{
    /* Return the byte in the UARTs receive buffer. This function is called
     * by the protocol stack after pxMBFrameCBByteReceived( ) has been called.
     */
    if (HAL_UART_Receive(&huart2, (uint8_t*)pucByte, 1, 10) != HAL_OK)
        return FALSE;
    else
        return TRUE;
}

/* Create an interrupt handler for the transmit buffer empty interrupt
 * (or an equivalent) for your target processor. This function should then
 * call pxMBFrameCBTransmitterEmpty( ) which tells the protocol stack that
 * a new character can be sent. The protocol stack will then call
 * xMBPortSerialPutByte( ) to send the character.
 */
static void prvvUARTTxReadyISR(void)
{
    pxMBFrameCBTransmitterEmpty();
}

/* Create an interrupt handler for the receive interrupt for your target
 * processor. This function should then call pxMBFrameCBByteReceived( ). The
 * protocol stack will then call xMBPortSerialGetByte( ) to retrieve the
 * character.
 */
static void prvvUARTRxISR(void)
{
    pxMBFrameCBByteReceived();
}

/** 
 * @brief USARTx IRQ handler
 *
 * @attention
 *      need to change USARTx to your peripheral.
 */
// void USARTx_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huartx);
//
//   if(__HAL_UART_GET_IT_SOURCE(&huartx, UART_IT_RXNE)!=RESET)
// 	  prvvUARTRxISR();
//   
//   if(__HAL_UART_GET_IT_SOURCE(&huartx, UART_IT_TXE)!=RESET)
// 	  prvvUARTTxReadyISR();
//   
//   HAL_NVIC_ClearPendingIRQ(USARTx_IRQn);
//   HAL_UART_IRQHandler(&huartx);
//   
// }
//
