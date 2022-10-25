#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i, res = 0, value;
    for(i = 0; i < n; i++) {
        cin >> value;
        res ^= value;
    }

    cout << res << value;

    return 0;
}