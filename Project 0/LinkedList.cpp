#include <iostream>
using namespace std;

class node
{
	public:
    	double value;
    	node *next;
};

class LinkedList{
	public:
		node *head;
		node *tail;
		int length;

		LinkedList(){
			head = nullptr;
			tail = nullptr;
			length = 0;
		}

		void newNode(double term){
			if(head == nullptr){
				//std::cout<<"Head is a null pointer"<<endl;
				node *temp = new node;
				temp->value = term;
				temp->next = nullptr;

				this->head = temp;
				this->tail = temp;
				//std::cout<<tail->value<<endl;
			}
			else{
				//std::cout<<"Head is not a null pointer"<<endl;
				node *temp = new node;
				node *temp2 = head;

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

		double toArray(){
			/*node *temp = head;
			int degree = 0;
			double list;

			if(temp != nullptr){
				while(true){
				   std::cout<<(temp->value)<<" ";
				   degree++;

					if(temp->next == nullptr){
						break;
					}
					else{
						temp = temp->next;
					}
				}

			std::cout<<endl;
			}*/
		}

		void print(){
			//over written in polynomial sub class
			node *temp = head;

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
};
