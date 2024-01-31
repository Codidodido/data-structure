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
}