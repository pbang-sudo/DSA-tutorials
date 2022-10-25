#include <bits/stdc++.h>
using namespace std;

bool findSubarray(int *arr, int n, int sum)
{
    int currSum = arr[0], start = 0;
    for (int end = 1; end < n; end++)
    {
        // Clean the previous window
        while (currSum > sum && start < end - 1)
        {
            currSum -= arr[start];
            start++;
        }
        if (currSum == sum)
            return true;
        if (end < n)
            currSum += arr[end];
    }
    return (currSum == sum);
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;
    if (findSubarray(arr, n, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}