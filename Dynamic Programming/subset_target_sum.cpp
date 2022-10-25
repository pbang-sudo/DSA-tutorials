#include <bits/stdc++.h>
using namespace std;

// Naive
/*bool subsetSumToK(int n, int k, vector<int> &arr) {
	if (k == 0) return true;
	if (n == 0) return arr[n] == k;

	bool notPick = subsetSumToK(n - 1, k, arr);
	bool pick = false;
	if (k >= arr[n])
		pick = subsetSumToK(n - 1, k - arr[n], arr);
	return (pick | notPick);
}*/

// Memoization
/*bool subsetSumToK(int n, int k, vector<int> &arr, vector<bool> &dp) {
	if (k == 0) return true;
	if (n == 0) return arr[n] == k;
	if (dp[n] != false) return dp[n];

	bool notPick = subsetSumToK(n - 1, k, arr, dp);
	bool pick = false;
	if (k >= arr[n])
		pick = subsetSumToK(n - 1, k - arr[n], arr, dp);
	return dp[n] = (pick | notPick);
}*/

// Tabulation
/*bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
	for (int i = 0; i < n; i++)
		dp[i][0] = true;
	dp[0][arr[0]] = true;

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < k + 1; target++) {
			bool notPick = dp[index - 1][target];
			bool pick = false;
			if (target >= arr[index])
				pick = dp[index - 1][target - arr[index]];
			dp[index][target] = pick | notPick;
		}
	}

	return dp[n - 1][k];
}*/

// Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<bool> previous(k + 1, false);
	previous[0] = true;
	previous[arr[0]] = true;

	for (int index = 1; index < n; index++) {
		vector<bool> current(k + 1, false);
		current[0] = true;
		for (int target = 0; target < k + 1; target++) {
			bool notPick = previous[target];
			bool pick = false;
			if (target >= arr[index])
				pick = previous[target - arr[index]];
			current[target] = pick | notPick;
		}
		previous = current;
	}

	return previous[k];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << (subsetSumToK(n, k, arr) ? "true" : "false");
	vector<bool> dp(n, false);
	// cout << (subsetSumToK(n, k, arr, dp) ? "true" : "false");
	return 0;
}