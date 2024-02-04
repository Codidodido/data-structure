# Data Structure
Learning data structure together 

# Contens
- Linked List
- Graph
- Sort
- Tree
- TODO

# Linked List

Simple arrays are limited and can not be resized. Additionally, when you remove a data from an array, memory which filled with that data isn't freed. Therefore, linked list is a solution for lack of size limitation and allows for more flexible memory allocation.

As its name is, linked Lists are linked together like a chain. Every item in linked list has two property, data and an address to next item. We name linked list items as **node**.

Data can be anything. Address is same type of linked list . Node points to next node trough address property. It's good to know that there is no node to point to first node and last node doesn't point to any node. Look at below example: 

[Node1]->[Node2]->[Node3]->[Node4]->null

- Node 4 is last item and node 1 is first item.
- These node are connected to each other by address property.
- Address property is a pointer which point to next node.

### How to create a linked list?

First of all, we create a structure which has two properties as we mentioned, data and address.

```cpp
struct Node{
    int data;
    Node* next;
};
```

As you see, I created a structure which name is **Node**. This node has two properties which are an int data and a pointer to next node. This pointer conect nodes like a chain which we name it linked list.

# Graph

Do you ever think about train lines, airplane lines, or even road lines ? Do you ever think about connection between peoples in our world or social medias? Have you ever mind how could GPS programs find closest way to your destination ? All are **graph**.

In simple language, graph is collection of points which are linked together by lines. We call these points vertices and these lines edges. 

There are many theoretical and mathematical things about graph which are not our goal in this article. We will learn how to create a graph and use it.

#### Basic Knowledge:
- Graph has vertices which are linked together by edges.
- Each edge has a weight, which can be destination, or power, or any relation between vertices.
- Vertices which are not connected call as isolated vertex .
- Path is collection of edges which are start from a vertex and end to any vertex.
- Cycle is collection of edges which are start from a vertex and end to it.
- Maximum outgoing edges from a vertex is -> vertices - 1
- Maximum edges of a graph is -> ((vertices)*(vertices-1))/2


### How to create a graph ?

There is two famous way to make graph: 

- Matrix
- Adjency List

#### Matrix:

We can Imagine a graph like a square matrix. Each row and column belong to a vertex. Edges start from a vertex and end to another vertex, with a speceif weight. So we can display it with matrix like : 

  a b c d
a 0 0 1 5
b 0 0 0 0
c 1 0 0 7
d 5 0 7 0

This is a graph with 4 vertices. Vertex 'a' is connected to 'c' and 'd' and. Vertex 'c' also connected to 'a' and 'd'. Vertext 'd' is connected to 'a' and 'c'. Also, each edge has its specefic weight . For example 'a'->'d' is 1 and 'd'->'c' is 7.

We can create it with 2D array.

```cpp
// v = vertices , e = edges
int v,e;
float graph[v][v];
// s = source, d = destination, w = weight
int s,d,w;
for(int i = 0; i < e; i++){
    cin >> s;
    cin >> d;
    cin >> w;
    graph[s][d] = w;
    graph[d][s] = w;
}
```
### Adjency List

Adjency list is an array where each item is head of a linked list chain. To explain in simple terms, each item of adjency list represent as a vertex, which is of type **Node**. Edges would be connected by pointing to source vertex with target vertex and vice versa.

Look at this example array: 

[
[A] => B -> D,
[B] => A,
[C] => E,
[D] => E -> A,
[E] => D -> C
]

```cpp
// Implement Node

struct AdjencyList{
  Node* head;
}

class Graph{
  private:
    int v; // Vertices Number
    AdjancyList* edgesList;
  public:
    Graph(int n){
      v = n;
      edgeList = new AdjancyList[v]; // Allocate memory for array of adjacency lists

      for(int i = 0; i < n; i ++){
        edgesList[i]->head = nullptr; // Initialize head pointer of each list to nullptr
      }
    }

    void AddEdge(int s, int d, int w){
      // Create a new node for the source vertex and connect it to the destination vertex
      Node* S = new Node;
      S->info = s;
      S->weight = w;
      S->next = edgesList[d]->head; // Connect S to the head of the destination's list
      edgesList[d]->head = S; // Update the head of the destination's list to point to S

      // Create a new node for the destination vertex and connect it to the source vertex
      Node* D = new Node;
      D->info = d;
      D->weight = w;
      D->next = edgesList[s]->head; // Connect D to the head of the source's list
      edgesList[s]->head = D; // Update the head of the source's list to point to D
    }
}
```
# TODO
- Add adjency tutorial
- Add tree tutorial
- Add sort tutorial
- Add merge sort