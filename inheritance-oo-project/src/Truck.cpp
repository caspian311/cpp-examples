/*
 * Truck.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */
#include "Truck.h"
#include <iostream>

const float TANK_SIZE = 23;
const float MPG_RATE = 18;

Truck::Truck() {
}

Truck::~Truck() {
}

float Truck::get_tank_size() {
	return TANK_SIZE;
}

float Truck::get_mpg() {
	return MPG_RATE;
}

