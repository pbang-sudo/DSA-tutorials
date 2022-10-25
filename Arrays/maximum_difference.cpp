#include <iostream>
using namespace std;

int max_diff(int *arr, int n)
{
    int minimum = arr[0];
    int res = arr[1] - arr[0];
    for (int i = 0; i < n; i++)
    {
        res = max(res, arr[i] - minimum);
        minimum = min(minimum, arr[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Maximum Difference: " << max_diff(arr, n) << endl;
    return 0;
}