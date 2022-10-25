#include <bits/stdc++.h>
using namespace std;

// Naive Solution
/*int countWays(int m, int n) {
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	int up = countWays(m - 1, n);
	int left = countWays(m, n - 1);
	return up + left;
}*/

// Memoization
/*int countWays(int m, int n, vector<vector<int>> &dp) {
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	if (dp[m][n] != -1) return dp[m][n];
	int up = countWays(m - 1, n, dp);
	int left = countWays(m, n - 1, dp);
	return dp[m][n] = up + left;
}*/
// Tabulation
/*int countWays(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int up = 0, left = 0;
			if (i == 0 && j == 0)
				continue;
			if (i > 0) up = dp[i - 1][j];
			if (j > 0) left = dp[i][j - 1];

			dp[i][j] = up + left;
		}
	}
	return dp[m - 1][n - 1];
}*/

// Space Optimization
int countWays(int m, int n) {
	vector<int> prev(n, 0);
	for (int i = 0; i < m; i++) {
		vector<int> current(n, 0);
		for (int j = 0; j < n; j++) {
			int up = 0, left = 0;
			if (i == 0 && j == 0)
				current[j] = 1;
			if (i > 0) up = prev[j];
			if (j > 0) left = current[j - 1];
			current[j] = up + left;
		}
		prev = current;
	}
	return prev[n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	cin >> m >> n;
	// vector<vector<int>> dp(m, vector<int>(n, -1));
	cout << countWays(m, n);
	// cout << countWays(m - 1, n - 1, dp);
	return 0;
}