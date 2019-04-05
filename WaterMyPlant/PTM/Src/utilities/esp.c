#include "stm32f4xx_hal.h"
#include "main.h"
#include "esp.h"
#include "headers/sender.h"
/*
 * plik do obslugi polecen wysylaych na ESP 8266
 *
 *
 * ---- TODO ----
 *  1. Dopisac funkcje sendUART, ktora przyjmuje parametry, wielkosc tablicy i tresc przesylanej wadomosci
 *  2. Dopisac dzialajaca funkcje //void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass) po to, zeby podawac rozne WiFi
 */

/*
 * variables
 */


//configuracja polaczenia esp z serwerem
void ConfigESP(UART_HandleTypeDef *huart2)
{
	AT_command(huart2);
	AT_reset(huart2);
	AT_command(huart2);
	AT_Set_WorkMode(huart2);
//	AT_MultipleConnections(huart2);
//	AT_Connect_To_WiFi(huart2);
//	AT_Connect_To_Server(huart2);
//	AT_Send(huart2);
//	AT_GET(huart2);
}
//sprawdzenie czy polaczono z ESP 8266 AT
void AT_command(UART_HandleTypeDef *huart2)
{
//	uint8_t sendUART[4] = {"AT\r\n"};
//	uint16_t sizeSendUART = 4;
//	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	Send_To_ESP(huart2, "AT\r\n", 4);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	check(300);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}
//resetowanie esp
void AT_reset(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[8] = {"AT+RST\r\n"};
	uint16_t sizeSendUART = 8;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
	check(2000);
}
/*
 * ustawienie trybu pracy
 * 1 – Klient
 * 2 – Access Point (punkt dostępu)
 * 3 – Klient + Access Point
 */
void AT_Set_WorkMode(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[13] = {"AT+CWMODE=1\r\n"};
	uint16_t sizeSendUART = 13;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
	check(300);
}
//Pozwolenie na wiele polaczen MAX 4
void AT_MultipleConnections(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[13] = {"AT+CIPMUX=1\r\n"};
	uint16_t sizeSendUART = 13;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
	check(300);
}
//kanal, protokol, adres, port
void AT_Connect_To_Server(UART_HandleTypeDef *huart2)
{
	uint8_t sendUART[100] = {"AT+CIPSTART=4,\"TCP\",\"krzysztof.r.czarnecki.student.put.poznan.pl\",80\r\n"};
	uint16_t sizeSendUART = 100;
	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
	check(2000);
}

//trzeba zrobic konkatenacje, zeby moc podawac dowolne parametry ssid i hasla do wifi
//void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass)
void AT_Connect_To_WiFi(UART_HandleTypeDef *huart2)
{
		uint8_t sendUART[32] = {"AT+CWJAP=\"Krzysio\",\"misio1234\"\r\n"};
		uint16_t sizeSendUART = 32;
		HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
		check(7000);
}

void AT_Send(UART_HandleTypeDef *huart2)
{
		uint8_t sendUART[100] = {"AT+CIPSEND=4,88\r\n"};
		uint16_t sizeSendUART = 100;
		HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
		check(2000);
}
void AT_GET(UART_HandleTypeDef *huart2)
{
		uint8_t sendUART[90] = {"GET /get_state.php?id=2 HTTP/1.1\r\nHost:krzysztof.r.czarnecki.student.put.poznan.pl\r\n\r\n\r\n\r\n"};
		uint16_t sizeSendUART = 90;
		HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);

		check(4000);
		// DO PRZETESOWANIA
		uint16_t sizeReceiveUART = 100;
		uint8_t receiveUART[100];
		HAL_UART_Receive_IT(huart2, receiveUART, sizeReceiveUART);
		check(1000);
		// tutaj musimy zobaczyc co pokaze STM Studio dla
		// wartosci receive UART
}

void AT_POST()
{
	//
}

//zmiana stanu diody na stmie i chwila odczekania
void check(uint delay)
{
	HAL_Delay(delay);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}
