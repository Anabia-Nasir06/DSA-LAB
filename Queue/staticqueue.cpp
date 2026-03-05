#include <iostream>
using namespace std;

int queueArr[5];     
int front = 0;
int rear = 0;

// Add element to queue
void enqueue(int value) {
    if (rear == 5) {
        cout << "Queue is Full!" << endl;
        return;
    }
    queueArr[rear] = value;
    rear++;
}

// Remove element from queue
void dequeue() {
    if (front == rear) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Removed: " << queueArr[front] << endl;
    front++;
}

// Display queue
void display() {
    if (front == rear) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i < rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);   // This will show Queue is Full
    display();

    return 0;
}