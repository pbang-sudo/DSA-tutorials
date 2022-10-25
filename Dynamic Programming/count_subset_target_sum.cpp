#include <bits/stdc++.h>
using namespace std;

// Naive
/*int findWays(vector<int> &num, int target, int n) {
	if (target == 0) return 1;
	if (n == 0) return num[0] == target;
	int notPick = findWays(num, target, n - 1);
	int pick = 0;
	if (target >= num[n])
		pick = findWays(num, target - num[n], n - 1);
	return pick + notPick;
}*/

// Memoization
/*int findWays(vector<int> &num, int target, int n, vector<vector<int>> &dp) {
	if (target == 0) return 1;
	if (n == 0) return num[0] == target;
	if (dp[n][target] != -1) return dp[n][target];
	int notPick = findWays(num, target, n - 1, dp);
	int pick = 0;
	if (target >= num[n])
		pick = findWays(num, target - num[n], n - 1, dp);
	return dp[n][target] = pick + notPick;
}*/

// Tabulation
/*int findWays(vector<int> &num, int target) {
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, 0));
	for (int i = 0; i < n; i++) dp[i][0] = 1;

	if (target >= num[0]) dp[0][num[0]] = 1;

	for (int index = 1; index < n; index++) {
		for (int sum = 0; sum < target + 1; sum++) {
			int notPick = dp[index - 1][sum];
			int pick = 0;
			if (sum >= num[index]) pick = dp[index - 1][sum - num[index]];
			dp[index][sum] = pick + notPick;
		}
	}
	return dp[n - 1][target];
}*/

// Space Optimization
int findWays(vector<int> &num, int target) {
	int n = num.size();
	vector<int> previous(target + 1, 0), current(target + 1, 0);
	previous[0] = 1;

	if (target >= num[0]) previous[num[0]] = 1;

	for (int index = 1; index < n; index++) {
		for (int sum = 0; sum < target + 1; sum++) {
			int notPick = previous[sum];
			int pick = 0;
			if (sum >= num[index]) pick = previous[sum - num[index]];
			current[sum] = pick + notPick;
		}
		previous = current;
	}
	return previous[target];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;

	// vector<vector<int>> dp(n, vector<int>(k + 1, -1));

	// cout << findWays(arr, k, n - 1, dp);
	cout << findWays(arr, k);
	return 0;
}