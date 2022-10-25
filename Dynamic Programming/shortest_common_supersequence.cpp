// Source has been copied from Minimum Insertion / Deletion problem then edited.
#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string s, string t)
{
    // Using the concept of Longest Commong Subsequence
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string str = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            str += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            str += s[i - 1];
            i--;
        }
        else {
            str += t[j - 1];
            j--;
        }
    }

    // If any character left in string 1.
    while (i > 0) {
        str += s[i - 1];
        i--;
    }

    // If any character left in string 2.
    while (j > 0) {
        str += t[j - 1];
        j--;
    }

    string ans = string(str.rbegin(), str.rend());
    return ans;
}

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

    cout << shortestSupersequence(x, y);
    return 0;
}