/*
 * flowerService.h
 *
 *  Created on: Apr 8, 2019
 *      Author: Blaise
 */

#ifndef HEADERS_FLOWERSERVICE_H_
#define HEADERS_FLOWERSERVICE_H_

#include "main.h"
#include "stm32f4xx_hal.h"

uint16_t flowerService(uint16_t canWater);
void waterMyPlant();
uint16_t measureHumidity();

#endif /* HEADERS_FLOWERSERVICE_H_ */
