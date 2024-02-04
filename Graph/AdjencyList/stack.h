#include <iostream>
#include "node.h"
using namespace std;

class Stack {
private:
    Node* stack;

public:
    Stack() : stack(nullptr) {}

    void Push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = stack;
        stack = newNode;
    }

    int Pop() {
        if (stack != nullptr) {
            Node* temp = stack;
            int poppedData = temp->data;
            stack = stack->next;
            delete temp;
            return poppedData;
        } else {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
    }

    bool IsEmpty() {
        return stack == nullptr;
    }

    int Top() {
        if (stack != nullptr) {
            return stack->data;
        } else {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
    }

    void Display() {
        Node* temp = stack;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
