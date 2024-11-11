/*
 * circularBuffer.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#ifndef CIRCULARBUFFER_CIRCULARBUFFER_H_
#define CIRCULARBUFFER_CIRCULARBUFFER_H_

#include "commonDefines.h"

typedef struct
{
	uint16_t head;
	uint16_t tail;
	uint16_t maxCapacity;
	uint16_t dataSize;
	uint16_t length;
	void * array;
}sCircularBuffer_t;

typedef enum
{
	E_CBUFF_CREATE_SUCCESS = 0,
	E_CBUFF_CREATE_FAILED,
	E_CBUFF_ENQUEUE_OK,
	E_CBUFF_ENQUEUE_FAILED,
	E_CBUFF_DEQUEUE_OK,
	E_CBUFF_DEQUEUE_FAILED
}eCbuffStatus_t;


eCbuffStatus_t circularBufferInit(sCircularBuffer_t * cBuff, uint16_t maxCapacity, uint16_t dataSize);

eCbuffStatus_t circularBufferEnqueue(sCircularBuffer_t * cBuff, void * value);

eCbuffStatus_t circularBufferDequeue(sCircularBuffer_t * cBuff, void * value);


#endif /* CIRCULARBUFFER_CIRCULARBUFFER_H_ */
