/*
 * Node.cpp
 *
 *  Created on: Nov. 30, 2020
 *      Author: Matthew
 */

class Node{

	public:
		int name;
		int rep;
		int next; //change to node for linked list

		Node(int name){
			this->name = name;
			this->rep = name;
			this->next = name;
		}

		void Settheset(int u){
			this->rep = u;
		}

		void Setthenext(int u){
			this->next = u;
		}
};


