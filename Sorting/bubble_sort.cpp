#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 2, 9, 1, 3};
    int n = 5;
    for (int i = 0; i < n - 1; i++) // passes
    {
        for (int j = 0; j < n - 1 - i; j++) // comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); // swap elements
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}