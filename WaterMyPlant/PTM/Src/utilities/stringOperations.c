/*
 * stringOperations.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Blaise
 */
#include "stm32f4xx_hal.h"
#include "main.h"
#include "headers/stringOperations.h"


int canIWaterMyPlant(uint8_t *txt)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
	return 0;
}

int canIWaterMyPlant2(uint8_t receiveUART[])
{
	for (int i = 0; i<9; i++){
		if( receiveUART[i] == 'P' && receiveUART[i+1] == 'P'){

			return 1;
		}
	}

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);

	return 0;
}
