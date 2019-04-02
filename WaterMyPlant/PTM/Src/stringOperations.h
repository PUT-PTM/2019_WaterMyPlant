#include "stm32f4xx_hal.h"
#include "main.h"

/*
 * plik do obslugi odebranych zapytań od ESP
 *
 *
 * ---- TODO ----
 *  1. Napisac funkcje ponizej!
 */


/*
 * Function prototypes
 */

// to musi miec Stringa jako parametr
static boolean canIWaterMyPlant(){
	if( charsContainsStage() && isStageGTZero )
		return true;
	else
		return false;
}

// to musi miec Stringa jako parametr
static boolean isStageGTZero(){
	return false;
}

// to musi miec Stringa jako parametr
static boolean charsContainsStage(){
	return false;
}




