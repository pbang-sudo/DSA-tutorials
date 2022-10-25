#include <iostream>
using namespace std;

int countMaxOne(int *arr, int n)
{
    int count = 0, currentCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            count++;
        else
        {
            currentCount = max(count, currentCount);
            count = 0;
        }
    }
    return currentCount;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countMaxOne(arr, n) << endl;
    return 0;
}