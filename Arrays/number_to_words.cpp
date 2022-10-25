#include <iostream>
using namespace std;

string one[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ",
                "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
string ten[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

string numToWords(int n, string s)
{
    string str = "";
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];
    if (n)
        str += s;

    return str;
}

string numberToWords(long n) {
    string out;
    out += numToWords((n / 10000000), "Crore ");
    out += numToWords((n / 100000) % 100, "Lakh ");
    out += numToWords((n / 1000) % 100, "Thousand ");
    out += numToWords((n / 100) % 10, "Hundred ");
    out += numToWords((n % 100), "");

    if(out == "")
    return "Zero";

    return out;
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << numberToWords(n) << endl;
    return 0;
}