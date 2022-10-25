#include <bits/stdc++.h>
using namespace std;

// Memoization
/*int fib(vector<int> &dp, int n) {
	if (n <= 1)
		return n;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = fib(dp, n - 1) + fib(dp, n - 2);
}*/

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	// vector<int> dp(n + 1, -1);
	// cout << fib(dp, n);

	// Tabulation Method
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}