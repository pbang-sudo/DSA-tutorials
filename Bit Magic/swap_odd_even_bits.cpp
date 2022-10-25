#include <iostream>
using namespace std;

void swap_odd_even(unsigned int n)
{
    unsigned int even = n & (0xAAAAAAAA);
    unsigned int odd = n & (0x55555555);

    even = even >> 1;
    odd = odd << 1;
    n = even | odd;
    cout << "Output: " << n << endl;
}

int main()
{
    unsigned int n;
    cout << "Enter number: ";
    cin >> n;

    swap_odd_even(n);

    return 0;
}