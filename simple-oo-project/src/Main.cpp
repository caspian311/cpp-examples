/*
 * Main.cpp
 *
 *  Created on: Mar 21, 2010
 *      Author: mtodd
 */

#include <iostream>

#include "Car.h"

int main(void) {
	Car car;
	car.set_id(123);
	std::cout << "The owner is: " << car.get_id();

	return 0;
}
