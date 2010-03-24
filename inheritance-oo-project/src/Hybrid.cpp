/*
 * Hybrid.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */

#include "Hybrid.h"

const int TANK_SIZE = 13;
const int MPG_RATE = 40;

Hybrid::Hybrid() {
}

Hybrid::~Hybrid() {
}

float Hybrid::get_mpg() {
	return MPG_RATE;
}

float Hybrid::get_tank_size() {
	return TANK_SIZE;
}
