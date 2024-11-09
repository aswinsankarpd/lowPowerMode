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

typedef void(*commandFptr)(char * args, char *response);

static void sampleGetFunction(char * args, char *response);

typedef struct
{
    char * command;
    struct sCommandStruct_t * subCommand;
    commandFptr fptr;
} sCommandStruct_t;

// Command tables
sCommandStruct_t getCommandtable[] =
{
    {"sample", 	NULL, 	sampleGetFunction},
    {NULL, 		NULL, 	NULL}
};

sCommandStruct_t mainCommandTable[] =
{
    {"get", 	getCommandtable, 	NULL},
    {"set", 	getCommandtable, 	NULL},
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
    }
}

static void parseCommand(void)
{
    uint16_t pData = 0;
    uint16_t cmdIdx = 0;

    // Dequeue data from circular buffer until end of command (0x0D) is detected
    while(E_CBUFF_DEQUEUE_OK == circularBufferDequeue(getRxBuffer(), (void *)&pData))
    {


        // Reset index if end of command is detected
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


static void sampleGetFunction(char * args, char *response)
{
    HAL_UART_Transmit(&huart3, (uint8_t *)"get Cmd OK", 10, 100);
}
