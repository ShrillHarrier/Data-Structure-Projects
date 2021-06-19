/*
 * Quadtree.cpp
 *
 *  Created on: Nov. 3, 2020
 *      Author: Matthew
 */

#include <iomanip>
#include "City.cpp"
#include <iostream>
using namespace std;

class Quadtree{
	private:
		City *root;
		int length;

	public:
		Quadtree(){
			root = nullptr;
			length = 0;
		}

		//Insert functions start
		void insertCity(string name, double x, double y, double population, double col, double salary){
			City *insert = new City(name, x, y, population, col, salary);

			if(this->root == nullptr){
				this->root = insert;
				length++;
				std::cout<<"success"<<std::endl;
			}
			else{
				City *temp = this->root;
				City *prev = this->root;
				recursiveNode(insert, temp, prev);
			}
		}

		void recursiveNode(City *insert, City *temp, City *prev){
			if(temp == nullptr){ //Base Case
				if(insert->x >= prev->x && insert->y > prev->y){
					prev->ne = insert;
				}
				else if(insert->x < prev->x && insert->y >= prev->y){
					prev->nw = insert;
				}
				else if(insert->x <= prev->x && insert->y < prev->y){
					prev->sw = insert;
				}
				else if(insert->x > prev->x && insert->y <= prev->y){
					prev->se = insert;
				}
				length++;
				std::cout<<"success"<<std::endl;
			}
			else if(insert->x == temp->x && insert->y == temp->y){ //Another base case
				delete insert;
				insert = nullptr;
				std::cout<<"failure"<<std::endl;
			}
			else if(insert->x >= temp->x && insert->y > temp->y){
				recursiveNode(insert, temp->ne, temp);
			}
			else if(insert->x < temp->x && insert->y >= temp->y){
				recursiveNode(insert, temp->nw, temp);
			}
			else if(insert->x <= temp->x && insert->y < temp->y){
				recursiveNode(insert, temp->sw, temp);
			}
			else if(insert->x > temp->x && insert->y <= temp->y){
				recursiveNode(insert, temp->se, temp);
			}
		}
		//Insert functions end

		//Search function start
		void searchTree(double x, double y){
			City *location = recursiveSearch(this->root, x, y);

			if(location == nullptr){
				std::cout<<"not found"<<std::endl;
			}
			else{
				std::cout<<"found "<<location->name<<std::endl;
			}
		}

		City *recursiveSearch(City *temp, double x, double y){
			if(temp == nullptr){ //Base Case
				return nullptr;
			}
			else if(x == temp->x && y == temp->y){ //Another base case
				return temp;
			}
			else if(x >= temp->x && y > temp->y){
				return recursiveSearch(temp->ne, x, y);
			}
			else if(x < temp->x && y >= temp->y){
				return recursiveSearch(temp->nw, x, y);
			}
			else if(x <= temp->x && y < temp->y){
				return recursiveSearch(temp->sw, x, y);
			}
			else if(x > temp->x && y <= temp->y){
				return recursiveSearch(temp->se, x, y);
			}
		}
		//Search functions end

		//Print functions start
		void printTree(){
			int count = this->length;
			recursivePrint(this->root, count);
			std::cout<<std::endl;
		}

		void recursivePrint(City *temp, int &count){

		    if(temp != nullptr){

		    	recursivePrint(temp->ne, count);
		    	recursivePrint(temp->nw, count);

		        std::cout<<temp->name;
		        count--;
		        if(count != 0){
		        	std::cout<<" ";
		        }

		        recursivePrint(temp->sw, count);
		        recursivePrint(temp->se, count);

		    }

		}
		//Print functions end

		//Total functions start
		void printTotal(double x, double y, int d, int attr){
				City *start = recursiveSearch(this->root, x, y);

				if(start == nullptr || (d == 1 && start->ne == nullptr) || (d == 2 && start->nw == nullptr) || (d == 3 && start->se == nullptr) || (d == 4 && start->sw == nullptr)){
					std::cout<<"failure"<<endl;
				}
				else{
					int precise;

					if(attr == 1){
						precise = 0;
					}
					else{
						precise = 2;
					}

					if(d == 1){
						std::cout<<std::fixed<<std::setprecision(precise)<<"total "<<getTotal(start->ne, attr)<<endl;
					}
					else if(d == 2){
						std::cout<<std::fixed<<std::setprecision(precise)<<"total "<<getTotal(start->nw, attr)<<endl;
					}
					else if(d == 3){
						std::cout<<std::fixed<<std::setprecision(precise)<<"total "<<getTotal(start->se, attr)<<endl;
					}
					else if(d == 4){
						std::cout<<std::fixed<<std::setprecision(precise)<<"total "<<getTotal(start->sw, attr)<<endl;
					}
				}
		}

