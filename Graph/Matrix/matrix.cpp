#include <iostream>
using namespace std;

signed int inf = 2147483647;

struct MinEdgeIndex {
    int firstIndex;
    int secondIndex;
};

class Graph{
	private:
		int v;
		int** graph;
	public:
		Graph(int V){
			v = V;
			graph = new int*[V];
			for(int i = 0; i < v; i++){
				graph[i] = new int[V];
				for(int j = 0; j < v; j++)
					graph[i][j] = 0;
			}
		}
		
		void AddEdge(int a, int b, int weight){
			graph[a][b] = weight;
			graph[b][a] = weight;
		}
		
		void RemoveEdge(int a, int b){
			graph[a][b] = 0;
			graph[b][a] = 0;
		}
		
		//Minimum edge index
		
		MinEdgeIndex FindMinEdge() {
	        int min = inf;
	        MinEdgeIndex minIndex = {-1, -1};
	        for (int i = 0; i < v; i++) {
	            for (int j = 0; j < v; j++) {
	                if (graph[i][j] < min && graph[i][j] != 0 ) {
	                    min = graph[i][j];
	                    minIndex.firstIndex = i;
	                    minIndex.secondIndex = j;
	                }
	            }
	        }
	        
	        return minIndex;
    	}
		
		int Find(int a, int b){
			return graph[a][b];
		}
		
		void Print(){
			for(int i = 0; i < v ; i++){
				for(int j = 0 ; j < v ; j++){
					cout << graph[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
};

int main(){
	// v = vertices, e = edges
	cout << "-> Welcome To Codidodido Graph <-\n\n";
	
	int v,e;
	
	cout << "-> Enter Graph Vertexes Number: ";
	cin >> v;
	
	Graph g = Graph(v);
	
	// s = source, d = destination, w = weight
	int s,d,w;
	
	int order = -1;
	
	cout << "-> Commands List:\n-> 1. Add Edge\n-> 2. Remove Edge\n-> 3. Find Edge\n-> 4. Find Min Edge\n-> 5. Print Graph\n-> 0. Exit\n";
	
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
				g.AddEdge(s,d,w);
				cout << "\t-> Edge Added!";
				break;
			}
			
			case 2:{
				
				cout << "\t-> Enter src vertex: ";
				cin >> s;
				cout << "\t-> Enter dest vertex: ";
				cin >> d;
				g.RemoveEdge(s,d);
				cout << "\t-> Edge Removed!";
				break;
			}
			
			case 3:{
				
				int i = g.FindMinEdge().firstIndex;
				int j = g.FindMinEdge().secondIndex;
				cout << "\t-> Min Edge Is Connection Between " << i << " -> " << j << " And Its Weight Is: " << g.Find(i,j);
				break;
			}
				
			case 4:{
				
				cout << "\t-> Enter src vertex: ";
				cin >> s;
				cout << "\t-> Enter dest vertex: ";
				cin >> d;
				w = g.Find(s,d);
				cout << "\t-> Weight Of Edge Between " << s << " -> " << d << " Is: " << w;
				break;
			}
			
			case 5:{
				
				g.Print();
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