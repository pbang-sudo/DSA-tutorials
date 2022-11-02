// Here atmost k transactions are needed to be performed.
#include <bits/stdc++.h>
using namespace std;
// Naive
/*int maximumProfit(int index, int transNo, vector<int> &prices, int n, int k) {
	if(index == n || transNo == 2 * k) return 0;
	if(transNo % 2 == 0)		//buy
		return max(-prices[index] + maximumProfit(index + 1, transNo + 1, prices, n, k),
					0 + maximumProfit(index + 1, transNo, prices, n, k));
	else		// sell
		return max(prices[index] + maximumProfit(index + 1, transNo + 1, prices, n, k),
					0 + maximumProfit(index + 1, transNo, prices, n, k));
}*/

// Memoization
/*int maximumProfit(int index, int transNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp) {
	if(index == n || transNo == 2 * k) return 0;
	if(dp[index][transNo] != -1) return dp[index][transNo];
	if(transNo % 2 == 0)		//buy
		return dp[index][transNo] = max(-prices[index] + maximumProfit(index + 1, transNo + 1, prices, n, k, dp),
					0 + maximumProfit(index + 1, transNo, prices, n, k, dp));
	else		// sell
		return dp[index][transNo] = max(prices[index] + maximumProfit(index + 1, transNo + 1, prices, n, k, dp),
					0 + maximumProfit(index + 1, transNo, prices, n, k, dp));
}*/

// Tabulation
/*int maximumProfit(vector<int> &prices, int n, int k) {
	vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
	for(int index = n - 1; index >= 0; index--) {
		for(int transNo = 2 * k - 1; transNo >= 0; transNo--) {
			if(transNo % 2 == 0)		//buy
			dp[index][transNo] = max(-prices[index] + dp[index + 1][transNo + 1],
					0 + dp[index + 1][transNo]);
	else		// sell
		dp[index][transNo] = max(prices[index] + dp[index + 1][transNo + 1],
					0 + dp[index + 1][transNo]);
		}
	}
	return dp[0][0];
}*/

// Space Optimized
int maximumProfit(vector<int> &prices, int n, int k) {
	vector<int> current(2 * k + 1, 0), after(2 * k + 1, 0);
	for(int index = n - 1; index >= 0; index--) {
		for(int transNo = 2 * k - 1; transNo >= 0; transNo--) {
			if(transNo % 2 == 0)		//buy
			current[transNo] = max(-prices[index] + after[transNo + 1],
					0 + after[transNo]);
	else		// sell
		current[transNo] = max(prices[index] + after[transNo + 1],
					0 + after[transNo]);
		}
		after = current;
	}
	return after[0];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	std::vector<int> prices(n);
	for(int i = 0; i < n; i++) cin >> prices[i];

	// cout << maximumProfit(0, 0, prices, n, k);
	// vector<vector<int>> dp(n, vector<int> (2 * k, -1));
	cout << maximumProfit(prices, n, k);
	return 0;
}