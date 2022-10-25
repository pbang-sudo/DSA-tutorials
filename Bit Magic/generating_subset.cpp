#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i, j;
    int size = pow(2, n);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i & (1 << j) != 0)
                cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}