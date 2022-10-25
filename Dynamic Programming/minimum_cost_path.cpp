#include <bits/stdc++.h>
using namespace std;
// Naive
/*int minCost(int n, int m, vector<vector<int>> &grid) {
	if (n == 0 && m == 0) return grid[n][m];
	if (n < 0 || m < 0) return INT_MAX;
	int up = grid[n][m] + minCost(n - 1, m, grid);
	int left = grid[n][m] + minCost(n, m - 1, grid);
	return min(up, left);
}*/

// Memoization
int minCost(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
	if (i == 0 && j == 0) return grid[i][j];
	if (i < 0 || j < 0) return INT_MAX;
	if (dp[i][j] != -1) return dp[i][j];
	int up = grid[i][j] + minCost(i - 1, j, grid, dp);
	int left = grid[i][j] + minCost(i, j - 1, grid, dp);
	return dp[i][j] = min(up, left);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (auto& i : grid) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	// cout << minCost(n - 1, m - 1, grid);
	vector<vector<int>> dp(n, vector<int>(m, -1));
	cout << minCost(n - 1, m - 1, grid, dp);
	return 0;
}