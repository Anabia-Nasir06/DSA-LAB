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
int hashFunction(int key) {
    return key % SIZE;
}

// insert value
void insert(int key) {
    int index = hashFunction(key);

    while (table[index] != -1) {
        index = (index + 1) % SIZE;   // move to next position
    }

    table[index] = key;
    cout << key << " inserted at index " << index << endl;
}

// search value
void search(int key) {
    int index = hashFunction(key);
    int count = 0;

    while (table[index] != -1 && count < SIZE) {

        if (table[index] == key) {
            cout << key << " found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;
        count++;
    }

    cout << key << " not found" << endl;
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