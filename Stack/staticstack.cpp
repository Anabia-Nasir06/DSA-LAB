#include <iostream>
using namespace std;

int Stack[10];
int Top = 0;

void push(int value){
    if(Top == 10)
    {
        cout<<"Stack Overflow";
        return;
    }
    Stack[Top] = value;
    Top++;
}

int pop(){
    if (Top == 0){
        cout<<"Stack Underflow";
        return -1;
    }
    Top--;
    return Stack[Top];
}

void display(){
    if(Top == 0){
        cout<<"Stack is Empty";
        return;
    }
    cout<<"Stack elements:";
    for(int i = 0; i<Top; i++){
        cout<<Stack[i] << " ";
    }
    cout<<endl;
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