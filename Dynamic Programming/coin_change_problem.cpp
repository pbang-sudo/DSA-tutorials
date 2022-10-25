// Calculate the total number of ways to achieve the target.
// Given infinite supply of coins.

#include <bits/stdc++.h>
using namespace std;

// Naive
/*long countWaysToMakeChange(int *coin, int n, int value) {
    if (n == 0) return (value % coin[0] == 0);

    int pick = 0, notPick;
    notPick = countWaysToMakeChange(coin, n - 1, value);
    if (value >= coin[n])
        pick = countWaysToMakeChange(coin, n, value - coin[n]);
    return pick + notPick;
}*/

// Memoization
/*long countWaysToMakeChange(int *coin, int n, int value, vector<vector<int>> &dp) {
    if (n == 0) return (value % coin[0] == 0);
    if (dp[n][value] != -1) return dp[n][value];
    int pick = 0, notPick;
    notPick = countWaysToMakeChange(coin, n - 1, value, dp);
    if (value >= coin[n])
        pick = countWaysToMakeChange(coin, n, value - coin[n], dp);
    return dp[n][value] = pick + notPick;
}*/

// Tabulation
/*long countWaysToMakeChange(int *coin, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i < value + 1; i++)
        dp[0][i] = (i % coin[0] == 0);

    for (int index = 1; index < n; index++) {
        for (int target = 0; target < value + 1; target++) {
            long pick = 0, notPick;
            notPick = dp[index - 1][target];
            if (target >= coin[index])
                pick = dp[index][target - coin[index]];
            dp[index][target] = pick + notPick;
        }
    }
    return dp[n - 1][value];
}*/

// Space Optimized
long countWaysToMakeChange(int *coin, int n, int value) {
    vector<long>current(value + 1, 0), previous(value + 1, 0);
    for (int i = 0; i < value + 1; i++)
        previous[i] = (i % coin[0] == 0);

    for (int index = 1; index < n; index++) {
        for (int target = 0; target < value + 1; target++) {
            long pick = 0, notPick;
            notPick = previous[target];
            if (target >= coin[index])
                pick = current[target - coin[index]];
            current[target] = pick + notPick;
        }
        previous = current;
    }
    return previous[value];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, i, k;
    cin >> n;
    int *coin = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    cin >> k;

    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // cout << countWaysToMakeChange(coin, n - 1, k, dp);

    cout << countWaysToMakeChange(coin, n, k);

    return 0;
}