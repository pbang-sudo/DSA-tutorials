#include <bits/stdc++.h>
using namespace std;

// Naive
/*int maximumProfit(int index, int buy, int n, vector<int> &prices, int k) {
	if(index == n) return 0;

	if(buy == 1) 
		return max(-prices[index] + maximumProfit(index + 1, 0, n, prices, k),
					0 + maximumProfit(index + 1, 1, n, prices, k));
	else
		return max(prices[index] - k + maximumProfit(index + 1, 1, n, prices, k),
					0 + maximumProfit(index + 1, 0, n, prices, k));
}*/

// Memoization
/*int maximumProfit(int index, int buy, int n, vector<int> &prices, int k, vector<vector<int>> &dp) {
	if(index == n) return 0;
	if(dp[index][buy] != -1) return dp[index][buy];
	if(buy == 1) 
		return dp[index][buy] = max(-prices[index] + maximumProfit(index + 1, 0, n, prices, k, dp),
					0 + maximumProfit(index + 1, 1, n, prices, k, dp));
	else
		return dp[index][buy] = max(prices[index] - k + maximumProfit(index + 1, 1, n, prices, k, dp),
					0 + maximumProfit(index + 1, 0, n, prices, k, dp));
}*/

// Tabulation 
/*int maximumProfit(vector<int> &prices, int k) {
	int n = prices.size();
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	for(int index = n - 1; index >= 0; index--) {
		for(int buy = 0; buy < 2; buy++) {
			if(buy == 1)
				dp[index][buy] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
			else
				dp[index][buy] = max(prices[index] - k + dp[index + 1][1], dp[index + 1][0]);
		}
	}
	return dp[0][1];
}*/

// Further optimization to one loop
/*int maximumProfit(vector<int> &prices, int k){
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for(int index = n - 1; index >= 0; index--) {
		dp[index][1] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
		dp[index][0] = max(prices[index] + dp[index + 1][1] - k, dp[index + 1][0]);
    }
    return dp[0][1];
}*/

// Further space optimization
int maximumProfit(vector<int> &prices, int k){
    int n = prices.size();
    vector<int> current(2, 0), after(2, 0);
    for(int index = n - 1; index >= 0; index--) {
		current[1] = max(-prices[index] + after[0], after[1]);
		current[0] = max(prices[index] + after[1] - k, after[0]);
		after = current;
    }
    return after[1];
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

	cout << maximumProfit(prices, k);
	return 0;
}