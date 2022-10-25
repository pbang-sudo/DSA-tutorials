#include <iostream>
using namespace std;

void arrayReverse(int *, int);
void swap(int *, int *);

int main()
{
    int n, i;
    cin >> n;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    arrayReverse(arr, n);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}

void arrayReverse(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}