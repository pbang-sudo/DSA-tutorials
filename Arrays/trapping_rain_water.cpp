#include <iostream>
using namespace std;

// Naive Solution
/* int getMaxWaterUnits(int *arr, int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
            lmax = max(lmax, arr[j]);
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++)
            rmax = max(rmax, arr[j]);

        res += (min(lmax, rmax) - arr[i]);
    }
    return res;
} */

// Efficient Solution : precompute lmax and rmax
int getMaxWaterUnits(int *arr, int n)
{
    int res = 0;
    int *lmax = new int[n];
    int *rmax = new int[n];
    lmax[0] = arr[0];
    rmax[n - 1] = arr[n - 1];
    
    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i], arr[i - 1]);
    for (int i = n - 2; i > -1; i--)
        rmax[i] = max(arr[i], arr[i + 1]);

    for (int i = 1; i < n - 1; i++)
        res += (min(lmax[i], rmax[i]) - arr[i]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << getMaxWaterUnits(arr, n) << endl;
    return 0;
}