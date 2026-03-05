#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node * next;
};
Node * list = NULL;

void insert(int value){
    Node * temp;
    temp = (Node *)malloc(sizeof(Node));
    temp -> data = value;
    temp -> next = NULL;
    if (list == NULL){
        list = temp;
    }
    else{
        Node * curr = list;
        while(curr->next != NULL){
            curr = curr -> next;
        }
        curr -> next = temp;
    }
}

void search(int value){
    Node * cur =list;
    int pos =1;
    while (cur != NULL){
        if (cur->data == value){
            cout<<"Value "<<value<<" found at position "<<pos<< endl;
            return;
        }
        cur = cur->next;
        pos++;
    }
}

void Delete(int value){
    if (list == NULL){
        cout<<"The list is empty";
        return;
    }
    Node * cur = list;
    if (value == list->data){
        list = list->next;
        free(cur);
        return;
    }
    cur = list->next;
    Node * prev = list;
    while(cur != NULL){
        if (value == cur->data){
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout<<"Value not found";
}

void display() {
    if (list == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* curr = list;
    cout << "Linked List: ";
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main(){
    cout <<"Select:\n 1. Insert \n 2. Search \n 3. Delete \n 4. Display \n 5. To Exit";
    int choice;
    while(true){
        cin>>choice;
        switch(choice){
        case 1:{
            int n;
            cout <<"How many values to be entered? ";
            cin>>n;
            for(int i = 1; i <= n;i++){
                cout << "Enter Value: ";
                int value;
                cin>>value;
                insert(value);
            }
            break;}
        case 2:
            {int val;
            cout<<"Enter the value to search: ";
            cin>>val;
            search(val);
            break;}
        case 3:{
            int val;
            cout<<"Enter the value to search: ";
            cin>>val;
            Delete(val);
            break;}
        case 4:{
            display();
            break;}
        case 5:
        {
            cout<< "Program ended";
            break;
        }
        default:
            cout<<"Invalid Choice";
            break;
        }
    }
}








