#include <bits/stdc++.h>
using namespace std;
void frequencyCount(int *arr, int n)
{
    int i = 1, freq = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            i++;
            freq++;
        }
        cout << arr[i - 1] << " " << freq << endl;
        i++;
        freq = 1;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2])
        cout << arr[n - 1] << " 1\n";
}

int main()
{
    int n, i;
    cin >> n;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    frequencyCount(arr, n);
    return 0;
}