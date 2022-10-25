#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

// Naive
/*int subsequenceCounting(string &s, string &t, int m, int n) {
	// Write your code here.
	if (m < 0) return 1;
	if (n < 0) return 0;

	if (s[m] == t[n])
		return subsequenceCounting(s, t, m - 1, n - 1) % mod + subsequenceCounting(s, t, m - 1, n) % mod;
	else
		return subsequenceCounting(s, t, m - 1, n) % mod;
}*/

// Memoization
/*int subsequenceCounting(string &s, string &t, int m, int n, vector<vector<int>> &dp) {
	// Write your code here.
	if (n < 0) return 1;
	if (m < 0) return 0;
	if (dp[m][n] != -1) return dp[m][n];
	if (s[m] == t[n])
		return dp[m][n] = subsequenceCounting(s, t, m - 1, n - 1, dp) % mod + subsequenceCounting(s, t, m - 1, n, dp) % mod;
	else
		return dp[m][n] = subsequenceCounting(s, t, m - 1, n, dp) % mod;
}*/

// Tabulation
/*int subsequenceCounting(string &s, string &t, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int j = 0; j < m + 1; j++) dp[j][0] = 1;

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
			else
				dp[i][j] = dp[i - 1][j] % mod;
		}
	}
	return dp[m][n];
}*/

// Space Optimization
/*int subsequenceCounting(string &s, string &t, int m, int n) {
	vector<int> previous(n + 1, 0), current(n + 1, 0);
	previous[0] = 1, current[0] = 1;

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == t[j - 1])
				current[j] = (previous[j - 1] + previous[j]) % mod;
			else
				current[j] = previous[j] % mod;
		}
		previous = current;
	}
	return previous[n];
}*/

// 1-D Array Space Optimization
int subsequenceCounting(string &s, string &t, int m, int n) {
	vector<int> previous(n + 1, 0);
	previous[0] = 1;

	for (int i = 1; i < m + 1; i++) {
		for (int j = n; j > 0; j--) {
			if (s[i - 1] == t[j - 1])
				previous[j] = (previous[j - 1] + previous[j]) % mod;
		}
	}
	return previous[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x, y;
	cin >> x;
	cin >> y;

	int m = x.size();
	int n = y.size();

	//cout << subsequenceCounting(x, y, m - 1, n - 1);
	vector<vector<int>> dp(m, vector<int>(n, -1));
	cout << subsequenceCounting(x, y, m, n);

	return 0;
}