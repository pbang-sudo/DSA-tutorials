#include <iostream>
using namespace std;

void discPlacement(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move Disc 1 from " << a << " to " << c << endl;
        return;
    }

    discPlacement(n - 1, a, c, b);
    cout << "Move Disc " << n << " from " << a << " to " << c << endl;
    discPlacement(n - 1, b, a, c);
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    discPlacement(n, a, b, c);
    return 0;
}