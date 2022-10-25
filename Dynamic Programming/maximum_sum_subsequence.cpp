#include <bits/stdc++.h>
using namespace std;
// Calculate the maximum sum of the subsequence (non-adjacent elements only)
// Naive Solution
/*int maxSum(int index, vector<int> &array) {
	if (index == 0) return array[index];
	if (index < 0) return 0;
	int pick = array[index] + maxSum(index - 2, array);
	int not_pick = maxSum(index - 1, array);
	return max(pick, not_pick);
}*/

// Memoization
/*int maxSum(int index, vector<int> &arr, vector<int> &dp) {
	if (index == 0) return arr[index];
	if (index < 0) return 0;
	if (dp[index] != -1) return dp[index];
	int pick = arr[index] + maxSum(index - 2, arr, dp);
	int not_pick = maxSum(index - 1, arr, dp);
	dp[index] = max(pick, not_pick);
}*/

// Tabulation
int maxSum(vector<int> &arr) {
	int length = arr.size();
	vector<int> dp(length);
	dp[0] = arr[0];
	for (int i = 1; i < length; i++) {
		int pick = arr[i];
		if (i > 1)
			pick += dp[i - 2];
		int not_pick = dp[i - 1];
		dp[i] = max(pick, not_pick);
	}
	return *max_element(dp.begin(), dp.end());
}


// Space Optimized Tabulation
/*
	int maxSum(vector<int> &arr) {
		int length = arr.size();
		int prev = arr[0];
		int prev2 = 0;
		for(int i = 1; i < n; i++) {
			int pick = arr[i];
			if(i > 1)
				pick += prev2;
			int not_pick = prev;
			int curi = max(pick, not_pick);
			prev2 = prev;
			prev = curi;
		}
		return prev;
	}
*/

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;

	// cout << maxSum(n - 1, h);

	// vector<int> dp(n + 1, -1);
	cout << maxSum(arr);

	return 0;
}