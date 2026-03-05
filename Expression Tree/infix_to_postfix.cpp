#include <iostream>
#include <cctype>
using namespace std;

int Stack[10];
int Top = 0;

// push
void push(char value){
    if(Top == 10){
        cout<<"Stack Overflow";
        return;
    }
    Stack[Top] = value;
    Top++;
}

// pop
char pop(){
    if (Top == 0){
        cout<<"Stack Underflow";
        return -1;
    }
    Top--;
    return Stack[Top];
}

bool isEmpty(){
    return Top == 0;
}

// precedence using switch
int precedence(char op)
{
    switch(op)
    {
        case '*':
        case '/':
        case '%':
            return 6;

        case '+':
        case '-':
            return 5;

        case '<':
        case '>':
            return 4;

        case '!':
        case '=':
            return 3;

        case '&':
            return 2;

        case '|':
            return 1;

        default:
            return 0;
    }
}

// function for conversion
string infixToPostfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && Stack[Top-1] != '(')
            {
                postfix += pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(Stack[Top-1]) >= precedence(ch))
            {
                postfix += pop();
            }
            push(ch);
        }
    }
    while (!isEmpty())
    {
        postfix += pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix;
}