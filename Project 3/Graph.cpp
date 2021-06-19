/*
 * SpanningTree.cpp
 *
 *  Created on: Nov. 29, 2020
 *      Author: Matthew
 */

#include "Edge.cpp"
#include "Disjoint.cpp"
#include "InvalidArgument.cpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

class Graph{
	public:
		const double inf = std::numeric_limits<double>::max();
	    int size;
	    int edgesize;
	    std::vector<vector<double>> matrix;
		//std::vector<Node> nodes;
		std::vector<Edge> edges;

		Graph(int m){
			if(m <= 0){
				throw InvalidArgument();
			}
			else{
				this->size = m;
				this->edgesize = 0;

				for(int i = 0; i < m; i++){
					//nodes.push_back(Node(i));

					std::vector<double> row;

					for(int j = 0; j < m; j++){
						row.push_back(inf);
					}

					matrix.push_back(row);
				}

				std::cout<<"success"<<endl;
			}
		}

		void Insert(int u, int v, double w){
			if(u < 0 || u >= size || v < 0 || v >= size || w <= 0){
				throw InvalidArgument();
			}
			else{
				/*if(u > v){
					int temp = u;
					u = v;
					v = temp;
				}*/
				matrix[u][v] = w;
				matrix[v][u] = w;

				for(int i = 0; i < edgesize; i++){
					if(edges[i].u == u && edges[i].v == v){
						edges.erase(edges.begin() + i);
					}
				}

				edges.push_back(Edge(u,v,w));

				edgesize++;

				std::cout<<"success"<<endl;
			}
		}

		void Delete(int u, int v){
			if(u < 0 || u >= size || v < 0 || v >=size){
				throw InvalidArgument();
			}
			else{
				/*if(u > v){
					int temp = u;
					u = v;
					v = temp;
				}*/
				if(matrix[u][v] != inf){
					matrix[u][v] = inf;
					matrix[v][u] = inf;

					for(int i = 0; i < edgesize; i++){
						if(edges[i].u == u && edges[i].v == v){
							edges.erase(edges.begin() + i);
						}
					}

					edgesize--;

					std::cout<<"success"<<endl;
				}
				else{
					std::cout<<"failure"<<endl;
				}
			}
		}

		int Degree(int u){
			if(u < 0 || u >= size){
				throw InvalidArgument();
			}
			else{
				int deg = 0;

				for(int i = 0; i<size; i++){
					if(matrix[u][i] != inf){
						if(u == i){
							deg += 2;
						}
						else{
							deg++;
						}
					}
				}

				return deg;
			}
		}

		int Edgecount(){
			return this->edgesize;
		}

		void Clear(){
			for(int i = 0; i<size; i++){
				for(int j = 0; j<size; j++){
					matrix[i][j] = inf;
				}
			}

			for(int i = 0; i<edgesize; i++){
				edges.erase(edges.begin() + i);
			}

			edgesize = 0;

			std::cout<<"success"<<endl;
		}

		void MST() {
			Disjoint set = Disjoint(size);
			bool connected = true;

			Edge *sortededges = (Edge*)malloc(sizeof(Edge)*edgesize);
			std::copy(edges.begin(), edges.end(), sortededges);

			this->MergeSort(sortededges, 0, edgesize - 1);

			/*for(int i = 0; i < edgesize; i++){
				std::cout<<sortededges[i].w<<" ";
			}

			std::cout<<endl;*/

			set.Makeset();

			double weight = 0;
					for(int i = 0; i < edgesize; i++){
								/*std::cout<<"Got here one"<<endl;
								std::cout<<sortededges[i].w<<endl;
								std::cout<<"Got here two"<<endl;*/

					if(set.Findset(sortededges[i].u) != set.Findset(sortededges[i].v)){
									/*std::cout<<"u: "<<sortededges[i].u<<endl;
									std::cout<<"v: "<<sortededges[i].v<<endl;*/
						set.Union(sortededges[i].u, sortededges[i].v);
									//std::cout<<"Current Weigth: "<<sortededges[i].w<<endl;
						weight += sortededges[i].w;
					}
			}

			//std::cout<<set.Findset(0)<<endl;

			for(int i = 1; i<size; i++){
				//std::cout<<"Set for "<<i<<" "<<set.Findset(i)<<endl;
				if(set.Findset(i) != set.Findset(0)){
					connected = false;
					break;
				}
			}

			if(connected == false){
				std::cout<<"not connected"<<endl;
			}
			else{
				/*std::cout<<"Set Is: "<<set.Findset(sortededges[0].u)<<endl;

				std::cout<<"Got here one"<<endl;

				std::cout<<sortededges[0].w<<endl;

				std::cout<<"Got here two"<<endl;*/

				/*for(int i = 0; i<edgesize; i++){
					std::cout<<"u: "<<sortededges[i].u<<" set: "<<set.Findset(sortededges[i].u)<<endl;
					std::cout<<"v: "<<sortededges[i].v<<" set: "<<set.Findset(sortededges[i].v)<<endl;
				}*/

				std::cout<<std::fixed<<std::setprecision(2)<<"mst "<<weight<<endl;
			}

			free(sortededges);
		}

		/*void insertionSort(Edge *arr, std::vector<Edge> temp){
			//std::vector<Edge> temp = edges;
			//Edge *arr = (Edge*)malloc(sizeof(Edge)*edgesize);

			for(int i = 0; i <edgesize; i++){
				double min = inf;
				int index;

				for(int j = 0; j < edgesize - i; j++){
					if(temp[j].w < min){
						//std::cout<<temp[j].w<<endl;
						min = temp[j].w;
						index = j;
					}
				}

				arr[i] = temp[index];
				temp.erase(temp.begin() + index);

				//std::cout<<arr[i].w<<" ";
			}

			//std::cout<<endl;

			//std::cout<<"Function Works"<<endl;
			for(int i = 0; i < edgesize; i++){
							std::cout<<arr[i].w<<" ";
						}

			//std::cout<<endl;
			//return arr;
		}*/

		void MergeSort(Edge *arr, int start, int finish){
		    if(start >= finish){
		        return;
		    }

		    int bisection = (finish + start - 1)/2;

		    MergeSort(arr,start,bisection);

		    MergeSort(arr,bisection + 1,finish);

		    Combine(arr, start, bisection, finish);
		}

		void Combine(Edge *arr, int start, int bisection, int finish) {
		    std::vector<Edge> left;
		    std::vector<Edge> right;

		    int side2 = finish - bisection;
		    int side1 = bisection - start + 1;

		   	int i = 0;
		   	int j = 0;
		   	int k = start;

		    for (int j = 0; j < side2; j++){
		        right.push_back(arr[bisection + j + 1]);
		    }

		    for (int i = 0; i < side1; i++){
		    	left.push_back(arr[start + i]);
		    }

		    while (i < side1 && j < side2) {
		        if (left[i].w <= right[j].w) {
		            arr[k] = left[i];
		            i++;
		        }
		        else {
		            arr[k] = right[j];
		            j++;
		        }
		        k++;
		    }

		    while (i < side1) {
		        arr[k] = left[i];
		        i++;
		        k++;
		    }

		    while (j < side2) {
		    	arr[k] = right[j];
		        j++;
		        k++;
		    }
		}

		~Graph(){
			size = 0;
			edgesize = 0;
		}

};




