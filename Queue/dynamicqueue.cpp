#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontNode = NULL;
Node* rearNode  = NULL;

// Enqueue (Insert)
void enqueue(int value)
{
    Node* temp = new Node;   
    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if (frontNode == NULL) {
        frontNode = temp;
        rearNode = temp;
    }
    else {
        rearNode->next = temp;
        rearNode = temp;
    }
}

// Dequeue (Remove)
void dequeue()
{
    if (frontNode == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = frontNode;
    cout << "Removed: " << temp->data << endl;
    frontNode = frontNode->next;

    if (frontNode == NULL) {
        rearNode = NULL;
    }
    delete temp;
}

// Display Queue
void display()
{
    if (frontNode == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node* temp = frontNode;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    enqueue(10);
    enqueue(23);
    enqueue(44);
    display();

    dequeue();
    display();

    return 0;
}