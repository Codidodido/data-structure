#include <iostream>
using namespace std;

struct Student{
	string name;
	int age;
	int ID;
	float mark;
};

struct Node{
	Student student;
	Node* next;
};

Node* CreateStudent(Student student){
	Node* q = new Node;
	q->student = student;
	q->next = nullptr;
	return q;
}
int main(){
	
	cout << "-> Welcome To Codidodido School <-\n\n" << endl;
	
}