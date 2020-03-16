#include "LogFile.h"
#include "usart.h"

int fputc (int ch,FILE *f) {
	HAL_UART_Transmit(&hlpuart1,(uint8_t *)&ch,1,1000);
	return ch;
};
