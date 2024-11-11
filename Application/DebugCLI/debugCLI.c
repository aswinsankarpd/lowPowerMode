/*
 * debugCLI.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */
#include "debugCLI.h"
#include "debugUart.h"
#include "circularBuffer.h"
#include "commonDefines.h"
#include "realtimeclock.h"

typedef void(*commandFptr)(char ** args, char *response);

static void getDateTime(char ** args, char *response);

static void setTime(char ** args, char *response);

static void setSleep(char ** args, char *response);

typedef struct
{
    char * command;
    struct sCommandStruct_t * subCommand;
    commandFptr fptr;
} sCommandStruct_t;

// Command tables
sCommandStruct_t getCommandtable[] =
{
    {"dateTime", 	NULL, 	getDateTime},
    {NULL, 			NULL, 	NULL}
};

sCommandStruct_t setCommandtable[] =
{
	{"dateTime", 		NULL, 	setTime},
	{"sleep", 			NULL, 	setSleep},
    {NULL, 				NULL, 	NULL}
};
sCommandStruct_t mainCommandTable[] =
{
    {"get", 	getCommandtable, 	NULL},
    {"set", 	setCommandtable, 	NULL},
    {NULL, 		NULL, 				NULL}
};


uint8_t commandBuffer[512] = {0};
char * args[10];
char response[512] = {0};

static void parseCommand(void);
static void processCommand(void);

void debugCLITask(void)
{
    bool commandRxd = false;

    commandRxd = getCmdReceivedFlag();

    if(commandRxd == true)
    {
        parseCommand();
        processCommand();

        setCmdReceivedFlag(0);

        memset(args,0,10);
        memset(commandBuffer,0,512);

    }
}

static void parseCommand(void)
{
    uint16_t pData = 0;
    uint16_t cmdIdx = 0;

    while(E_CBUFF_DEQUEUE_OK == circularBufferDequeue(getRxBuffer(), (void *)&pData))
    {
        if(pData == 0x0D)
        {
            cmdIdx = 0;
            break;
        }
        else
        {
        	commandBuffer[cmdIdx++] = (uint8_t)pData;
        }
    }
}

static void processCommand(void)
{
    uint8_t argIndex = 0;
    sCommandStruct_t *commandStruct = mainCommandTable;
    uint8_t cmdIdx = 0;
    bool cmdSucessFlag = false;


    args[argIndex] = strtok((char *)commandBuffer, " ");
    while (args[argIndex] != NULL)
    {
        argIndex++;
        args[argIndex] = strtok(NULL, " ");
    }

    cmdIdx = 0;
    argIndex = 0;

    while(commandStruct[cmdIdx].command != NULL)
    {
    	if(strcmp(commandStruct[cmdIdx].command, args[argIndex]) == 0)
    	{
    		if(commandStruct[cmdIdx].fptr != NULL)
			{
    			commandStruct[cmdIdx].fptr(args, response);
    			cmdSucessFlag = true;
				break;
			}
    		else if(commandStruct[cmdIdx].subCommand != NULL)
    		{
				commandStruct = commandStruct[cmdIdx].subCommand;
				argIndex++;
				cmdIdx = 0;
    		}
    	}
    	else
    	{
    		cmdIdx++;
    	}
    }

    if( false == cmdSucessFlag)
    {
		uint8_t len = snprintf(response, 512, "%s", "Command Not OK\r\n");
		HAL_UART_Transmit(&huart3, response, len, 100);
    }
}


static void getDateTime(char ** args, char *response)
{
	sDateTimeConfig_t dateTime = {0};

	getRTCData(&dateTime);

	uint16_t length = snprintf(response, 512, "Time: %02u:%02u:%02u\r\n", dateTime.hours, dateTime.mins, dateTime.secs);

	HAL_UART_Transmit(&huart3, response, length, 100);
}

static void setTime(char ** args, char *response)
{
    uint8_t dateTimeArray[3] = {0};
    uint8_t tokenIdx = 0;
    sDateTimeConfig_t dateTime = {0};

    char *token = strtok(args[2], ",");


    while (token != NULL && tokenIdx < 3)
    {
        dateTimeArray[tokenIdx] = (uint8_t)atoi(token);
        tokenIdx++;
        token = strtok(NULL, ",");
    }

    dateTime.hours = dateTimeArray[0];
    dateTime.mins = dateTimeArray[1];
    dateTime.secs = dateTimeArray[2];

    setRTCData(&dateTime);

    uint16_t length = snprintf(response, 512, "Time is Set\r\n");

	HAL_UART_Transmit(&huart3, response, length, 100);
}

static void setSleep(char ** args, char *response)
{
    uint16_t length = snprintf(response, 512, "Device entered low power mode\r\n");

	HAL_UART_Transmit(&huart3, response, length, 100);

	startLowPowerMode();
}
