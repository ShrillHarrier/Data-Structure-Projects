/*
 * Person.cpp
 *
 *  Created on: Oct. 7, 2020
 *      Author: Matthew
 */

#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Person{

	public:
		string caller;
		long long int number;

		Person(string caller, long long int number){
			this->caller = caller;
			this->number = number;
		}
};


