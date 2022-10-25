#include <bits/stdc++.h>
using namespace std;

void generateNBonacci(int n, int m)
{
    int sum = 1;
    int *arr = new int[m];
    memset(arr, 0, sizeof(arr));
    arr[n - 1] = 1;
    arr[n] = 1;
    for (int i = n + 1; i < m; i++)
    {
        arr[i] = (2 * arr[i - 1] - arr[i - n - 1]);

    }

    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    generateNBonacci(n, m);
    return 0;
}