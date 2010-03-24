/*
 * Car.h
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */

#ifndef CAR_H_
#define CAR_H_

class Car {
public:
	Car();
	~Car();
	void fill_tank(void);
	void drive(float miles);
	float gallons_left();
protected:
	virtual float get_tank_size(void);
	virtual float get_mpg(void);
private:
	float amount_of_gas_in_tank;
};

#endif /* CAR_H_ */
