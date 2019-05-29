/*
 * flowerService.c
 *
 *  Created on: Apr 8, 2019
 *      Author: Blaise
 */

#include "main.h"
#include "stm32f4xx_hal.h"
#include "headers/flowerService.h"
/*
 * Global variables
 */
uint16_t humidity = 0;

uint16_t flowerService(uint16_t canWater){
	// 1. canWater <= 0 -> nie można podlac
	if ( canWater <= 0){
		return 0;
	}

	if (canWater > 0){
		waterMyPlant();
		return 1;
	}
}

void waterMyPlant(){
	uint16_t minHumidity = 120;
	uint16_t maxHumidity = 750;
	uint16_t measuredHumidity = measureHumidity();


	 if ( measuredHumidity < maxHumidity  && measuredHumidity > minHumidity ){
		 turnPumpOn();
		 turnLedsOn(1);
		 HAL_Delay(3000);
		 turnPumpOff();
		 turnLedsOff();
	 }
	 else if (measuredHumidity > maxHumidity){
		 turnLedsOn(3);
		 HAL_Delay(1000);
		 turnLedsOff();
	 }
	 else if (measuredHumidity < minHumidity){
		 turnPumpOn();
		 turnLedsOn(2);
		 HAL_Delay(6000); // czas podlewania jest dluzszy jesli wilgotnosc jest ponizej wartosci zadanej
		 turnPumpOff();
		 turnLedsOff();
	 }
}

void setHumidity(uint16_t hum)
{
	humidity = hum;
}

// funkcja do pomiaru wilgotnosci
uint16_t measureHumidity()
{
	return humidity;
}

void turnPumpOn()
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, 0); // docelowo ma tu byc pin wlaczajacy pompke
}
/*
 * 1 - zielona dioda - stan normalny - zwykle podlewanie
 * 2 - zolta dioda - podlewanie awaryjne, gdy jest za malo wody w doniczce
 * 3 - czerwona dioda -
 */
void turnLedsOn(int num)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);

	switch(num)
	{
		case 3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			break;
	}
}

void turnPumpOff()
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, 1); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnLedsOff()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); // docelowo ma tu byc pin wlaczajacy pompke

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
}

