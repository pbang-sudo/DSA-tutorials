// Only 2 transactions.
#include <bits/stdc++.h>
using namespace std;

// Naive
/*int maxProfit(vector<int> &prices, int n, int index, int buy, int cap) {
	if (index == n - 1 || cap == 0) return 0;

	int profit;
	if (buy == 1)
		return max(-prices[index] + maxProfit(prices, n, index + 1, 0, cap),
		           maxProfit(prices, n, index + 1, 1, cap));
	else
		return max(prices[index] + maxProfit(prices, n, index + 1, 1, cap - 1),
		           maxProfit(prices, n, index + 1, 0, cap));
}*/

// Memoization
/*int maxProfit(vector<int> &prices, int n, int index, int buy, int cap, vector<vector<vector<int>>> &dp) {
	if (index == n || cap == 0) return 0;
	if (dp[index][buy][cap] != -1) return dp[index][buy][cap];

	if (buy == 1)
		return dp[index][buy][cap] = max(-prices[index] + maxProfit(prices, n, index + 1, 0, cap, dp),
		                                 maxProfit(prices, n, index + 1, 1, cap, dp));
	else
		return dp[index][buy][cap] = max(prices[index] + maxProfit(prices, n, index + 1, 1, cap - 1, dp),
		                                 maxProfit(prices, n, index + 1, 0, cap, dp));
}*/

// Tabulation
/*int maxProfit(vector<int>& prices, int n)
{
	// Write your code here.
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

	for (int i = n - 1; i > -1; i--) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k < 3; k++) {
				if (i == n - 1 || k == 0) dp[i][j][k] = 0;

				if (j == 1)
					dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
				else
					dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
			}
		}
	}
	return dp[0][1][2];
}*/


// Space Optimization
int maxProfit(vector<int>& prices, int n)
{
	// Write your code here.
	vector<vector<int>> after(2, vector<int>(3, 0)), current(2, vector<int>(3, 0));

	for (int i = n - 1; i > -1; i--) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k < 3; k++) {

				if (j == 1)
					current[j][k] = max(-prices[i] + after[0][k], after[1][k]);
				else
					current[j][k] = max(prices[i] + after[1][k - 1], after[0][k]);
			}
		}
		after = current;
	}
	return after[1][2];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	vector<int> price(n, 0);

	for (int i = 0; i < n; i++)
		cin >> price[i];

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

	// cout << maxProfit(price, n, 0, 1, 2);
	cout << maxProfit(price, n);

	return 0;
}