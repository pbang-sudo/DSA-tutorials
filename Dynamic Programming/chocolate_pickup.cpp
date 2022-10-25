#include <bits/stdc++.h>
using namespace std;

// Naive
/* int util(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid) {
	if (j1 < 0 || j2 < 0 || j1 > c - 1 || j2 > c - 1) return -1e8;
	if (i == r - 1) {
		if (j1 == j2) return grid[i][j1];
		else
			return grid[i][j1] + grid[i][j2];
	}

	int maxi = -1e8;
	for (int d1 = -1; d1 < 2; d1++) {
		for (int d2 = -1; d2 < 2; d2++) {
			if (j1 == j2)
				maxi = max(maxi, grid[i][j1] + util(i + 1, j1 + d1, j2 + d2, r, c, grid));
			else
				maxi = max(maxi, grid[i][j1] + grid[i][j2] + util(i + 1, j1 + d1, j2 + d2, r, c, grid));
		}
	}
	return maxi;
}*/

// Memoization
/*int maxChocolate(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
	if (j1 < 0 || j2 < 0 || j1 > c - 1 || j2 > c - 1) return -1e8;
	if (i == r - 1) {
		if (j1 == j2) return grid[i][j1];
		else return grid[i][j1] + grid[i][j2];
	}
	if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

	int currCost = -1e8;
	for (int d1 = -1; d1 < 2; d1++) {
		for (int d2 = -1; d2 < 2; d2++) {
			int value = 0;
			if (j1 == j2) value = grid[i][j1];
			else value = grid[i][j1] + grid[i][j2];

			value += maxChocolate(i + 1, j1 + d1, j2 + d2, r, c, grid, dp);
			currCost = max(currCost, value);
		}
	}
	return dp[i][j1][j2] = currCost;
}*/

// Tabulation
/*int maxChocolate(int r, int c, vector<vector<int>> &grid) {
	vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
	for (int j1 = 0; j1 < c; j1++) {
		for (int j2 = 0; j2 < c; j2++) {
			dp[r - 1][j1][j2] = (j1 == j2) ? grid[r - 1][j1] : grid[r - 1][j1] + grid[r - 1][j2];
		}
	}

	for (int i = r - 2; i > -1; i--) {
		for (int j1 = 0; j1 < c; j1++) {
			for (int j2 = 0; j2 < c; j2++) {
				int currCost = -1e8;
				for (int d1 = -1; d1 < 2; d1++) {
					for (int d2 = -1; d2 < 2; d2++) {
						int value = 0;
						if (j1 == j2) value = grid[i][j1];
						else value = grid[i][j1] + grid[i][j2];
						if (j1 + d1 > -1 && j1 + d1 < c && j2 + d2 > -1 && j2 + d2 < c)
							value += dp[i + 1][j1 + d1][j2 + d2];
						else
							value += -1e8;
						currCost = max(currCost, value);
					}
				}
				dp[i][j1][j2] = currCost;
			}
		}
	}
	return dp[0][0][c - 1];
}*/

// Space Optimization
int maxChocolate(int r, int c, vector<vector<int>> &grid) {
	vector<vector<int>> front(c, vector<int>(c, -1));
	vector<vector<int>> current(c, vector<int>(c, -1));
	for (int j1 = 0; j1 < c; j1++) {
		for (int j2 = 0; j2 < c; j2++) {
			front[j1][j2] = (j1 == j2) ? grid[r - 1][j1] : grid[r - 1][j1] + grid[r - 1][j2];
		}
	}

	for (int i = r - 2; i > -1; i--) {
		for (int j1 = 0; j1 < c; j1++) {
			for (int j2 = 0; j2 < c; j2++) {
				int currCost = -1e8;
				for (int d1 = -1; d1 < 2; d1++) {
					for (int d2 = -1; d2 < 2; d2++) {
						int value = 0;
						if (j1 == j2) value = grid[i][j1];
						else value = grid[i][j1] + grid[i][j2];
						if (j1 + d1 > -1 && j1 + d1 < c && j2 + d2 > -1 && j2 + d2 < c)
							value += front[j1 + d1][j2 + d2];
						else
							value += -1e8;
						currCost = max(currCost, value);
					}
				}
				current[j1][j2] = currCost;
			}
		}
		front = current;
	}
	return front[0][c - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	// cout << util(0, 0, c - 1, r, c, grid);
	// vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
	// cout << maxChocolate(0, 0, c - 1, r, c, grid, dp);

	cout << maxChocolate(r, c, grid);

	return 0;
}