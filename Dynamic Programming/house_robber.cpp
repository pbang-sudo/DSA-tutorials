#include <bits/stdc++.h>
using namespace std;

// Memoization
int maxMoneyLooted(vector<int> &house, int n, vector<int> &dp) {
	if (n == 0) return house[0];
	if (dp[n] != -1) return dp[n];

	int loot = INT_MIN;
	int notLoot = maxMoneyLooted(house, n - 1, dp);
	if (n > 1)
		loot = house[n] + maxMoneyLooted(house, n - 2, dp);

	return dp[n] = max(loot, notLoot);
}

/*// Tabulation
int maxMoneyLooted(vector<int> &house, int n) {
	vector<int> dp(n, 0);
	dp[0] = house[0];

	for (int i = 1; i < n; i++) {
		int loot = 0;
		int notLoot = dp[i - 1];
		if (i > 1)
			loot = house[i] + dp[i - 2];
		dp[i] = max(loot, notLoot);
	}

	return dp[n - 1];
}*/

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> house(n);
	for (auto& i : house)
		cin >> i;

	vector<int> dp(n, -1);
	cout << maxMoneyLooted(house, n - 1, dp);

	return 0;
}