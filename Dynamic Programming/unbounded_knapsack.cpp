#include <bits/stdc++.h>
using namespace std;

// Memoization
/*int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
	if (n == 0) return ((w / weight[0]) * profit[0]);
	if(dp[n][w] != -1) return dp[n][w];
	int pick = INT_MIN, notPick;
	notPick = unboundedKnapsack(n - 1, w, profit, weight, dp);
	if (w >= weight[n])
		pick = unboundedKnapsack(n, w - weight[n], profit, weight, dp) + profit[n];
	return dp[n][w] = max(pick, notPick);
}*/

// Tabulation
/*int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n, vector<int>(w + 1, 0));
	for (int i = weight[0]; i < w + 1; i++) dp[0][i] = ((int)i / weight[0]) * profit[0];

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < w + 1; target++) {
			int pick = INT_MIN, notPick;
			notPick = 0 + dp[index - 1][target];
			if (target >= weight[index])
				pick = dp[index][target - weight[index]] + profit[index];
			dp[index][target] = max(pick, notPick);
		}
	}
	return dp[n - 1][w];
}*/

// Space Optimization
/*int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<int> previous(w + 1, 0), current(w + 1, 0);
	for (int i = weight[0]; i < w + 1; i++) previous[i] = ((int)i / weight[0]) * profit[0];

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < w + 1; target++) {
			int pick = INT_MIN, notPick;
			notPick = 0 + previous[target];
			if (target >= weight[index])
				pick = current[target - weight[index]] + profit[index];
			current[target] = max(pick, notPick);
		}
		previous = current;
	}
	return previous[w];
}*/

// 1-D array optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<int> current(w + 1, 0);
	for (int i = weight[0]; i < w + 1; i++) current[i] = ((int)i / weight[0]) * profit[0];

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < w + 1; target++) {
			int pick = INT_MIN, notPick;
			notPick = 0 + current[target];
			if (target >= weight[index])
				pick = current[target - weight[index]] + profit[index];
			current[target] = max(pick, notPick);
		}
	}
	return current[w];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> wt(n), value(n);
	for (auto& i : value)
		cin >> i;
	for (auto& i : wt)
		cin >> i;

	vector<vector<int>> dp(n, vector<int>(k + 1, -1));

	cout << unboundedKnapsack(n, k, value, wt);

	return 0;
}