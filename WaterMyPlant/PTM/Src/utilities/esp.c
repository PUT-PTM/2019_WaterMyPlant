#include "stm32f4xx_hal.h"
#include "main.h"
#include "headers/esp.h"
#include "headers/sender.h"
/*
 * plik do obslugi polecen wysylaych na ESP 8266
 *
 *
 * ---- TODO ----
 *  1. Dopisac funkcje Send_To_ESP, ktora przyjmuje parametry, wielkosc tablicy i tresc przesylanej wadomosci
 *  2. Dopisac dzialajaca funkcje //void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass) po to, zeby podawac rozne WiFi
 */

/*
 * variables
 */

void SendResetFlowerState(UART_HandleTypeDef *huart2){
	AT_Set_WorkMode(huart2);
	AT_MultipleConnections(huart2);
	AT_Connect_To_WiFi(huart2);
	AT_Connect_To_Server(huart2);
	AT_Send_Reset(huart2);
	AT_GET_ResetFlowerState(huart2);
}

//konfiguracja polaczenia esp z serwerem
void ConfigESP(UART_HandleTypeDef *huart2)
{
	AT_command(huart2);
//	AT_reset(huart2);
//	AT_command(huart2);
	AT_Set_WorkMode(huart2);
	AT_MultipleConnections(huart2);
	AT_Connect_To_WiFi(huart2);
	AT_Connect_To_Server(huart2);
	AT_Send(huart2);
	AT_GET(huart2);
}
//sprawdzenie czy polaczono z ESP 8266 AT
void AT_command(UART_HandleTypeDef *huart2)
{
	Send_To_ESP(huart2, "AT\r\n", 4);
	check(300);
}
//resetowanie esp
void AT_reset(UART_HandleTypeDef *huart2)
{
	Send_To_ESP(huart2, "AT+CWQAP\r\n",10);
	Send_To_ESP(huart2, "AT+RST\r\n", 8);
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
	Send_To_ESP(huart2, "AT+CWMODE=1\r\n", 13);
	check(300);
}
/*Pozwolenie na wiele polaczen MAX 4
* 1 - wiele
* 0 - jedno
*/
void AT_MultipleConnections(UART_HandleTypeDef *huart2)
{
	Send_To_ESP(huart2, "AT+CIPMUX=1\r\n", 13);
	check(2000);
}
//kanal, protokol, adres, port
void AT_Connect_To_Server(UART_HandleTypeDef *huart2)
{
	char* msg = "AT+CIPSTART=0,\"TCP\",\"krzysztof.r.czarnecki.student.put.poznan.pl\",80\r\n";
	Send_To_ESP(huart2, msg, 70);
	check(2000);
}
//trzeba zrobic konkatenacje, zeby moc podawac dowolne parametry ssid i hasla do wifi
//void ConnectToWiFi(UART_HandleTypeDef *huart2, char* ssid, char* pass)
void AT_Connect_To_WiFi(UART_HandleTypeDef *huart2)
{
		char* msg = "AT+CWJAP=\"krzysiulekk\",\"misio1234\"\r\n";
		Send_To_ESP(huart2, msg, 46);
		check(7000);
}
// ustalenie kanalu i ilosci przesylanych bajtow
void AT_Send(UART_HandleTypeDef *huart2)
{
		Send_To_ESP(huart2, "AT+CIPSEND=0,88\r\n", 18);
		check(2000);
}

void AT_Send_Reset(UART_HandleTypeDef *huart2)
{
		Send_To_ESP(huart2, "AT+CIPSEND=0,91\r\n", 18);
		check(2000);
}
//pobranie wartosci z serwera poleceniem GET
void AT_GET(UART_HandleTypeDef *huart2)
{
		char* msg = "GET /get_state.php?id=1 HTTP/1.1\r\nHost:krzysztof.r.czarnecki.student.put.poznan.pl\r\n\r\n\r\n\r\n";
		Send_To_ESP(huart2, msg, 90);
		check(4000);
}

void AT_GET_ResetFlowerState(UART_HandleTypeDef *huart2)
{
		char* msg = "GET /reset_flower.php?id=1 HTTP/1.1\r\nHost:krzysztof.r.czarnecki.student.put.poznan.pl\r\n\r\n\r\n\r\n";
		Send_To_ESP(huart2, msg, 95);
		check(4000);
}
//zmiana stanu diody na stmie i chwila odczekania
void check(uint delay)
{
	HAL_Delay(delay);
//	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}
