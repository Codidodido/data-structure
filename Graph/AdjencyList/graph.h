#include "q.h";
#include "stack.h";

using namespace std;

struct Edge{
	int src;
	int weight;
	Edge* dest;
};

struct AdjencyList{
	Edge* head;
};

class Graph{
	private:
		int v;
		AdjencyList* eList;
	public:
		Graph(int V){
			v = V;
			eList = new AdjencyList[V];
			for(int i = 0; i < v; i++)
				eList[i].head = nullptr;
		}
		
		void AddOneWayEdge(int a, int b, int w){
			Edge* aE = new Edge;
			aE->src = a;
			aE->weight = w;
			aE->dest = eList[b].head;
			eList[b].head = aE;
		}
		
		void AddTwoWayEdge(int a, int b, int w){
			AddOneWayEdge(a,b,w);
			AddOneWayEdge(b,a,w);
		}
		
		void Print(){
			for(int i = 0; i < v; i++){
				Edge *tmp = eList[i].head;
				cout << "Vertex [" << i << "]:\n" ;
				while(tmp){
					cout << "-- " << tmp->weight << " --> ["<<tmp->src << "]\n";
					tmp = tmp->dest;
				}
				cout << endl;
				
			}
		}
		
		AdjencyList* ReturnVertexList(int vertex) {
	        return &eList[vertex]; // Return the adjacency list of the specified vertex
	    }
		
		int ReturnVertexNumber(){
			return v;
		}
		
		void BFS(int start) {
		    bool visited[v] = {false};
		    Q queue;
		    queue.Push(start);
		    visited[start] = true;
		
		    cout << "BFS FROM " << start << " : ";
		    while (!queue.IsEmpty()) {
		        int current = queue.Pop();
		        cout << current << " - ";
		
		        Edge* tmp = eList[current].head;
		        while (tmp) {
		            int neighbor = tmp->src == current ? tmp->dest->src : tmp->src;
		
		            if (!visited[neighbor]) {
		                visited[neighbor] = true;
		                queue.Push(neighbor);
		            }
		            tmp = tmp->dest;
		        }
		    }
		    cout << endl;
		}
		
		void DFS(int start) {
		    bool visited[v] = {false};
		    Stack stack;
		    stack.Push(start);
		    visited[start] = true;
		
		    cout << "DFS FROM " << start << " : ";
		    cout << start << " - ";
		
		    while (!stack.IsEmpty()) {
		        int current = stack.Top();
		        bool hasUnvisitedNeighbor = false;
		        Edge* tmp = eList[current].head;
		
		        while (tmp) {
		            int neighbor = tmp->src == current ? tmp->dest->src : tmp->src;
		            if (!visited[neighbor]) {
		                visited[neighbor] = true;
		                stack.Push(neighbor);
		                cout << neighbor << " - "; 
		                hasUnvisitedNeighbor = true;
		                break;
		            }
		            tmp = tmp->dest;
		        }
		
		        if (!hasUnvisitedNeighbor) {
		            stack.Pop();
		        }
		    }
		}
};