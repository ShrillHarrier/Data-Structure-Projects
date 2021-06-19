/*
 * openhttest.cpp
 *
 *  Created on: Oct. 9, 2020
 *      Author: Matthew
 */

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*#include "DoubleHash.cpp"
//#include "Chaining.cpp"

int main()
{
	string n;
	std::getline(std::cin,n);

	int size = std::stoi(n.substr(2, n.length()-2));

	DoubleHash *list = new DoubleHash(size);

	std::cout<<"success"<<endl;

	string com;
	std::getline(std::cin,com);

	//std::cout<<com.substr(0, 4).compare("exit")<<endl;

	while(com.substr(0, 4).compare("exit") != 0){
		//std::cout<<"got here"<<endl;
		//std::cout<<com[0]<<endl;
		if(com[0] == 'i'){
			//std::cout<<"got here2"<<endl;
			string line = com.substr(2, com.length()-2);
			string k = "";
			int i = 0;

			for(;i < line.length(); i++){
				if(line[i] == ';'){
					i++;
					break;
				}
				k += line[i];
			}

			long int key = std::stoll(k);
			string caller = line.substr(i, line.length() - i);

			//std::cout<<"caller is: "<<caller.length()<<endl;

			//std::cout<<key<< " "<<caller<<endl;

			list->insert(key, caller);
			//std::cout<<"caller is: "<<list->table[0].caller<<endl;
		}
		else if(com[0] == 's'){
			long int k = std::stoll(com.substr(2, com.length() - 2));
			string name = list->search(k);

			//std::cout<<k<<endl;
			//std::cout<<name<<endl;

			//std::cout<<"found "<<name<<" in " + k%(list->size)<<endl;

			if(name.compare("No name with that number.") == 0){
				std::cout<<"not found"<<endl;
			}
			else{
				std::cout<<"found "<<name<<" in "<<k%(list->size)<<endl;
			}
		}
		else if(com[0] == 'd'){
			//std::cout<<"got here"<<endl;
			long int k = std::stoll(com.substr(2, com.length() - 2));
			//std::cout<<"k is: "<<k<<endl;
			list->deleteName(k);
		}

		std::getline(std::cin,com);

		//std::cout<<"com is: "<<com.compare("comm")<<endl;
	}

	return 0;

}*/


