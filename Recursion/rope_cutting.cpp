#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    return ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}

int ropeCut(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(ropeCut(n - a, a, b, c),
                  ropeCut(n - b, a, b, c),
                  ropeCut(n - c, a, b, c));
    if (res == -1)
        return -1;
    else
        return res + 1;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << ropeCut(n, a, b, c) << endl;
    return 0;
}