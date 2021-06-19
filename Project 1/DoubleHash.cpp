/*
 * DoubleHash.cpp
 *
 *  Created on: Oct. 7, 2020
 *      Author: Matthew
 */

#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

#include "Person.cpp"

class DoubleHash{

public:
	int size;
	std::vector<Person> table;

		DoubleHash(int m){
			size = m;

			for(int i = 0; i<m; i++){ //Fills vector with NoName value
				Person *temp = new Person("No name here.", 0);
				table.push_back(*temp);
			}

		}

		string search(long long int k){
			long long int h1 = k % size;
			long long int h2 = (int)((int)floor(k/size)%size);

			if(h2 % 2 == 0){
				h2 += 1;
			}

			if(table[h1].number != 0){
				return table[h1].caller;
			}
			else{
				for(int i = 1; i < size; i++){
					long long int newkey = (h1+i*h2)%size;
					//std::cout<<"New key is: "<<newkey<<endl;
				    //std::cout<<"New caller in table is: "<<table[newkey].caller<<endl;
					if(table[newkey].caller.compare("No name here.") == 0){
						return "No name with that number.";
					}
					else if(table[newkey].number == k){
						return table[newkey].caller;
					}
				}
			}
			/*for(int i = 0; i < size; i++){
				if(table[i].number == k){
					return table[i].caller;
				}
			}*/

			return "No name with that number.";
		}

		void deleteName(long long int k){
			bool found = false;
			for(int i = 0; i < size; i++){
				//std::cout<<table[i].number<<endl;
				if(table[i].number == k){
					table[i].caller = "Name was deleted.";
					table[i].number = 0;
					found = true;
					break;
				}
			}

			if(found == true){
				std::cout<<"success"<<endl;
			}
			else{
				std::cout<<"failure"<<endl;
			}

		}

		bool isDup(long long int k){
					for(int i = 0; i<size; i++){
						if(table[i].number == k){
							return true;
						}
					}

					return false;
				}

		void collision(long long int k, string caller){
			int h1 = k % size;
			int h2 = (int)((int)floor(k/size)%size);

			if(h2 % 2 == 0){
				h2 += 1;
			}

			for(int i = 1; i < size+1; i++){
				int newkey = (h1+i*h2)%size;
				//std::cout<<"New key is: "<<newkey<<endl;
				if(table[newkey].number == 0){
					table[newkey].caller = caller;
					table[newkey].number = k;
					break;
				}
			}
		}

		bool isFull(){
			for(int i = 0; i<size; i++){
				if(table[i].number == 0){
					return false;
				}
			}

			return true;
		}

		void insert(long long int k, string caller){
			long long int h1 = k % size;
			if(this->isFull() == true){
				std::cout<<"failure"<<endl;
			}
			else if(this->isDup(k) == true){
				std::cout<<"failure"<<endl;
			}
			else{
				//std::cout<<"gets here1"<<endl;
				if(table[h1].number == 0){
					//std::cout<<"gets here2"<<endl;
					table[h1].caller = caller;
					table[h1].number = k;
				}
				else{
					this->collision(k, caller);
				}
				std::cout<<"success"<<endl;
			}

		}

};






