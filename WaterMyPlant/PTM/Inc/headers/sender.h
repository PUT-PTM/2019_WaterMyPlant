/*
 * sender.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Blaise
 */


#ifndef HEADERS_SENDER_H_
#define HEADERS_SENDER_H_

#include "main.h"
#include "stm32f4xx_hal.h"

void Send_To_ESP(UART_HandleTypeDef *huart2, char *msg, uint16_t sizeSendUART)
{
	uint8_t sendUART[sizeSendUART];
	memset( sendUART, msg, sizeSendUART*sizeof(uint8_t) );

	HAL_UART_Transmit_IT(huart2, sendUART, sizeSendUART);
}


#endif /* HEADERS_SENDER_H_ */