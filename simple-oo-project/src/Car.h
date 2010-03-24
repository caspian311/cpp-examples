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
	virtual ~Car();
	int get_id(void);
	void set_id(int id);
protected:
	int car_id;
};

#endif /* CAR_H_ */
