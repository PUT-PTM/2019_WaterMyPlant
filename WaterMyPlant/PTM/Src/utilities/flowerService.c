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
	// if ( measureHumidity() > maxHumidity ){
	// wlacz ledy + podlej Kwiata
	// }

	// else {
	// wlacz ledy
	// }

	// ESP_Send_Get_Reset_floweState(); -> to ma byc nawet, jezeli tylko wlaczylo ledy. Najlepiej z 5 razy dla pewnosci
}


uint16_t measureHumidity(){
	// funkcja do pomiaru wilgotnosci
	return 0;
}

