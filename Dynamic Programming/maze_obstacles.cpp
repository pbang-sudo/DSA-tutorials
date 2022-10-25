#include <bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

// Naive
/*int countPaths(int n, int m, vector<vector<int>> &arr) {
	if (n >= 0 && m >= 0 && arr[n][m] == -1) return 0;
	if (n == 0 && m == 0) return 1;
	if (n < 0 || m < 0) return 0;
	int up = countPaths(n - 1, m, arr);
	int left = countPaths(n, m - 1, arr);
	return up + left;
}*/

// Memoization
/*int countPaths(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp) {
	if (n >= 0 && m >= 0 && arr[n][m] == -1) return 0;
	if (n == 0 && m == 0) return 1;
	if (n < 0 || m < 0) return 0;
	if (dp[n][m] != INT_MIN) return dp[n][m];
	int up = countPaths(n - 1, m, arr, dp);
	int left = countPaths(n, m - 1, arr, dp);
	return dp[n][m] = up + left;
}*/

// Tabulation
/*int countPaths(int n, int m, vector<vector<int>> &arr) {
	int dp[n][m];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) dp[i][j] = 1;
			else if (arr[i][j] == -1) dp[i][j] = 0;
			else {
				int up = 0, left = 0;
				if (i > 0) up = dp[i - 1][j];
				if (j > 0) left = dp[i][j - 1];
				dp[i][j] = (up + left) % mod;
			}
		}
	}
	return dp[n - 1][m - 1];
}*/

// Space Optimization
int countPaths(int n, int m, vector<vector<int>> &arr) {
	vector<int> prev(m, 0);
	for (int i = 0; i < n; i++) {
		vector<int> current(m, 0);
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) current[j] = 1;
			else if (arr[i][j] == -1) current[j] = 0;
			else {
				int up = 0, left = 0;
				if (i > 0) up = prev[j];
				if (j > 0) left = current[j - 1];
				current[j] = (up + left) % mod;
			}
		}
		prev = current;
	}
	return prev[m - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(m, vector<int>(n));
	for (auto& i : arr) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	cout << countPaths(n, m, arr);
	// vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
	// cout << countPaths(n - 1, m - 1, arr, dp);

	return 0;
}