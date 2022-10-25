#include <iostream>
using namespace std;

int count_set_bits(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << count_set_bits(n) << endl;

    return 0;
}