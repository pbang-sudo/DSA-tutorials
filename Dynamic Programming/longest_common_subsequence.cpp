#include <bits/stdc++.h>
#define MAX 100
using namespace std;

string printLCS(vector<vector<int>>, string, string);

// Naive
/*int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m] == y[n])
        return 1 + lcs(x, y, m - 1, n - 1);
    else
        return max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}*/

// Memoization
/*int lcs(string x, string y, int m, int n, vector<vector<int>> &dp) {
    if (m < 0 || n < 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    if (x[m] == y[n])
        return dp[m][n] =  1 + lcs(x, y, m - 1, n - 1, dp);
    return dp[m][n] = max(lcs(x, y, m - 1, n, dp), lcs(x, y, m, n - 1, dp));
}*/

// Tabulation
int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // cout << printLCS(dp, s, t);
    int i = dp.size();
    int j = dp[0].size();
    int length = dp[i - 1][j - 1];
    char *ch = new char[length];
    // for (int i = 0; i < length; i++)
    //     str += "$";
    int index = 0;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ch[index++] = s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else j--;
    }

    for (int i = 0; i < index; i++) cout << ch[i] << "";
    //cout << s << endl;
    return dp[m][n];
}

// Space Optimized
/*int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<int> previous(n + 1, 0), current(n + 1, 0);

    for (int j = 0; j < n + 1; j++) previous[j] = 0;

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (s[i - 1] == t[j - 1]) current[j] = 1 + previous[j - 1];
            else current[j] = max(previous[j], current[j - 1]);
        }
        previous = current;
    }
    return previous[n];
}*/

// Printing LCS
/*char* printLCS(vector<vector<int>> &dp, string s, string t) {
    int i = dp.size();
    int j = dp[0].size();
    int length = dp[i - 1][j - 1];
    char *ch = new char[length];
    // for (int i = 0; i < length; i++)
    //     str += "$";
    int index = 0;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ch[index++] = s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else j--;
    }
    cout << ch << endl;
}*/

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string x, y;

    // cout << "Enter string 1 : ";
    cin >> x;
    // cout << "Enter string 2 : ";
    cin >> y;

    int m = x.length();
    int n = y.length();

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // cout << lcs(x, y, m - 1, n - 1, dp) << endl;
    cout << lcs(x, y);

    return 0;
}