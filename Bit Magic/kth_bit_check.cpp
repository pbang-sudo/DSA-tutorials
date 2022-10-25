#include <iostream>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    int mask = 1 << (k - 1);
    if(mask & n)
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
    return 0;
}