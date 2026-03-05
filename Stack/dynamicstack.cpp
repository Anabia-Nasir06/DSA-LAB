#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *top = NULL;
void push(int val)
{
    Node *temp = (Node*)malloc(sizeof (Node));
    temp->value = val;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

void display() {
    Node* temp = top;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    push(1);
    push(2);
    push(3);
    display(); 
    pop();
    display();

    return 0;
}