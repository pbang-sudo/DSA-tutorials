#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[], int n, int k)
{
    // Complete the function
    unordered_map<int, int> m;
    int res = 0, preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == k)
            res = i + 1;
        if (m.find(preSum) == m.end())
            m.insert({preSum, i});
        if (m.find(preSum - k) != m.end())
            res = max(res, i - m[preSum - k]);
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << lenOfLongSubarr(arr, n, k);
    return 0;
}