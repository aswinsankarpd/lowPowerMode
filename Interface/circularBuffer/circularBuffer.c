/*
 * circularBuffer.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#include "circularBuffer.h"
#include <stdlib.h>
#include <string.h>


eCbuffStatus_t circularBufferInit(sCircularBuffer_t * cBuff, uint16_t maxCapacity, uint16_t dataSize)
{
    eCbuffStatus_t status = E_CBUFF_CREATE_FAILED;

    cBuff->head = 0;
    cBuff->tail = 0;
    cBuff->dataSize = dataSize;
    cBuff->maxCapacity = maxCapacity;
    cBuff->array = malloc(maxCapacity * dataSize);
    cBuff->length = 0;

    if(cBuff->array != NULL)
    {
        memset(cBuff->array, 0, maxCapacity * dataSize);  // Corrected memset size
        status = E_CBUFF_CREATE_SUCCESS;
    }

    return status;
}

eCbuffStatus_t circularBufferEnqueue(sCircularBuffer_t * cBuff, void * value)
{
    eCbuffStatus_t status = E_CBUFF_ENQUEUE_FAILED;

    uint16_t next = cBuff->head + 1;

    if (next >= cBuff->maxCapacity)
    {
        next = 0;
    }

    // If next is equal to tail, buffer is full, so do not enqueue
    if (next != cBuff->tail)
    {
        void *currentAddress = memcpy((char*)cBuff->array + (cBuff->head * cBuff->dataSize), value, cBuff->dataSize);

        if (currentAddress != NULL)
        {
            cBuff->head = next;
            status = E_CBUFF_ENQUEUE_OK;

            cBuff->length = (cBuff->head + cBuff->maxCapacity - cBuff->tail) % cBuff->maxCapacity;
        }
    }

    return status;
}

eCbuffStatus_t circularBufferDequeue(sCircularBuffer_t * cBuff, void * value)
{
    eCbuffStatus_t status = E_CBUFF_DEQUEUE_FAILED;

    // if head and tail are equal then it means no data has been dequeued and the buffer is full
    if (cBuff->tail != cBuff->head)
    {
        uint16_t next = cBuff->tail + 1;

        if (next >= cBuff->maxCapacity)
        {
            next = 0;
        }

        memcpy(value, (char*)cBuff->array + (cBuff->tail * cBuff->dataSize), cBuff->dataSize);  // Copy dequeued element

        cBuff->tail = next;

        cBuff->length = (cBuff->head + cBuff->maxCapacity - cBuff->tail) % cBuff->maxCapacity;

        status = E_CBUFF_DEQUEUE_OK;
    }

    return status;
}
