/*
 * debugUart.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */
#include "debugUart.h"
#include "commonDefines.h"
#include "uart.h"
#include "circularBuffer.h"
uint8_t data = 0;

sCircularBuffer_t * rxBuffer = NULL;

uint8_t commandReceivedFlag = 0;

uint16_t commandReceivedHead = 0;

void debugRxCallback(void)
{
	if(data == 0x0D)
	{
		commandReceivedFlag = 1;
	}

	circularBufferEnqueue(rxBuffer, (void * )&data);

	receptionItrOn(&data);

}

void debugTxCallback(void)
{

}

void debugUartInit(void)
{
	void * rxCallbackFptr = &debugRxCallback;

	circularBufferInit(rxBuffer, (uint16_t)512, (uint16_t)sizeof(uint8_t));

	uartInit(rxCallbackFptr);

	receptionItrOn(&data);
}



void debugPrint(void)
{
	uint8_t pData = 0;

	while(E_CBUFF_DEQUEUE_OK == circularBufferDequeue(rxBuffer, (void *)&pData))
	{
		HAL_UART_Transmit(&huart3, &pData, 1, 10);
	}

}

uint8_t getCmdReceivedFlag(void)
{
	return commandReceivedFlag;
}

void setCmdReceivedFlag(uint8_t value)
{
	commandReceivedFlag = value;
}

sCircularBuffer_t * getRxBuffer(void)
{
	return rxBuffer;
}
