#include "stm32f4xx_hal.h"
#include "main.h"


/*
 * plik do obslugi polecen wysylaych na ESP 8266
 */

//funkcja do testowania polaczenia
static void TestFunc()
{
}

//configuracja polaczenia esp z serwerem
void ConfigESP(UART_HandleTypeDef huart2)
{
	uint8_t sendUART[4] = {"AT\r\n"};
	uint16_t sizeSendUART = 4;

	HAL_UART_Transmit_IT(&huart2, sendUART, sizeSendUART);
}
