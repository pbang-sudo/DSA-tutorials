// Given two binary arrays arr1[] and arr2[] of same size N. 
// Find length of the longest common span [i, j] where j>=i such that 
// arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j]. 

 
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

int longestCommonSum(bool arr1[], bool arr2[], int n)
{
    // code here
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        int a = (arr1[i]) ? 1 : 0;
        int b = (arr2[i]) ? 1 : 0;
        temp[i] = a - b;
    }
    return lenOfLongSubarr(temp, n, 0);
}

int main()
{
    int n;
    cin >> n;
    bool arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr2[n];
    cout << longestCommonSum(arr1, arr2, n);
    return 0;
}