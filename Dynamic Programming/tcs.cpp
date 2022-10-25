#include <bits/stdc++.h>
using namespace std;

// Naive
/*int maxMilk(int n, int x, int y, int z) {
	if (n == 0)
		return 0;
	if (n < 0) return -1e9;

	int pickPlastic = 0, pickGlass = 0;
	pickPlastic = maxMilk(n - x, x, y, z) + 1;
	pickGlass = maxMilk(n - y, x, y, z) + 1;

	if ((n < x && n < y))
		return maxMilk(n + z, x, y, z);
	return max(pickGlass, pickPlastic);
}*/

// Memoization
int maxMilk(int n, int x, int y, int z, vector<int> &dp) {
	if (n == 0)
		return 0;
	if (n < 0) return -1e9;

	int pickPlastic = 0, pickGlass = 0;
	pickPlastic = maxMilk(n - x, x, y, z, dp) + 1;
	pickGlass = maxMilk(n - y, x, y, z, dp) + 1;

	if ((n < x && n < y))
		return dp[n] = maxMilk(n + z, x, y, z, dp);
	return dp[n] = max(pickGlass, pickPlastic);
}

// Tabulation
int maxMilk(int n, int x, int y, int z) {
	if (n == 0)
		return 0;
	if (n < 0) return -1e9;
	vector<int> dp(n + z + 1, 0);
	// dp[0] = -1;

	for (int i = 1; i < n + z + 1; i++) {
		int pickPlastic = 0, pickGlass = 0;
		if (i >= x)
			pickPlastic = dp[i - x] + 1;
		if (i >= y)
			pickGlass = dp[i - y] + 1;
		if (i < x && i < y)
			dp[i] = dp[i - 1 + z] + 1;
		else
			dp[i] = max(pickGlass, pickPlastic);
	}
	return dp[n + z];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, x, y, z;
	cin >> n;
	cin >> x >> y >> z;

	cout << maxMilk(n, x, y, z);
	vector<int> dp(n + 1, -1);
	// cout << maxMilk(n, x, y, z, dp);
	return 0;
}