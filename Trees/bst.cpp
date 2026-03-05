#include<iostream>
using namespace std;

struct Node{
    int data; 
    Node* right;
    Node* left;
};
Node* Root = NULL;


Node* insert(Node* cur, int value){
    if (cur == NULL){
        Node* temp = new Node;
        temp -> data = value;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }
    if (value > cur ->data)
        cur -> right = insert(cur -> right, value);
    else
        cur -> left = insert(cur -> left, value);
    return cur;
}


void search(Node* cur, int value){
    if (cur == NULL){
        cout << "Value not found";
        return;
    }
    if (cur->data == value){
        cout << "Value " << value << " found";
        return;
    }
    if (value < cur->data)
        search(cur->left, value);
    else
        search(cur->right, value);
}

void PreOrder(Node* cur){
    if (cur != NULL){
        cout<< cur->data <<" ";
        PreOrder(cur -> left);
        PreOrder(cur -> right);
    }
}

void PostOrder(Node* cur){
    if (cur != NULL){
        PostOrder(cur -> left);
        PostOrder(cur -> right);
        cout<< cur->data <<" ";
    }
}
void InOrder(Node* cur){
    if (cur != NULL){
        InOrder(cur -> left);
        cout<< cur->data <<" ";
        InOrder(cur -> right);
    }
}

Node* Del(Node* cur, int value){
    if(cur == NULL){
        cout<<"Value not Found.";
        return NULL;
    }
    if(cur -> data == value){
        //  no child 
        if(cur->left == NULL && cur->right == NULL){
            delete cur;
            return NULL;

        }
        //  one child on right
        if(cur->left == NULL && cur->right != NULL){
            Node* temp = cur->right;
            delete cur;
            return temp;
        }
        //  one child on left
        if(cur->left != NULL && cur->right == NULL){
            Node* temp = cur->left;
            delete cur;
            return temp;
        }
        // two child
        if(cur->left != NULL && cur->right != NULL){
            Node* temp = cur->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            cur->data = temp->data;
            cur->right = Del(cur->right , temp->data);
            return cur;
        }
    }
    if (value < cur->data)
       cur->left =  Del(cur->left, value);
    else
       cur->right = Del(cur->right, value);
    cout<<"Value Deleted";
    return cur;


}

int main(){
    cout <<"Select:\n 1. Insert \n 2. Pre-Order \n 3. Post-Order \n 4. In-Order \n 5. Search \n 6. Delete \n 7. To Exit\n";
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
                Root = insert (Root, value);
            }
            break;}
        case 2:
            {
            cout << "PostOrder: ";
            PostOrder(Root);
            break;}
        case 3:{
            cout << "PreOrder: ";
            PostOrder(Root);
            break;}
        case 4:{
            cout << "InOrder: ";
            InOrder(Root);
            break;}
        case 5:{
            cout << "Enter Value to Search: ";
            int value;
            cin>>value;
            search(Root, value);
            break;}
        case 6:{
            cout << "Enter Value to Delete: ";
            int value;
            cin>>value;
            Root = Del(Root, value);
            break;}
        case 7:
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