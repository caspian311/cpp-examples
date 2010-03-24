/*
 * Car.cpp
 *
 *  Created on: Mar 21, 2010
 *      Author: mtodd
 */
#include "Car.h"

Car::Car() {
}

Car::~Car() {
}

int Car::get_id() {
	return car_id;
}

void Car::set_id(int new_id) {
	car_id = new_id;
}

