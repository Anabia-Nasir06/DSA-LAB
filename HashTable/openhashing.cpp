#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node HT[10];
int size = 10;


void insert(int value){
    int index = value % size;

    if (HT[index].data == -1){
        HT[index].data = value;
    }
    else{
        Node * temp = new Node;
        temp -> data = value;
        temp -> next = NULL;

        Node* cur = &HT[index];

        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
}


void search(int value){
    int index = value % size;
    Node* cur = &HT[index];   // Take address

    while (cur != NULL) {
        if (cur->data == value) {
            cout << "Value " << value << " found at index " << index << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Value " << value << " not found\n";
}




int main(){
    for(int i=0; i<size; i++){
        HT[i].data = -1;
        HT[i].next = NULL;
    }
    insert(10);
    insert(33);
    insert(22);
    insert(63);
    insert(66);
    insert(43);
    insert(6);
    cout<<"Insertion Done"<<endl;
    cout<<"Searching......"<<endl;
    search(6);
    

}
