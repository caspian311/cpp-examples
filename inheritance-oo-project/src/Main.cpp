//============================================================================
// Name        : inheritance-oo-project.cpp
// Author      : Matt Todd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
#include <iostream>
#include <stdlib.h>

#include "Truck.h"
#include "Hybrid.h"

using namespace std;

void fill_up(Car *car) {
	car->fill_tank();
}

void goto_chicago(Car *car) {
	car->drive(100);
}

Car *create_hybrid()
{
    return new Hybrid;
}

Car *create_truck()
{
    return new Truck;
}

int main(void) {
	Car *hybrid = create_hybrid();
	Car *truck = create_truck();

    fill_up(hybrid);
    fill_up(truck);

	goto_chicago(hybrid);
	goto_chicago(truck);

	cout << "Prius: " << hybrid->gallons_left() << endl;
	cout << "Truck: " << truck->gallons_left() << endl;

	return EXIT_SUCCESS;
}

