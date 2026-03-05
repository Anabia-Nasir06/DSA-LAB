#include <iostream>
using namespace std;

int arr[10] = {77, 82, 11, 54, 76, 57, 25, 98, 59, 101};

int SetPivot(int L, int R)
{
    int piv_ind = (L + R) / 2;
    while (L != R)
    {
        while ( R != piv_ind){
        if (arr[piv_ind] > arr[R])
        {
            swap(arr[piv_ind], arr[R]);
            piv_ind = R;
        }
        else R--;
    }

        while ( L != piv_ind){  
        if (arr[piv_ind] < arr[L])
        {
            swap(arr[piv_ind], arr[L]);
            piv_ind = L;
        }
        else L++;
    }
    }
    return piv_ind;
}

void QuickSort(int L, int R)
{
    if (L < R)
    {
        int piv_ind = SetPivot(L, R);
        QuickSort(L, piv_ind - 1);
        QuickSort(piv_ind + 1, R);
    }
}

int main()
{
    QuickSort(0, 9);

    cout << "Sorted Array:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
