#include<iostream>
using namespace std;
struct CNode{
    int CNo;
    CNode * CNext;
    SNode * SList;
};
CNode * CList = NULL;

struct SNode{
    int SNo;
    SNode * SNext;
};

void add_course(int CNo){
    CNode * temp;
    temp = (CNode *)malloc(sizeof(CNode));
    temp -> CNo = CNo;
    temp -> CNext = NULL;
    temp -> SList = NULL;
    if (CList == NULL){
        CList = temp;
    }
    else{
        CNode * Ccur = CList;
        while(Ccur->CNext != NULL){
            Ccur = Ccur -> CNext;
        }
        Ccur -> CNext = temp;
    }
}

void add_stu(int SNo, int CNo) {
    CNode* Ccur = CList;

    while (Ccur != NULL) {
        if (CNo == Ccur->CNo) {

            SNode* temp = (SNode*)malloc(sizeof(SNode));
            temp->SNo = SNo;
            temp->SNext = NULL;

            if (Ccur->SList == NULL) {
                Ccur->SList = temp;
            } 
            else {
                SNode* Scur = Ccur->SList;
                while (Scur->SNext != NULL)
                    Scur = Scur->SNext;

                Scur->SNext = temp;
            }

            return;  
        }

        Ccur = Ccur->CNext;
    }

    // course not found
    cout << "The course does not exist\n";
}


int main(){
    cout <<"Select:\n 1. To Add A Course \n 2. To Add A Student In A Course \n 3. Delete \n 4. Display All\n 5. To Exit\n";
    int choice;
    while(true){
        cin>>choice;
        switch(choice){
        case 1:{
            int n;
            cout <<"How many courses to be entered? ";
            cin>>n;
            for(int i = 1; i <= n;i++){
                cout << "Enter Course no: ";
                int value;
                cin>>value;
                add_course(value);
            }
            break;}
        case 2:
            {int seatno, courseno;
            cout<<"Enter the seat number of the student: ";
            cin>>seatno;
            cout<<"Enter the course number: ";
            cin>>courseno;
            // add_stu(seatno,courseno);
            break;}
            case 3:
                cout << "Delete: Under Construction\n";
                break;

            case 4:
                // display();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
