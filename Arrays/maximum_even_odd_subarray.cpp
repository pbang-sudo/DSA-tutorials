#include <iostream>
using namespace std;

int getMaximumLength(int *arr, int n)
{
    int count = 1, currCount = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (((arr[i] % 2 == 0) && (arr[i + 1] % 2 != 0)) || ((arr[i] % 2 != 0) && (arr[i + 1] % 2 == 0)))
        {
            count++;
            currCount = max(count, currCount);
        }
        else
        {
            count = 0;
        }
    }

    return currCount;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << getMaximumLength(arr, n) << endl;
    return 0;
}