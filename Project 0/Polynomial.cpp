/*
 * Polynomial.cpp
 *
 *  Created on: Sep. 20, 2020
 *      Author: Matthew
 */

#include <iostream>
using namespace std;

#include <math.h>
using namespace std;

#include <cmath>
using namespace std;

#include "Polynomial.h"
// #include "LinkedList.cpp"

Polynomial::Polynomial (const int& size_p, const double coeff_p[]) {
 	size = sizeof(coeff_p)/sizeof(coeff_p[0]);

	poly = new LinkedList;

    for(int i = 0; i < size_p; i++){
    		poly->newNode(coeff_p[i]);
	}

 }

Polynomial::Polynomial(){
	coeff = 0;
	 size = 0;
}

double Polynomial::evaluate(const double &x){
	node *temp = poly->head;
	double sum = 0.0;
	int iteration = 0;

	if(temp != nullptr){
		while(true){
			sum += pow(x, iteration)*(temp->value);

			if(temp->next == nullptr){
				break;
			}

			temp = temp->next;
			iteration++;
		}
	}

	return sum;
}

void Polynomial::print(){
			node *temp = poly->head;

			if(temp != nullptr){
				while(true){
					std::cout<<(temp->value)<<" ";

					if(temp->next == nullptr){
						break;
					}
					else{
						temp = temp->next;
					}
				}

				std::cout<<endl;
			}
}








