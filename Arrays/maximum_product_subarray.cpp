/*
    Complete Solution:
1. We will keep 2 variables, one that will store maximum positive value - MAXI and one with minimum negative value - MINI.
2. We will keep sure that MAXI, is always greater than equal to 1 and MINI is always less than equal to 1
3. Now there are 3 cases:
    if arr[i] > 0, then MAXI is MAXI*arr[i], and MINI is min(MIN*arr[i], 1)
    if arr[i] == 0, then we need to see for another subarray, and make MAXI = MINI = 1
    if arr[i]<0, then MAXI becomes max(MINI*arr[i],1) and MINI becomes MAXI* arr[i]
4. For every iteration MAXI stores the maximum value so far, so keep another variable OVERALLMAX to store max of all MAXIs.
    Print OVERALLMAX
*/

#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n)
{
    // code here
    // long long maxi = 1, mini = 1, omax;
    // for(int i = 0; i < n; i++) {
    //     if(arr[i] > 0) {
    //         maxi *= arr[i];
    //         mini = min(mini * (long long)arr[i], 1);
    //     }
    //     else if(arr[i] == 0) {
    //         maxi = 1;
    //         mini = 1;
    //     }
    //     else {
    //         maxi = max(mini * arr[i], 1);
    //         mini = maxi * arr[i];
    //     }
    //     omax = max(maxi, omax);
    // }
    // return omax;
    long long maxi = arr[0], mini = arr[0], maxpr = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxi, mini);
        long long num = (long long)arr[i];
        maxi = max(num, maxi * num);
        mini = min(num, num * mini);
        maxpr = max(maxpr, maxi);
    }
    return maxpr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n) << endl;
    return 0;
}