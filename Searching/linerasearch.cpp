#include<iostream>
using namespace std;

int main()
{
    int i=0, flag=0 , count=0;
    int input[10]= {77,98,32,66,66,66,12,15,72,57};
    int tosearch;
    cout << "Enter value to search: ";
    cin>>tosearch;
    for(i ; i<10 ; i++)
    {
        if (input[i] == tosearch)
        {
            flag = 1;
            cout << "Value found at "<<i<<"\n";
            count +=1;
        }
    }
    cout<<"The value is repeated "<<count<<" times \n";
    if (flag == 0)
    {
        cout<<"Value not found";
    }
}
