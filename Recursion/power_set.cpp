#include <iostream>
#include <cstring>

using namespace std;

void powerSet(string str, int index = 0, string currentString = "")
{
    int n = str.length();
    if (n == index)
    {
        cout << currentString << endl;
        return;
    }

    powerSet(str, index + 1, currentString + str[index]);
    powerSet(str, index + 1, currentString);
}

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    powerSet(str);
    return 0;
}