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
	int i = 0;
	for(i = 0; i < sizeof(&txt); i++)
	{
		if(&txt[i] == 'P')
			return 1;
	}
	return 0;
}





