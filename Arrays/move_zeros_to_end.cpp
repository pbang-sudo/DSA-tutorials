#include <iostream>
using namespace std;

void swap(int *, int*);
void printArray(int arr[], int n);
void moveAllZeroes(int arr[], int n);


int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    moveAllZeroes(arr, n);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
}

void moveAllZeroes(int *arr, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(&arr[i], &arr[count]);
            count++;
        }
    }
    printArray(arr, n);
}