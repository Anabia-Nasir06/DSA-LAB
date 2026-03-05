#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};
    int n = 5;

    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}