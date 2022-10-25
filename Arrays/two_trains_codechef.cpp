#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int T, car;
    cin >> T;

    while (T--)
    {
        int sum = 0, diff, i;
        cin >> car;
        int *a = new int[car];
        int *b = new int[car];
        a[0] = 0;
        b[0] = 0;
        for (i = 1; i < car; i++)
        {
            cin >> a[i];
            sum += a[i];
            b[i] = a[i];
            a[i] = sum;
        }

        for (i = 0; i < car - 1; i++)
        {
            diff = a[i + 1] - b[i];
            b[i + 1] = (diff > 0) ? (b[i] + diff + b[i + 1]) : (b[i] + b[i + 1]);
        }
        cout << b[i] << endl;
    }
    return 0;
}
