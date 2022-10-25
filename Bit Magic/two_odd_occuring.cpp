#include <iostream>
using namespace std;

void oddAppearing(int arr[], int n)
{
    int xor = 0, res1 = 0, res2 = 0, i;
    for (i = 0; i < n; i++)
        xor ^= arr[i];

    int sn = xor&~(xor-1); // rightmost set bit
    for (i = 0; i < n; i++)
    {
        if (arr[i] & sn)
            res1 = res1 ^ arr[i];
        else
            res2 = res2 ^ arr[i];
    }

    cout << res1 << " " << res2 << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (auto &x : arr)
        cin >> x;

    oddAppearing(arr, n);
    return 0;
}