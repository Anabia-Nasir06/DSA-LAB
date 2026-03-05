#include <iostream>
using namespace std;

const int MAX = 5;      // Size of queue

int queueArr[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
bool isEmpty() {
    return front == -1;
}

// Check if queue is full
bool isFull() {
    return (rear + 1) % MAX == front;
}

// Insert element
void enqueue(int value)
{
    if (isFull()) {
        cout << "Queue is Full!" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }
    queueArr[rear] = value;
}

// Remove element
void dequeue()
{
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Removed: " << queueArr[front] << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display()
{
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue: ";

    int i = front;
    while (true)
    {
        cout << queueArr[i] << " ";
        if (i == rear)
            break;

        i = (i + 1) % MAX;
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
    enqueue(60);
    display();

    enqueue(70);   // Will show full

    return 0;
}