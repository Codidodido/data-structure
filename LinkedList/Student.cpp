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
	
	ClassList* computer = new ClassList();
	
	cout << "-> Order List: \n-> 1. Add Student\n-> 2. Remove Student\n-> 3. Edit Student Mark\n-> 4. Find Student\n-> 5. Print Student\n-> 6. Class Average\n-> 7. Class Variance\n-> 0. Exit\n";
	int order = -1, data;
	while(order != 0){
		cout << "\n\n-> What to do : ";
		cin >> order;
		
		switch(order){
			
			case 1:{
				cout << "\n-> Enter number of students: ";
				cin >> data;
				for(int i = 0; i < data ; i++){
					Student student;
					cout << "\n\t-> Enter student ID: ";
					cin >> student.ID;
					cout << "\t-> Enter student name: ";
					cin >> student.name;
					cout << "\t-> Enter student age: ";
					cin >> student.age;
					cout << "\t-> Enter student mark: ";
					cin >> student.mark;
					
					Node* newStudent = CreateStudent(student);
					computer->AddStudent(newStudent);
					cout << "\t-> Student Added Successfully!";
				}
				break;
			}
			
			case 2:{
				cout << "\n\t-> Enter student ID: ";
				cin >> data;
				computer->RemoveStudent(data);
				cout << "\t-> Student Removed Successfully!";
				break;
			}
			
			
			case 3:{
				cout << "\n-> Enter student ID: ";
				cin >> data;
				
				int mark;
				cout << "\t-> Enter student mark: ";
				cin >> mark;
				
				Node* student = computer->Find(data);
				student->student.mark = mark;
				cout << "\t-> Student Edited Successfully!";
				break;
			}
			
			case 4:{
				cout << "\n-> Enter student ID: ";
				cin >> data;
				
				Node* student = computer->Find(data);
				computer->PrintStudent(student);
				break;
			}
			
			case 5: {
				computer->Print();
				break;
			}
			
			case 6:{
				float average = computer->GetAverage();
				cout << "\n-> Class Average Mark is : " << average;
				break;
			}
			
			case 7:{
				float variance = computer->GetVariance();
				cout << "\n-> Class Variance Mark is : " << variance;
				break;
			}
			
			case 0: {
				break;
			}
			
			default:
                cout << "Invalid input. Please try again." << endl;
				
		}
		
	}
}