#include <bits/stdc++.h>
using namespace std;

int findMajority(vector<int> &arr, int n)
{
    int length = *max_element(arr.begin(), arr.end());
    int *freq = new int[length];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < length; i++)
    {
        if (freq[i] % 2 == 0)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    cout << findMajority(arr, n) << endl;
    return 0;
}