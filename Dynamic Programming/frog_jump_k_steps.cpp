#include <bits/stdc++.h>
using namespace std;

int minEnergy(int index, int k, vector<int> &heights, vector<int> &dp) {
	dp[0] = 0;
	for (int i = 1; i < index; i++) {
		int minSteps = INT_MAX;
		for (int j = 1; j <= k; j++) {
			int jump;
			if (i - j >= 0) {
				jump = dp[i - j] + abs(heights[index] - heights[index - j]);
			}
			minSteps = min(minSteps, jump);
		}
		dp[i] = minSteps;
	}
	return dp[index];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, target;
	cin >> n >> k >> target;
	vector<int> h(n);
	for (auto& i : h)
		cin >> i;

	vector<int> dp(n + 1, -1);
	cout << minEnergy(target + 1, k, h, dp);


	return 0;
}