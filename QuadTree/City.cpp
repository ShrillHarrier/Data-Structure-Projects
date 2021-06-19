/*
 * City.cpp
 *
 *  Created on: Nov. 3, 2020
 *      Author: Matthew
 */

#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class City{

	public:
		City *nw, *ne, *sw, *se; //Pointers

		double x, y; //Keys
		string name; //Values
		double population, col, salary; //Values

		City(string name, double x, double y, double population, double col, double salary){
			nw = nullptr;
			ne = nullptr;
			sw = nullptr;
			se = nullptr;

			this->name = name;
			this->x = x;
			this->y = y;
			this->population = population;
			this->col = col;
			this->salary = salary;
		}
};


