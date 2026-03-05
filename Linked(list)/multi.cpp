#include <iostream>
#include <cstdlib>
using namespace std;

struct SNode {
    int SNo;
    SNode* SNext;
};

struct CNode {
    int CNo;
    CNode* CNext;
    SNode* SList;   
};

CNode* CList = NULL;

/* Add Course */
void add_course(int CNo) {
    CNode* temp = (CNode*)malloc(sizeof(CNode));
    temp->CNo = CNo;
    temp->CNext = NULL;
    temp->SList = NULL;

    if (CList == NULL) {
        CList = temp;
    } else {
        CNode* Ccur = CList;
        while (Ccur->CNext != NULL)
            Ccur = Ccur->CNext;

        Ccur->CNext = temp;
    }
}

/* Add Student to Course */
void add_stu(int SNo, int CNo) {
    CNode* Ccur = CList;

    while (Ccur != NULL) {
        if (Ccur->CNo == CNo) {

            SNode* temp = (SNode*)malloc(sizeof(SNode));
            temp->SNo = SNo;
            temp->SNext = NULL;

            if (Ccur->SList == NULL) {
                Ccur->SList = temp;
            } else {
                SNode* Scur = Ccur->SList;
                while (Scur->SNext != NULL)
                    Scur = Scur->SNext;

                Scur->SNext = temp;
            }

            cout << "Student added successfully\n";
            return;
        }
        Ccur = Ccur->CNext;
    }

    cout << "Course does not exist\n";
}

/* Display All Courses and Students */
void display() {
    if (CList == NULL) {
        cout << "No courses available\n";
        return;
    }

    CNode* Ccur = CList;
    while (Ccur != NULL) {
        cout << "Course No: " << Ccur->CNo << endl;

        SNode* Scur = Ccur->SList;
        if (Scur == NULL) {
            cout << "  No students enrolled\n";
        } else {
            cout << "  Students: ";
            while (Scur != NULL) {
                cout << Scur->SNo << " ";
                Scur = Scur->SNext;
            }
            cout << endl;
        }
        Ccur = Ccur->CNext;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nSelect:\n";
        cout << "1. Add Course\n";
        cout << "2. Add Student to Course\n";
        cout << "3. Delete (Under Construction)\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "How many courses? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    int c;
                    cout << "Enter course number: ";
                    cin >> c;
                    add_course(c);
                }
                break;
            }

            case 2: {
                int seatno, courseno;
                cout << "Enter student seat number: ";
                cin >> seatno;
                cout << "Enter course number: ";
                cin >> courseno;
                add_stu(seatno, courseno);
                break;
            }

            case 3:
                cout << "Delete: Under Construction\n";
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
