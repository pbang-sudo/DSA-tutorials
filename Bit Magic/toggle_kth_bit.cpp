#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int mask = 1 << (k - 1);
    cout << "Output: " << (mask ^ n) << endl;

    return 0;
}