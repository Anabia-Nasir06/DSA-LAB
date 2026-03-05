#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {12, 11, 13, 5, 6};
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int hold = arr[i];
        int gap = i;
        while (gap > 0 && arr[gap - 1] > hold)
        {
            arr[gap] = arr[gap - 1];
            gap--;
        }
        arr[gap] = hold;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}