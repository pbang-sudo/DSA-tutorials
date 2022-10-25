#include <bits/stdc++.h>
using namespace std;

// Naive
/*int maxCostPath(int i, int j, vector<vector<int>> &matrix) {
	if (j < 0 || j >= matrix[0].size()) return -1e9;
	if (i == 0) return matrix[i][j];

	int up = matrix[i][j] + maxCostPath(i - 1, j, matrix);
	int diagonal_up_left = matrix[i][j] + maxCostPath(i - 1, j - 1, matrix);
	int diagonal_up_right = matrix[i][j] + maxCostPath(i - 1, j + 1, matrix);

	return max(up, max(diagonal_up_left, diagonal_up_right));
}*/

// Memoization
/*int maxCostPath(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
	if (j < 0 || j >= matrix[0].size()) return -1e9;
	if (i == 0) return matrix[i][j];
	if (dp[i][j] != -1) return dp[i][j];

	int up = matrix[i][j] + maxCostPath(i - 1, j, matrix, dp);
	int diagonal_up_left = matrix[i][j] + maxCostPath(i - 1, j - 1, matrix, dp);
	int diagonal_up_right = matrix[i][j] + maxCostPath(i - 1, j + 1, matrix, dp);

	return dp[i][j] = max(up, max(diagonal_up_left, diagonal_up_right));
}*/

// Tabulation
/*int maxCostPath(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	for (int j = 0; j < m; j++)
		dp[0][j] = matrix[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = matrix[i][j] + dp[i - 1][j];
			int diagonal_up_left = matrix[i][j];
			int diagonal_up_right = matrix[i][j];

			diagonal_up_left += (j > 0) ? dp[i - 1][j - 1] : -1e9;
			diagonal_up_right += (j < m - 1) ? dp[i - 1][j + 1] : -1e9;

			dp[i][j] = max(up, max(diagonal_up_left, diagonal_up_right));
		}
	}
	return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}*/

// Space Optimization
int maxCostPath(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> prev(m, 0), curr(m, 0);
	for (int j = 0; j < m; j++)
		prev[j] = matrix[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = matrix[i][j] + prev[j];
			int diagonal_up_left = matrix[i][j];
			int diagonal_up_right = matrix[i][j];

			diagonal_up_left += (j > 0) ? prev[j - 1] : -1e9;
			diagonal_up_right += (j < m - 1) ? prev[j + 1] : -1e9;

			curr[j] = max(up, max(diagonal_up_left, diagonal_up_right));
		}
		prev = curr;
	}
	return *max_element(prev.begin(), prev.end());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	// vector<vector<int>> dp(n, vector<int>(m, -1));
	// int curr_cost = 0;
	// for (int j = 0; j < m; j++) {
	// 	curr_cost = max(maxCostPath(n - 1, j, matrix, dp), curr_cost);
	// }
	// cout << curr_cost;

	cout << maxCostPath(matrix);
	return 0;
}