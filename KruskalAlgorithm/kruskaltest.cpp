/*
 * kruskaltest.cpp
 *
 *  Created on: Nov. 29, 2020
 *      Author: Matthew
 */

#include <iostream>

#include "Graph.cpp"
using namespace std;

int main()
{

		string com = "Just for intial";
		//std::getline(std::cin,com);
		Graph *tree;

		//std::cout<<std::stoi(com.substr(2,1))<<endl;
		/*try{
			tree = new Graph(std::stoi(com.substr(2,com.length() - 1)));
		}
		catch(InvalidArgument){
			std::cout<<"invalid argument"<<endl;
		}*/

		while(com.substr(0, 4).compare("exit") != 0){
			    if(com[0] == 'n'){
			    	try{
			    		tree = new Graph(std::stoi(com.substr(2,com.length() - 2)));
			    	}
			    	catch(InvalidArgument){
			    		std::cout<<"invalid argument"<<endl;
			    	}
			    }
			    else if(com[0] == 'i'){
					int i = 2;
					string u = "";
					string v = "";
					string w = "";

					for(;i < com.length(); i++){
						if(com[i] == ';'){
							i++;
							break;
						}
						u += com[i];
					}

					for(;i < com.length(); i++){
						if(com[i] == ';'){
							i++;
							break;
						}
						v += com[i];
					}

					w = com.substr(i,com.length()-i);

					//std::cout<<u<<" "<<v<<" "<<w<<endl;
					try{
						tree->Insert(std::stoi(u), std::stoi(v), std::stod(w));
					}
					catch(InvalidArgument){
						std::cout<<"invalid argument"<<endl;
					}
				}
				else if(com.substr(0, 6).compare("degree") == 0){

					//std::cout<<std::stoi(com.substr(7,1))<<endl;

					try{
						int deg = tree->Degree(std::stoi(com.substr(7,com.length()-7)));
						std::cout<<"degree of "<<std::stoi(com.substr(7,com.length()-7))<<" is "<<deg<<endl;
					}
					catch(InvalidArgument){
						std::cout<<"invalid argument"<<endl;
					}

				}
				else if(com[0] == 'd'){
					int i = 2;
					string u = "";
					string v = "";

					for(;i < com.length(); i++){
						if(com[i] == ';'){
							i++;
							break;
						}
						u += com[i];
					}

					v = com.substr(i,com.length()-i);

					//std::cout<<u<<" "<<v<<endl;

					try{
						tree->Delete(std::stoi(u), std::stoi(v));
					}
					catch(InvalidArgument){
						std::cout<<"invalid argument"<<endl;
					}
				}
				else if(com.substr(0, 10).compare("edge_count") == 0){

					std::cout<<"edge count is "<<tree->Edgecount()<<endl;

				}
				else if(com.substr(0, 5).compare("clear") == 0){

					tree->Clear();

				}
				else if(com.substr(0, 3).compare("mst") == 0){

					tree->MST();

				}

				std::getline(std::cin,com);
		}

		delete tree;
		tree = nullptr;

	return 0;
}