		double getTotal(City *temp, int attr){
			double count = 0;

			if(temp == nullptr){
				return count;
			}
			else{
				if(attr == 1){
					count = temp->population;
				}
				else if(attr == 2){
					count = temp->col;
				}
				else if(attr == 3){
					count = temp->salary;
				}
				return count + getTotal(temp->ne, attr) + getTotal(temp->nw, attr) + getTotal(temp->se, attr) + getTotal(temp->sw, attr);
			}
		}
		//Total functions end

		//Max functions start
		void printMax(double x, double y, int d, int attr){
						City *start = recursiveSearch(this->root, x, y);

						if(start == nullptr || (d == 1 && start->ne == nullptr) || (d == 2 && start->nw == nullptr) || (d == 3 && start->se == nullptr) || (d == 4 && start->sw == nullptr)){
							std::cout<<"failure"<<endl;
						}
						else{
							int precise;

							if(attr == 1){
								precise = 0;
							}
							else{
								precise = 2;
							}

							double max = -1;

							if(d == 1){
								getMax(start->ne, attr, max);
							}
							else if(d == 2){
								getMax(start->nw, attr, max);
							}
							else if(d == 3){
								getMax(start->se, attr, max);
							}
							else if(d == 4){
								getMax(start->sw, attr, max);
							}
							std::cout<<std::fixed<<std::setprecision(precise)<<"max "<<max<<endl;
						}
				}

				void getMax(City *temp, int attr, double &currentmax){
					double max = -1;

					if(temp != nullptr){
						if(attr == 1){
							max = temp->population;
						}
						else if(attr == 2){
							max = temp->col;
						}
						else if(attr == 3){
							max = temp->salary;
						}

						if(max > currentmax){
							currentmax = max;
						}

						getMax(temp->ne, attr, currentmax);
						getMax(temp->nw, attr, currentmax);
						getMax(temp->se, attr, currentmax);
						getMax(temp->sw, attr, currentmax);
					}
				}
		//Max functions end

		//Min functions start
				void printMin(double x, double y, int d, int attr){
										City *start = recursiveSearch(this->root, x, y);

										if(start == nullptr || (d == 1 && start->ne == nullptr) || (d == 2 && start->nw == nullptr) || (d == 3 && start->se == nullptr) || (d == 4 && start->sw == nullptr)){
											std::cout<<"failure"<<endl;
										}
										else{
											int precise;

											if(attr == 1){
												precise = 0;
											}
											else{
												precise = 2;
											}

											double min = 99999999999;

											if(d == 1){
												getMin(start->ne, attr, min);
											}
											else if(d == 2){
												getMin(start->nw, attr, min);
											}
											else if(d == 3){
												getMin(start->se, attr, min);
											}
											else if(d == 4){
												getMin(start->sw, attr, min);
											}
											std::cout<<std::fixed<<std::setprecision(precise)<<"min "<<min<<endl;
										}
								}

								void getMin(City *temp, int attr, double &currentmin){
									double min = -1;

									if(temp != nullptr){
										if(attr == 1){
											min = temp->population;
										}
										else if(attr == 2){
											min = temp->col;
										}
										else if(attr == 3){
											min = temp->salary;
										}

										if(min < currentmin){
											currentmin = min;
										}

										getMin(temp->ne, attr, currentmin);
										getMin(temp->nw, attr, currentmin);
										getMin(temp->se, attr, currentmin);
										getMin(temp->sw, attr, currentmin);
									}
								}
		//Min functions end

		//Get size start
		void getLength(){
			//std::cout<<"Get to here too"<<endl;
			std::cout<<"tree size "<<this->length<<endl;
		}
		//Get size end

		//Clear function start
		void callClear(){
			recursiveClear(this->root);
			std::cout<<"success"<<std::endl;
		}

		void recursiveClear(City *temp){
		    if (temp != nullptr){
		    	recursiveClear(temp -> ne);
		    	recursiveClear(temp -> nw);
		    	recursiveClear(temp -> se);
		    	recursiveClear(temp -> sw);

		        delete temp;
		        temp = nullptr;
		        this->length--;
		    }
		    if(this->length == 0){
		        this->root = nullptr;
		    }
		}
		//Clear function end

		~Quadtree(){
			recursiveClear(this->root);
		}
};



