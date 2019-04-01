#include "stm32f4xx_hal.h"
#include "main.h"


/*
 * plik do obslugi polecen wysylaych na ESP 8266
 *
 *
 * TODO
 *  1. Dopisac funkcje sendUART, ktora przyjmuje parametry, wielkosc tablicy i tresc przesylanej wadomosci
 *  2. Dopisac dzialajaca funkcje //void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass) po to, zeby podawac rozne WiFi
 */

//configuracja polaczenia esp z serwerem
void ConfigESP(UART_HandleTypeDef *huart2)
{
	ATcommand(huart2);
//	ATreset(huart2);
//	ATcommand(huart2);
//	ATSetClientMode(huart2);
//	ATConnectToWiFi(huart2);
}

//sprawdzenie czy polaczono z ESP 8266 AT
void ATcommand(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[4] = {"AT\r\n"};
	uint16_t sizeSendUART = 4;
	check();
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}

void ATreset(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[8] = {"AT+RST\r\n"};
	uint16_t sizeSendUART = 8;
	check();
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}
//ustawienei trybu pracy AT+CWMODE
void ATSetClientMode(UART_HandleTypeDef *huart2)
{
	check();
	//AT+CWJAP='ssid','pass' -> laczy z wifi
	uint8_t sendUART[13] = {"AT+CWMODE=1\r\n"};
	uint16_t sizeSendUART = 13;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}

//trzeba zrobic konkatenacje, zeby moc podawac dowolne parametry ssid i hasla do wifi
//void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass)
void ATConnectToWiFi(UART_HandleTypeDef *huart2)
{
	check();
	//AT+CWJAP='ssid','pass' -> laczy z wifi
	uint8_t sendUART[32] = {"AT+CWJAP='Krzysio','misio1234'\r\n"};
	uint16_t sizeSendUART = 32;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}


//zmiana stanu diody na stmie i chwila odczekania
void check()
{
	HAL_Delay(1000);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}
