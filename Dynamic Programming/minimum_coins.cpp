#include <bits/stdc++.h>
using namespace std;

// Naive
/*int minElements(int ind, vector<int> &num, int x) {
	if (ind == 0) {
		if (x % num[ind] == 0) return x / num[ind];
		else return 1e9;
	}

	int pick = INT_MAX, notPick;
	notPick = minElements(ind - 1, num, x);
	if (x >= num[ind]) pick = 1 + minElements(ind, num, x - num[ind]);

	return min(pick, notPick);
}*/

// Memoization
/*int minElements(int ind, vector<int> &num, int x, vector<vector<int>> &dp) {
	if (ind == 0) {
		if (x % num[ind] == 0) return x / num[ind];
		else return 1e9;
	}
	if (dp[ind][x] != -1) return dp[ind][x];

	int pick = INT_MAX, notPick;
	notPick = minElements(ind - 1, num, x, dp);
	if (x >= num[ind]) pick = 1 + minElements(ind, num, x - num[ind], dp);

	return dp[ind][x] = min(pick, notPick);
}*/

// Tabulation
/*int minElements(vector<int> &num, int x) {
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(x + 1, 0));
	for (int i = 0; i < x + 1; i++) {
		if (i % num[0] == 0)
			dp[0][i] = i / num[0];
		else
			dp[0][i] = 1e9;
	}

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < x + 1; target++) {
			int pick = INT_MAX, notPick;
			notPick = dp[index - 1][target];
			if (target >= num[index])
				pick = 1 + dp[index][target - num[index]];

			dp[index][target] = min(pick, notPick);
		}
	}

	int ans = dp[n - 1][x];
	if (ans >= 1e9) return -1;
	else return ans;
}*/

// Space Optimization
int minElements(vector<int> &num, int x) {
	int n = num.size();
	vector<int> previous(x + 1, 0), current(x + 1, 0);
	for (int i = 0; i < x + 1; i++) {
		if (i % num[0] == 0)
			previous[i] = i / num[0];
		else
			previous[i] = 1e9;
	}

	for (int index = 1; index < n; index++) {
		for (int target = 0; target < x + 1; target++) {
			int pick = INT_MAX, notPick;
			notPick = previous[target];
			if (target >= num[index])
				pick = 1 + current[target - num[index]];

			current[target] = min(pick, notPick);
		}
		previous = current;
	}

	int ans = previous[x];
	if (ans >= 1e9) return -1;
	else return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (auto& i : coins)
		cin >> i;

	// vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	// cout << minElements(n - 1, coins, k, dp);

	cout << minElements(coins, k);
	return 0;
}