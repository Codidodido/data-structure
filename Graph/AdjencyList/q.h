#include <iostream>
#include "node.h"
using namespace std;

class Q {
private:
    Node* queue;

public:
    Q() : queue(nullptr) {}

    void Push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (queue == nullptr) {
            queue = newNode;
        } else {
            Node* temp = queue;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int Pop() {
        if (queue != nullptr) {
            Node* temp = queue;
            queue = queue->next;
            return temp->data;
            delete temp;
        } else {
            cout << "Queue is empty. Cannot pop.\n";
            return -1;
        }
    }

    bool IsEmpty() {
        return queue == nullptr;
    }

    int Front() {
        if (queue != nullptr) {
            return queue->data;
        } else {
            cout << "Queue is empty. No front element.\n";
            return -1;
        }
    }

    void Display() {
        Node* temp = queue;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};