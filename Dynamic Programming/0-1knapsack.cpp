#include <bits/stdc++.h>
using namespace std;

// Naive
/*int knapsack(vector<int> &weight, vector<int> value, int n, int maxWeight) {
	if (n == 0) {
		if (maxWeight >= weight[n]) return value[n];
		else return 0;
	}

	int pick = INT_MIN, notPick;

	notPick = knapsack(weight, value, n - 1, maxWeight);
	if (maxWeight >= weight[n])
		pick = knapsack(weight, value, n - 1, maxWeight - weight[n]) + value[n];
	return max(pick, notPick);
}*/

// Memoization
/*int knapsack(vector<int> &weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp) {
	if (n == 0) {
		if (maxWeight >= weight[n]) return value[n];
		else return 0;
	}
	if (dp[n][maxWeight] != -1) return dp[n][maxWeight];
	int pick = INT_MIN, notPick;

	notPick = knapsack(weight, value, n - 1, maxWeight, dp);
	if (maxWeight >= weight[n])
		pick = knapsack(weight, value, n - 1, maxWeight - weight[n], dp) + value[n];
	return dp[n][maxWeight] = max(pick, notPick);
}
*/
// Tabulation
/*int knapsack(vector<int> &weight, vector<int> value, int n, int maxWeight) {

	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
	for (int i = weight[0]; i < maxWeight + 1; i++) dp[0][i] = value[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < maxWeight + 1; j++) {
			int pick = INT_MIN, notPick;
			notPick = dp[i - 1][j];
			if (j >= weight[i])
				pick = dp[i - 1][j - weight[i]] + value[i];
			dp[i][j] = max(pick, notPick);
		}
	}

	return dp[n - 1][maxWeight];
}*/

// Space Optimization
/*int knapsack(vector<int> &weight, vector<int> value, int n, int maxWeight) {

	vector<int> current(maxWeight + 1, 0), previous(maxWeight + 1, 0);
	for (int i = weight[0]; i < maxWeight + 1; i++) previous[i] = value[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < maxWeight + 1; j++) {
			int pick = INT_MIN, notPick;
			notPick = previous[j];
			if (j >= weight[i])
				pick = previous[j - weight[i]] + value[i];
			current[j] = max(pick, notPick);
		}
		previous = current;
	}

	return previous[maxWeight];
}*/

// 1 Row Optimization
int knapsack(vector<int> &weight, vector<int> value, int n, int maxWeight) {
	vector<int> previous(maxWeight + 1, 0);
	for (int i = weight[0]; i < maxWeight + 1; i++) previous[i] = value[0];

	for (int i = 1; i < n; i++) {
		for (int j = maxWeight; j > -1; j--) {
			int pick = INT_MIN, notPick;
			notPick = previous[j];
			if (j >= weight[i])
				pick = previous[j - weight[i]] + value[i];
			previous[j] = max(pick, notPick);
		}
	}

	return previous[maxWeight];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n;
	vector<int> wt(n), V(n);

	for (auto& i : wt)
		cin >> i;
	for (auto& j : V)
		cin >> j;

	cin >> k;
	cout << knapsack(wt, V, n, k);
	// vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	// cout << knapsack(wt, V, n - 1, k, dp);
	return 0;
}