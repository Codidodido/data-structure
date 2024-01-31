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

class ClassList{
	private:
		Node* head;
	public:
		ClassList(){
			head = nullptr;
		}
		
		void AddStudent(Node* student){
			if(head == nullptr){
				head = student;
				return;
			}
			
			Node* q = student;
			
			Node* tmp = head;
			
			while(tmp->next != nullptr){
				tmp = tmp->next;
			}
			
			tmp->next = q;
		}
		
		Node* Find(int ID){
			Node* tmp = head;
			
			while(tmp != nullptr && tmp->student.ID != ID){
				tmp = tmp->next;
			}
			
			return tmp;
		}

		
		void RemoveStudent(int ID) {
		    Node* tmp = head;
		    Node* prev = nullptr;
		
		    if (tmp != nullptr && tmp->student.ID == ID) {
		        head = tmp->next;
		        delete tmp;
		        return;
		    }
		
		    while (tmp != nullptr && tmp->student.ID != ID) {
		        prev = tmp;
		        tmp = tmp->next;
		    }
		
		    if (tmp == nullptr) {
		        cout << "Invalid ID" << endl;
		        return;
		    }
		    
		    prev->next = tmp->next;
		
		    delete tmp;
		}
		
		float GetAverage(){
			float average = 0;
			int count = 0;
			Node* tmp = head;
			
			while(tmp){
				average += tmp->student.mark;
				count++;
				tmp = tmp->next;
			}
			
			if (count == 0) {
            	return 0;
        	}	
			
			average = average / count;
			return average;
		}
		
		float GetVariance(){
			float variance = 0;
			int count = 0;
			float average = GetAverage();
			
			Node* tmp = head;
			
			while(tmp){
				variance += (tmp->student.mark-average)*(tmp->student.mark-average);
				count++;
				tmp = tmp->next;
			}
			
			if (count == 0) {
            	return 0;
        	}	
			
			variance = variance / count;
			return variance;
		}
		
		void PrintStudent(Node* student){
			cout << "---\n" << 
			"-> ID: "<<student->student.ID<< "\n"
			"-> Name: "<<student->student.name << "\n"
			"-> Age: "<<student->student.age << "\n"
			"-> Mark: " << student->student.mark << endl;
		}
		
		void Print(){
			Node* tmp = head;
			while(tmp){
				PrintStudent(tmp);
				tmp = tmp->next;
			}
		}
};

int main(){
	
	cout << "-> Welcome To Codidodido School <-\n\n" << endl;
	
}