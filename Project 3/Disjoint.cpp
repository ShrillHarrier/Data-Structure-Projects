/*
 * Disjoint.cpp
 *
 *  Created on: Nov. 29, 2020
 *      Author: Matthew
 */

#include "Node.cpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Disjoint{
	public:
		int m;
		Node *nodes;

			Disjoint(int m){
				this->m = m;
			}

			void Makeset(){
				nodes = (Node*)malloc(sizeof(Node)*m);
				for(int i = 0; i < m; i++){
					nodes[i] = Node(i);
				}
			}

			void Union(int u, int v){
				//std::cout<<"In Union"<<endl;

				//std::cout<<"In Union Two "<<Findset(u)<<endl;
				//std::cout<<"In Union Three "<<Findset(v)<<endl;

				int setchange = Findset(v);

				nodes[v].Settheset(Findset(u)); //stack dump here

				//change to iterate by next value
				for(int i = 0; i < m; i++){
					if(Findset(i) == setchange){
						nodes[i].Settheset(Findset(u));
						//std::cout<<"Changed set to "<<Findset(i)<<" for "<<i<<endl;
					}
				}

				nodes[u].Setthenext(nodes[v].name); //stack dump here

				//std::cout<<"In Union Four "<<Findset(v)<<endl;
			}

			int Findset(int u){
				//std::cout<<nodes[u].rep;
				return nodes[u].rep;
			}

			~Disjoint(){
				free(nodes);
			}

};


