#include "stm32f4xx_hal.h"
#include "main.h"
#include "sender.h"


/*
 * plik do obslugi polecen wysylaych na ESP 8266
 *
 *
 * ---- TODO ----
 *  1. Dopisac funkcje sendUART, ktora przyjmuje parametry, wielkosc tablicy i tresc przesylanej wadomosci
 *  2. Dopisac dzialajaca funkcje //void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass) po to, zeby podawac rozne WiFi
 */

//configuracja polaczenia esp z serwerem
void ConfigESP(UART_HandleTypeDef *huart2)
{
	AT_command(huart2);
	AT_reset(huart2);
	AT_command(huart2);
	AT_Set_ClientMode(huart2);
	AT_MultipleConnections(huart2);
	AT_Connect_To_WiFi(huart2);
}

//sprawdzenie czy polaczono z ESP 8266 AT
void AT_command(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[4] = {"AT\r\n"};
	uint16_t sizeSendUART = 4;
	check();
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}
//resetowanie esp
void AT_reset(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[8] = {"AT+RST\r\n"};
	uint16_t sizeSendUART = 8;
	check();
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}
/*
 * ustawienie trybu pracy
 * 1 – Klient
 * 2 – Access Point (punkt dostępu)
 * 3 – Klient + Access Point
 */
void AT_Set_ClientMode(UART_HandleTypeDef *huart2)
{
	check();
	//AT+CWJAP='ssid','pass' -> laczy z wifi
	uint8_t sendUART[13] = {"AT+CWMODE=1\r\n"};
	uint16_t sizeSendUART = 13;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}
//Pozwolenie na wiele polaczen MAX 4
void AT_MultipleConnections(UART_HandleTypeDef *huart2)
{
	check();
	//AT+CWJAP='ssid','pass' -> laczy z wifi
	uint8_t sendUART[13] = {"AT+CIPMUX=1\r\n"};
	uint16_t sizeSendUART = 13;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}

//trzeba zrobic konkatenacje, zeby moc podawac dowolne parametry ssid i hasla do wifi
//void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass)
void AT_Connect_To_WiFi(UART_HandleTypeDef *huart2)
{
	check();
	//AT+CWJAP='ssid','pass' -> laczy z wifi
	uint8_t sendUART[63] = {"AT+CIPSTART=4,'TCP','http://sim900automation.comli.com',80\r\n"};
	uint16_t sizeSendUART = 63;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}

void AT_GET()
{
	//GET /api/flower/1<CR><LF>Host:water-test2.herokuapp.com<CR><LF>
}

void AT_POST()
{
	//
}

//kanal, protokol, adres, port
void AT_Connect_To_Server(UART_HandleTypeDef *huart2)
{
	//AT+CIPSTART="TCP","http://sim900automation.comli.com",80

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
