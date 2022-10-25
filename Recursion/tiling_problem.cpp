/*
    Place 2 x 1 tile into a 2 x n board. Count the number of ways the tile can be placed.
*/

#include <iostream>
using namespace std;

int countWays(int n)
{
    if (n == 1 || n == 0)
        return n;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}