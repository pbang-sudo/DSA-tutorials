#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        a[i] = sum;
    }
    int T, left, right;
    cout << "Number of queries: " << endl;
    cin >> T;
    while (T--)
    {
        cin >> left >> right;
        cout << a[right] - a[left] + arr[left] << endl;
    }
    return 0;
}