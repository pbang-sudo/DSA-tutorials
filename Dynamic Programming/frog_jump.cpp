#include <bits/stdc++.h>
using namespace std;

// Memoization
/*int minEnergy(int index, vector<int> &heights, vector<int> &dp) {
	if (index == 0) return 0;
	if (dp[index] != -1) return dp[index];
	int left = minEnergy(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
	int right = INT_MAX;
	if (index > 1)
		right = minEnergy(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
	return dp[index] = min(left, right);
}*/

// Tabulation
int minEnergy(int index, vector<int> &heights) {
	vector<int> dp(index, 0);
	dp[0] = 0;
	for (int i = 1; i < index; i++) {
		int firstStep, secondStep = INT_MAX;
		firstStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
		if (i > 1)
			secondStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
		dp[i] = min(firstStep, secondStep);
	}
	return dp[index - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (auto& i : h)
		cin >> i;

	// vector<int> dp(n + 1, -1);
	cout << minEnergy(k + 1, h);


	return 0;
}