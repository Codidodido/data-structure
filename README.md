# Data Structure
Learning data structure together 

# Contens
- Linked List
- Graph
- Sort
- Tree

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

