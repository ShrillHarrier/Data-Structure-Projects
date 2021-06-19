/*
 * LinkedList.cpp
 *
 *  Created on: Nov. 30, 2020
 *      Author: Matthew
 */

#include <iostream>

class LinkedList{
	/*public:
		Node *head;
		Node *tail;
		int length;

		LinkedList(){
			head = nullptr;
			tail = nullptr;
			length = 0;
		}

		void newNode(double term){
			if(head == nullptr){
				//std::cout<<"Head is a null pointer"<<endl;
				Node *temp = new Node;
				temp->value = term;
				temp->next = nullptr;

				this->head = temp;
				this->tail = temp;
				//std::cout<<tail->value<<endl;
			}
			else{
				//std::cout<<"Head is not a null pointer"<<endl;
				Node *temp = new Node;
				Node *temp2 = head;

				temp->value = term;
				temp->next = nullptr;

				while(temp2->next != nullptr){
					temp2 = temp2->next;
				}

				temp2->next = temp;
				this->tail = temp;
				//std::cout<<tail->value<<endl;
			}

			length++;
			std::cout<<(this->length)<<endl;
		}

		}

		void print(){
			//over written in polynomial sub class
			Node *temp = head;

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
		*/
};


