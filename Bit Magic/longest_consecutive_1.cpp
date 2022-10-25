#include <iostream>
#include <algorithm>
using namespace std;

int countLongestOnes(int n)
{
    int count = 0, currentCount = 0;
    while (n > 0)
    {
        if (n & 1 != 0)
        {
            count = count + 1;
            currentCount = max(currentCount, count);
        }
        else
            count = 0;
        n = n >> 1;
    }
    return currentCount;
}
/*
    another method
    int countLongestOnes(int n) {
        int count = 0;
        while(n > 0) {
            n = n & (n << 1);
            count++;
        }
        return count;
    }
*/

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Result: " << countLongestOnes(n) << endl;

    return 0;
}