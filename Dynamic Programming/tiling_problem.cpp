#include <bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

// Naive
/*int numberOfWaysToTile(long long n, vector<long long> &dp) {
	if (n == 1 || n == 0) return n;
	if (dp[n] != -1) return dp[n];
	return dp[n] = (numberOfWaysToTile(n - 1, dp) % mod) + (numberOfWaysToTile(n - 2, dp) % mod);
}*/

// Tabulation
/*int numberOfWaysToTile(long long n) {
	vector<int> dp(n + 1, -1);
	dp[0] = 1;
	dp[1] = 1;
	// dp[2] = 2;

	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] % mod + dp[i - 2] % mod;
	}
	return dp[n] % mod;
}*/

// Using formula
long long numberOfWaysToTile(long long n) {
	double phi = (1 + sqrt(5)) / 2;
	return (long long)	(round(((long long)(pow(phi, n)) % mod) / sqrt(5))) % mod;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n;

	cin >> n;
	// vector<long long> dp(n + 1, -1);
	// cout << numberOfWaysToTile(n, dp) << endl;

	cout << numberOfWaysToTile(n) % mod;
	return 0;
}