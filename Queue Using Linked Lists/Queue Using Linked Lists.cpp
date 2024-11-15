#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }
        Node* delPtr = front;
        front = front->next;
        delete delPtr;
        if (front == NULL) {  
            rear = NULL;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return front->data;
        }
        else {
            cout << "Queue is empty" << endl;
            return -1;  
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count() {
        int counter = 0;
        Node* temp = front;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void clear() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;  
        cout << "Queue cleared." << endl;
    }

    int find(int item) {
        int position = 1;
        Node* temp = front;
        while (temp != NULL) {
            if (temp->data == item) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; 
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();
    

    cout << "Front element of the queue: " << myQueue.peek() << endl;
    cout << "Number of elements in the queue: " << myQueue.count() << endl;

    
    int element = 50;
    int position = myQueue.find(element);
    if (position != -1) {
        cout << "Element " << element << " found at position: " << position << endl;
    }
    else {
        cout << "Element " << element << " not found in the queue." << endl;
    }

    
    myQueue.clear();
    myQueue.display();  

    return 0;
}   
