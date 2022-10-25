#include <bits/stdc++.h>
using namespace std;

// Naive
/*int minCost(int i, int j, vector<vector<int>> &triangle) {
	int down, diagonal;
	if (i == triangle.size() - 1) return triangle[i][j];
	down = triangle[i][j] + minCost(i + 1, j, triangle);
	diagonal = triangle[i][j] + minCost(i + 1, j + 1, triangle);
	return min(down, diagonal);
}*/

// Memoization
/*int minCost(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
	// int down, diagonal;
	if (i == triangle.size() - 1) return triangle[i][j];
	if (dp[i][j] != -1) return dp[i][j];
	int down = triangle[i][j] + minCost(i + 1, j, triangle, dp);
	int diagonal = triangle[i][j] + minCost(i + 1, j + 1, triangle, dp);
	return dp[i][j] = min(down, diagonal);
}*/

// Tabulation
int minCost(vector<vector<int>> &triangle) {
	int n = triangle.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	for (int j = 0; j < n; j++)
		dp[n - 1][j] = triangle[n - 1][j];
	for (int i = n - 2; i > -1; i--) {
		for (int j = i; j > -1; j--) {
			int down = triangle[i][j] + dp[i + 1][j];
			int diagonal = triangle[i][j] + dp[i + 1][j + 1];
			dp[i][j] = min(down, diagonal);
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < i + 1; j++) {
	// 		cout << dp[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	return dp[0][0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>> triangle(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> triangle[i][j];
		}
	}
	// vector<vector<int>> dp(n, vector<int>(n, -1));
	// cout << minCost(0, 0, triangle, dp);
	cout << minCost(triangle);
	return 0;
}