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
	uint16_t minHumidity = 500;
	uint16_t maxHumidity = 2000;
	uint16_t measuredHumidity = measureHumidity();


	 if ( measuredHumidity < maxHumidity  && measuredHumidity > minHumidity ){
		 turnPumpOn();
		 turnLedsOn();
		 HAL_Delay(3000);
		 turnPumpOff();
		 turnLedsOff();
	 }
	 else if (measuredHumidity > maxHumidity){
		 turnLedsOn();
		 HAL_Delay(1000);
		 turnLedsOff();
	 }
	 else if (measuredHumidity < minHumidity){
		 turnPumpOn();
		 turnLedsOn();
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
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 1); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnLedsOn()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnPumpOff()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 0); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnLedsOff()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); // docelowo ma tu byc pin wlaczajacy pompke
}

