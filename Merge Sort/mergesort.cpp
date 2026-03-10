#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int temp[100]; // temporary array

    int i = left;    // left part start
    int j = mid + 1; // right part start
    int k = left;    // temp index

    // compare both parts
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // remaining left elements
    while (i <= mid)
        temp[k++] = arr[i++];

    // remaining right elements
    while (j <= right)
        temp[k++] = arr[j++];

    // copy back to original array
    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);      // left half
    mergeSort(arr, mid + 1, right); // right half
    merge(arr, left, mid, right);   // merge them
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}