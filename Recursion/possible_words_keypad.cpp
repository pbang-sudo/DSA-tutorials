#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printAllPossibleWords(string input, string result, string keypad[]) {
    if (input.length() == 0) {
        cout << result << endl;
        return;
    }

    char ch = input[0];
    string code = keypad[ch - '0'];
    string remaining = input.substr(1);

    for (int i = 0; i < code.length(); i++)
        printAllPossibleWords(remaining, result + code[i], keypad);
}

int main()
{
    string keypad[] =
    {
        {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
    };
    string input;
    cout << "Enter number: ";
    cin >> input;
    printAllPossibleWords("444", "", keypad);
    return 0;
}