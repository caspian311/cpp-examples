/*
 * Car.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */
#include <iostream>
#include "Car.h"

Car::Car() {
	amount_of_gas_in_tank = 0.0;
}

Car::~Car() {
}

float Car::gallons_left() {
	return amount_of_gas_in_tank;
}

void Car::fill_tank() {
	amount_of_gas_in_tank = get_tank_size();
}

void Car::drive(float miles) {
	float rate = 1.0 / (float) get_mpg();
	float gallons_used = miles * rate;
	//	std::cout << "gallons used: " << gallons_used << std::endl;
	amount_of_gas_in_tank -= (int) gallons_used;
}

float Car::get_tank_size() {
	return 0.0;
}

float Car::get_mpg() {
	return 0.0;
}
