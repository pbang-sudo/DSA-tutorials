#include <iostream>
using namespace std;

int digitSum(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10) + digitSum(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << digitSum(n) << endl;

    return 0;
}