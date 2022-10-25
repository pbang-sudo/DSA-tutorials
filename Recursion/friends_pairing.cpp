// Find the number of ways in which friend can remain single or can be paired up.
#include <bits/stdc++.h>
using namespace std;

// Naive
int countPairs(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;

    return countPairs(n - 1) + countPairs(n - 2) * (n - 1);
}

// Memoization
int countPairs(int n, vector<int> &dp)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = countPairs(n - 1) + countPairs(n - 2) * (n - 1);
}

// Tabulation
int countFriendsPairings(int n) {
    vector<int> dp(n, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * (i - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, -1);
    cout << countPairs(n, dp) << endl;
    return 0;
}