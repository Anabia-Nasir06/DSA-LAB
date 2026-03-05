#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
};
Node * list = NULL;

void insert(int value){
    Node * curr;
    Node * temp;
    temp = (Node *)malloc(sizeof(Node));
    temp -> data = value;
    temp -> next = NULL;
    temp -> prev = curr;
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

int main(){
    cout <<"Select:\n 1. Insert \n 2. Search \n 3. Delete \n 4. Display \n";
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
        // case 2:{
        //     cout<<"Program Exit";
        //     break;
        // }
        default:
            cout<<"Invalid Choice";
            break;
        }
    }
}
