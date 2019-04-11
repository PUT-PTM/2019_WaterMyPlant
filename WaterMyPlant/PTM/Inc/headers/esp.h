/*
 * esp.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Blaise
 */

#ifndef ESP_H_
#define ESP_H_

/*
 * functions prototypes
 */


void check(uint delay);
void AT_command(UART_HandleTypeDef *huart2);
void AT_reset(UART_HandleTypeDef *huart2);
void AT_Set_WorkMode(UART_HandleTypeDef *huart2);
void AT_MultipleConnections(UART_HandleTypeDef *huart2);
void AT_Connect_To_Server(UART_HandleTypeDef *huart2);
void AT_Connect_To_WiFi(UART_HandleTypeDef *huart2);
void AT_Send(UART_HandleTypeDef *huart2);
void AT_GET(UART_HandleTypeDef *huart2);
void AT_GET_ResetFlowerState(UART_HandleTypeDef *huart2);
void SendResetFlowerState(UART_HandleTypeDef *huart2);
void ConfigESP(UART_HandleTypeDef *huart2);


#endif /* ESP_H_ */
