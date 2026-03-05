#include<iostream>
using namespace std;
int main()
{
    int input[10] = {12, 37, 77, 88, 92, 92, 92, 211, 300, 315};
    int l= 0, r=9, count=0, mid; 
    int tosearch;
    cout << "Enter value to search: ";
    cin>>tosearch;
    while(l<=r)
    {
        mid = (l+r)/2;
        if (tosearch == input[mid])
        {
            cout<<"The value "<<tosearch<<" is found at index "<<mid<<"\n";
            count = 1;
            int i = mid-1;
            while(i>=0 && input[i] == tosearch)
            {
                cout<<"The value "<<tosearch<<" is found at index "<<i<<"\n";
                count++;
                i--;
            }
            i = mid+1;
            while(i<10 && input[i] == tosearch)
            {
                cout<<"The value "<<tosearch<<" is found at index "<<i<<"\n";
                count++;
                i++;
            }
           
            
            break;
        }
        if (tosearch > input[mid])
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    if (count>0)
    {
        cout<<"The value "<<tosearch<<" is repeated "<<count<<" times";
    }
    else
    {
        cout<<"Not Found";
    }
}