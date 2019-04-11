/*
 * flowerService.c
 *
 *  Created on: Apr 8, 2019
 *      Author: Blaise
 */
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
	uint16_t minHumidity = 25;
	uint16_t maxHumidity = 55;
	uint16_t measuredHumidity = measureHumidity();


	 if ( measuredHumidity < maxHumidity  && measuredHumidity > minHumidity ){
		 turnPumpOn();
		 turnLedsOn();
		 HAL_Delay(1000);
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
		 HAL_Delay(5000); // czas podlewania jest dluzszy jesli wilgotnosc jest ponizej wartosci zadanej
		 turnPumpOff();
		 turnLedsOff();
	 }



	// ESP_Send_Get_Reset_floweState(); -> to ma byc nawet, jezeli tylko wlaczylo ledy. Najlepiej z 5 razy dla pewnosci
}


uint16_t measureHumidity(){
	// funkcja do pomiaru wilgotnosci
	return ;
}

void turnPumpOn(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 1); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnLedsOn(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnPumpOff(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 0); // docelowo ma tu byc pin wlaczajacy pompke
}

void turnLedsOff(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); // docelowo ma tu byc pin wlaczajacy pompke
}

