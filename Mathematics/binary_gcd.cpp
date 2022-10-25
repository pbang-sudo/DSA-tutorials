#include <iostream>
#define countTrailingZero(x) __builtin_ctz(x)
using namespace std;

void swapping(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a, int b)
{
    if (!a | !b)
        return a | b;
    unsigned shift = countTrailingZero(a | b);
    a >>= countTrailingZero(a);
    do
    {
        b >>= countTrailingZero(b);
        if (a > b)
            swapping(&a, &b);
        b -= a;
    } while (b);
    return a << shift;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "GCD: " << gcd(a, b) << endl;

    return 0;
}