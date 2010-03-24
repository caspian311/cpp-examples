/*
 * Hybrid.h
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */

#include "Car.h"

#ifndef HYBRID_H_
#define HYBRID_H_

class Hybrid : public Car {
public:
	Hybrid();
	~Hybrid();
protected:
	float get_tank_size(void);
	float get_mpg(void);
};

#endif /* HYBRID_H_ */
