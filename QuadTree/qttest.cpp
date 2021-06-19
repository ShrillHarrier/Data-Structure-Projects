/*
 * qttest.cpp
 *
 *  Created on: Nov. 3, 2020
 *      Author: Matthew
 */

#include "Quadtree.cpp"

#include <iostream>
using namespace std;

int main()
{
	Quadtree *tree = new Quadtree;

	string com;
	std::getline(std::cin,com);

	//std::cout<<com.substr(0, 4).compare("exit")<<std::endl;

	while(com.substr(0, 4).compare("exit") != 0){
			if(com.substr(0, 4).compare("size") == 0){
				//std::cout<<"Get to here"<<endl;
				tree->getLength();
			}
			else if(com[0] == 'i'){
				int i = 2;
				string name = "";
				string x = "";
				string y = "";
				string p = "";
				string r = "";
				string s = "";

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					name += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					x += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					y += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					p += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					r += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					s += com[i];
				}

				tree->insertCity(name, std::stod(x), std::stod(y), std::stod(p), std::stod(r), std::stod(s));
			}
			else if(com[0] == 's'){
				int i = 2;
				string x = "";
				string y = "";

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					x += com[i];
				}

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					y += com[i];
				}

				tree->searchTree(std::stod(x), std::stod(y));
			}
			else if(com.substr(0, 5).compare("q_max") == 0){
				int i = 6;
				string x = "";
				string y = "";
				int d = 0;
				int attr = 0;

				for(;i < com.length(); i++){
					if(com[i] == ';'){
						i++;
						break;
					}
					x += com[i];
				}

				for(;i < com.length(); i++){
									if(com[i] == ';'){
										i++;
										break;
									}
									y += com[i];
								}

				if(com.substr(i, 2).compare("NE") == 0){
					d = 1;
				}
				else if(com.substr(i, 2).compare("NW") == 0){
					d = 2;
				}
				else if(com.substr(i, 2).compare("SE") == 0){
					d = 3;
				}
				else if(com.substr(i, 2).compare("SW") == 0){
					d = 4;
				}

				i += 3;

				if(com[i] == 'p'){
					attr = 1;
				}
				else if(com[i] == 'r'){
					attr = 2;
				}
				else if(com[i] == 's'){
					attr = 3;
				}

				//std::cout<<x<<" "<<y<<" "<<d<<" "<<attr<<endl;

				tree->printMax(std::stod(x), std::stod(y), d, attr);
			}
			else if(com.substr(0, 5).compare("q_min") == 0){
							int i = 6;
							string x = "";
							string y = "";
							int d = 0;
							int attr = 0;

							for(;i < com.length(); i++){
								if(com[i] == ';'){
									i++;
									break;
								}
								x += com[i];
							}

							for(;i < com.length(); i++){
												if(com[i] == ';'){
													i++;
													break;
												}
												y += com[i];
											}

							if(com.substr(i, 2).compare("NE") == 0){
								d = 1;
							}
							else if(com.substr(i, 2).compare("NW") == 0){
								d = 2;
							}
							else if(com.substr(i, 2).compare("SE") == 0){
								d = 3;
							}
							else if(com.substr(i, 2).compare("SW") == 0){
								d = 4;
							}

							i += 3;

							if(com[i] == 'p'){
								attr = 1;
							}
							else if(com[i] == 'r'){
								attr = 2;
							}
							else if(com[i] == 's'){
								attr = 3;
							}

							//std::cout<<x<<" "<<y<<" "<<d<<" "<<attr<<endl;

							tree->printMin(std::stod(x), std::stod(y), d, attr);
						}
			else if(com.substr(0, 7).compare("q_total") == 0){
							int i = 8;
							string x = "";
							string y = "";
							int d = 0;
							int attr = 0;

							for(;i < com.length(); i++){
								if(com[i] == ';'){
									i++;
									break;
								}
								x += com[i];
							}

							for(;i < com.length(); i++){
												if(com[i] == ';'){
													i++;
													break;
												}
												y += com[i];
											}

							if(com.substr(i, 2).compare("NE") == 0){
								d = 1;
							}
							else if(com.substr(i, 2).compare("NW") == 0){
								d = 2;
							}
							else if(com.substr(i, 2).compare("SE") == 0){
								d = 3;
							}
							else if(com.substr(i, 2).compare("SW") == 0){
								d = 4;
							}

							i += 3;

							if(com[i] == 'p'){
								attr = 1;
							}
							else if(com[i] == 'r'){
								attr = 2;
							}
							else if(com[i] == 's'){
								attr = 3;
							}

							//std::cout<<x<<" "<<y<<" "<<d<<" "<<attr<<endl;

							tree->printTotal(std::stod(x), std::stod(y), d, attr);
			}
			else if(com.substr(0, 5).compare("print") == 0){
				tree->printTree();
			}
			else if(com.substr(0, 5).compare("clear") == 0){
				tree->callClear();
				//std::cout<<"tree size: "<<tree->getLength()<<endl;
			}

			std::getline(std::cin,com);

	}

	delete tree;
	tree = nullptr;

	return 0;
}




