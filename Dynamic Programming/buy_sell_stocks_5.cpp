// Best Time to Buy and Sell Stock with Cooldown
// i.e. cannot buy right after sell
#include <bits/stdc++.h>
using namespace std;

// Naive
/*int stockProfit(vector<int> &prices, int buy, int index, int n){
    if(index >= n) return 0;
    if(buy == 1)
    	return max(-prices[index] + stockProfit(prices, 0, index + 1, n),
    				0 + stockProfit(prices, 1, index + 1, n));
    else
    	return max(prices[index] + stockProfit(prices, 1, index + 2, n),
    				0 + stockProfit(prices, 0, index + 1, n));
}*/

// Memoization
/*int stockProfit(vector<int> &prices, int buy, int index, int n, vector<vector<int>> &dp){
    if(index >= n) return 0;
    if(dp[index][buy] != -1) return dp[index][buy];
    if(buy == 1)
    	return dp[index][buy] = max(-prices[index] + stockProfit(prices, 0, index + 1, n, dp),
    				0 + stockProfit(prices, 1, index + 1, n, dp));
    else
    	return dp[index][buy] = max(prices[index] + stockProfit(prices, 1, index + 2, n, dp),
    				0 + stockProfit(prices, 0, index + 1, n, dp));
}*/

// Tabulation
/*int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for(int index = n - 1; index >= 0; index--) {
    	for(int buy = 0; buy < 2; buy++) {
    		if(buy == 1) 
    			dp[index][buy] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
    		else
    			dp[index][buy] = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
    	}
    }
    return dp[0][1];
}*/

// Further optimization to one loop
/*int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for(int index = n - 1; index >= 0; index--) {
		dp[index][1] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
		dp[index][0] = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
    }
    return dp[0][1];
}*/

// Further space optimization
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> front1(2, 0), front2(2, 0), current(2, 0);
    for(int index = n - 1; index >= 0; index--) {
		current[1] = max(-prices[index] + front1[0], front1[1]);
		current[0] = max(prices[index] + front2[1], front1[0]);

		front2 = front1;
		front1 = current;
    }
    return current[1];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	std::vector<int> prices(n);
	for(int i = 0; i < n; i++) cin >> prices[i];

	vector<vector<int>> dp(n, vector<int>(2, -1));
	cout << stockProfit(prices);
	return 0;
}