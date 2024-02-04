#include <iostream>
#include "graph.h"

using namespace std;

signed int inf = 2147483647;

int FindMinVertex(Graph *g, int VW[], bool UV[]){
	int v = g->ReturnVertexNumber();
	
	int min = inf;
	int min_index = -1;
	
	for(int i = 0; i < v; i++){
		if(!UV[i] && VW[i] < min){
			min = VW[i];
			min_index = i;
		}
	}
	
	return min_index;
}

void FindPrime(Graph *g, int start){
	int v = g->ReturnVertexNumber();
	int VW[v];
	bool UV[v];
	
	// Vertexes sort by Prime
	
	int V[v];
	
	for(int i = 0; i < v; i++){
		VW[i] = inf;
		UV[i] = false;
		V[i] = -1;
	}
	
	VW[start] = 0;
	
	for(int i = 0; i < v - 1 ; i++){
		int min = FindMinVertex(g, VW, UV);
		UV[min] = true;
		
		Edge* tmp = g->ReturnVertexList(min)->head;
		while(tmp){
			int vertex = tmp->src;
			int weight = tmp->weight;
			
			if(!UV[vertex] && weight < VW[vertex]){
				VW[vertex] = weight;
				V[vertex] = min;
			}
			
			tmp = tmp->dest;
		}
	}
	
	for(int i = 0 ; i < v ; i++){
		if(V[i] != -1)
			cout << V[i] << "-> " << i << "\n";
	}
}

int main(){
	// v = vertices, e = edges
	cout << "-> Welcome To Codidodido Graph <-\n\n";
	
	int v,e;
	
	cout << "-> Enter Graph Vertexes Number: ";
	cin >> v;
	
	Graph *g = new Graph(v);
	
	// s = source, d = destination, w = weight
	int s,d,w,t = -1 ;
	
	int order = -1;
	
	cout << "-> Commands List:\n-> 1. Add Edge\n-> 2. BFS\n-> 3. DFS\n-> 4. Prime\n-> 5. Print Graph\n-> 0. Exit\n";
	
	int data;
	while(order != 0){
		cout << "\n\n-> What to do: ";
		cin >> order;
		switch(order){
			case 1:{
				
				cout << "\t-> Enter src vertex: ";
				cin >> s;
				cout << "\t-> Enter dest vertex: ";
				cin >> d;
				cout << "\t-> Enter src->dest weight: ";
				cin >> w;
				while(t != 1 || t != 2){
					cout << "\t-> Enter edge type (1. One-Way 2. Two-Way): ";
					cin >> t;
					if(t == 1){
						g->AddOneWayEdge(s,d,w);
						break;
					}else if(t == 2){
						g->AddTwoWayEdge(s,d,w);
						break;
					}	
				}
				cout << "\t-> Edge Added!";
				break;
			}
			
			case 2:{
				cout << "\t-> Enter start vertex: ";
				cin >> data;
				g->BFS(data);
				break;
			}
			
			case 3:{
				cout << "\t-> Enter start vertex: ";
				cin >> data;
				g->DFS(data);
				break;
				
			}
				
			case 4:{
				cout << "\t-> Enter start vertex: ";
				cin >> data;
				FindPrime(g,data);
				break;
			}	
			
			case 5:{
				
				g->Print();
				break;
			}
				
			case 0:{
				break;
			}
				
			default:
				cout << "Invalid Command";
				
						
		}
	}
}