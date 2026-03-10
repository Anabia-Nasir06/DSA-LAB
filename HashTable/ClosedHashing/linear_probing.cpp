#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// hash function
int hashFunction(int value) {
    return value % SIZE;
}

// insert value
void insert(int value) {
    int index = hashFunction(value);
    while (table[index] != -1) {
        index = (index + 1) % SIZE;   // move to next position
    }
    table[index] = value;
    cout << value << " inserted at index " << index << endl;
}

// search value
void search(int value) {
    int index = hashFunction(value);
    int count = 0;

    while (table[index] != -1 && count < SIZE) {

        if (table[index] == value) {
            cout << value << " found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;
        count++;
    }

    cout << value << " not found" << endl;
}

// display table
void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            cout << i << " : empty\n";
        else
            cout << i << " : " << table[i] << endl;
    }
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    search(20);
    search(50);

    return 0;
}