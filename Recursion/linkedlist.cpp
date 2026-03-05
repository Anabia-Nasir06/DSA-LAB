#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Print forward: head → tail
void printForward(Node* head) {
    if (head == nullptr) return;     // base case
    cout << head->data << " ";       // process node
    printForward(head->next);        // recursive call
}

// Print backward: tail → head
void printBackward(Node* head) {
    if (head == nullptr) return;     // base case
    printBackward(head->next);       // recursive call first
    cout << head->data << " ";       // print on return
}

int main() {
    // Creating a simple linked list: 1 → 2 → 3 → 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Forward: ";
    printForward(head);

    cout << "\nBackward: ";
    printBackward(head);

    return 0;
}
