#include <bits/stdc++.h>
using namespace std;

int maxSumK(int *arr, int n, int k)
{
    int sum = 0, currSum = 0;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }

    for (int i = k; i < n; i++)
    {
        currSum += (arr[i] - arr[i - k]);
        sum = max(sum, currSum);
    }
    return sum;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    cout << maxSumK(arr, n, k) << endl;
    return 0;
}