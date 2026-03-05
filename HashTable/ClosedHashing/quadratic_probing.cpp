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

// insert using quadratic probing
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int pos = (index + i*i) % SIZE;

        if (table[pos] == -1) {
            table[pos] = key;
            cout << key << " inserted at index " << pos << endl;
            return;
        }

        i++;
    }

    cout << "Table is full\n";
}

// search element
void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE) {
        int pos = (index + i*i) % SIZE;

        if (table[pos] == key) {
            cout << key << " found at index " << pos << endl;
            return;
        }

        if (table[pos] == -1)
            break;

        i++;
    }

    cout << key << " not found\n";
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