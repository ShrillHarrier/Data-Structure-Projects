/*
 * orderedhttest.cpp
 *
 *  Created on: Oct. 9, 2020
 *      Author: Matthew
 */

#include <iostream>
using namespace std;

//#include "DoubleHash.cpp";
#include "Chaining.cpp"

int main()
{

	Chaining *list;

	string com;
	std::getline(std::cin,com);

	//std::cout<<com.substr(0, 4).compare("exit")<<endl;

	while(com.substr(0, 4).compare("exit") != 0){
		//std::cout<<"got here"<<endl;
		//std::cout<<com[0]<<endl;
		if(com[0] == 'n'){
			int size = std::stoll(com.substr(2, com.length()-2));

				list = new Chaining(size);

				std::cout<<"success"<<endl;
		}
		else if(com[0] == 'i'){
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
				//std::cout<<"string is: "<<k<<endl;
			}

			long long int key = std::stoll(k.substr(0,10));
			string caller = line.substr(i, line.length()-i);

			//std::cout<<"key is: "<<key<<endl;
			list->insert(key, caller);

			//std::cout<<"number is: "<<list->table[0]->getHead()->number<<endl;
		}
		else if(com[0] == 's'){
			long long int k = std::stoll(com.substr(2, 10));
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
			long long int k = std::stoll(com.substr(2, com.length() - 2));
			//std::cout<<"k is: "<<k<<endl;
			list->deleteName(k);
		}
		else if(com[0] == 'p'){
			long long int k = std::stoll(com.substr(2, 1));
			list->printList(k);
		}

		std::getline(std::cin,com);

		//std::cout<<"com is: "<<com.compare("comm")<<endl;
	}

	return 0;

}


