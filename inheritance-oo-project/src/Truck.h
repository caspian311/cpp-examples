/*
 * Truck.h
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */

#include "Car.h"

#ifndef TRUCK_H_
#define TRUCK_H_

class Truck : public Car {
public:
	Truck();
	~Truck();
protected:
	float get_tank_size(void);
	float get_mpg(void);
};

#endif /* TRUCK_H_ */
