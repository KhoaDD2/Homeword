/******************************************************************************
===============================================================================
Filename        : LessionInterface.c
Description     : creat some function basic of for each lession 
Accessibility   : called from main.c
Creation        : Dao Nguyen- 12 April 2020
Modify/Updated  :
Version         : V01.00.00
===============================================================================
****************************************************************************/
/*
===============================================================================
                                INCLUDED FILES
===============================================================================
*/
#include "LessionInterface.h"
#include <string.h>
#include "LogFile.h"

/*
===============================================================================
                                GLOBAL VARIABLE 
===============================================================================
*/
#if LESSION_1
HAL_StatusTypeDef transmitStatus;
char TransmitStr[] = "Started project\r\n";
#endif
#if LESSION_3 
uint8_t RxBuffer;
uint8_t aStoredRxBuf[STOREDRXBUFSIZE], bCurStoredCharIdx=0;
#endif

/*
===============================================================================
                                FUNCTION
===============================================================================
*/
void RunLession1()
{
#if LESSION_1	
	if(HAL_UART_Transmit(&hlpuart1, (uint8_t*) &TransmitStr,strlen((char*)&TransmitStr) , 1000) !=HAL_OK)
	{
		Error_Handler();
	}		
#endif
}

void RunLession2()
{
#if LESSION_2

	if (DEBUG)
	{
			do
			{
				LOG_ERROR("Debug is true. Loop in while() \r\n");
				HAL_Delay(1000);
			}
			while(1);
	}
	else
	{
				LOG_INFO("Debug is false. Reset system\r\n");
				HAL_Delay(1000);
			__NVIC_SystemReset();
	}
#endif
}

void RunLession3()
{
	#if LESSION_3
	if(HAL_UART_Receive_IT(&hlpuart1, &RxBuffer, 1) != HAL_OK)
	{
			Error_Handler();
	}
	#endif
}
#if LESSION_3
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	
	if (UartHandle ->Instance == LPUART1)
	{
			if (RxBuffer == 0x0D)
			{
				HAL_UART_Transmit(&hlpuart1, aStoredRxBuf, bCurStoredCharIdx , 1000); 
				HAL_UART_Transmit(&hlpuart1, (uint8_t*) "\r\n", 2 , 1000); 
				bCurStoredCharIdx=0;
			}
			else
			{
				aStoredRxBuf[bCurStoredCharIdx] = RxBuffer;
				bCurStoredCharIdx++;
				HAL_UART_Transmit(&hlpuart1, &RxBuffer, 1 , 1000);
				HAL_UART_Transmit(&hlpuart1, (uint8_t*) "\r\n", 2 , 1000); 
			}
			if(HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&RxBuffer, 1) != HAL_OK)
			{
					Error_Handler();
			}
	}

}
#endif