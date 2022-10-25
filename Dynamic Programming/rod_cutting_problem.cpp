#include <bits/stdc++.h>
using namespace std;


// Naive
/*int cutRod(vector<int> &price, int n, int index) {
	if (index == 0) return n * price[0];
	int cut = INT_MIN, notCut;
	notCut = cutRod(price, n, index - 1);
	int rodLength = index + 1;
	if (rodLength <= n)
		cut = cutRod(price, n - rodLength, index) + price[index];
	return max(cut, notCut);
}*/

// Memoization
/*int cutRod(vector<int> &price, int n, int index, vector<vector<int>> &dp) {
	if (index == 0) return n * price[0];
	if (dp[index][n] != -1) return dp[index][n];

	int cut = INT_MIN, notCut;
	notCut = cutRod(price, n, index - 1, dp);
	int rodLength = index + 1;
	if (rodLength <= n)
		cut = cutRod(price, n - rodLength, index, dp) + price[index];
	return dp[index][n] = max(cut, notCut);
}*/

// Tabulation
/*int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	for (int i = 0; i < n + 1; i++) {
		dp[0][i] = i * price[0];
	}

	for (int index = 1; index < n; index++) {
		for (int rodLength = 0; rodLength < n + 1; rodLength++) {
			int cut = INT_MIN, notCut;
			notCut = dp[index - 1][rodLength];
			if (rodLength >= index + 1)
				cut = price[index] + dp[index][rodLength - (index + 1)];
			dp[index][rodLength] = max(cut, notCut);
		}
	}

	return dp[n - 1][n];
}*/

// Space Optimization
/*int cutRod(vector<int> &price, int n) {
	vector<int> previous(n + 1, 0), current(n + 1, 0);
	for (int i = 0; i < n + 1; i++) {
		previous[i] = i * price[0];
	}

	for (int index = 1; index < n; index++) {
		for (int rodLength = 0; rodLength < n + 1; rodLength++) {
			int cut = INT_MIN, notCut;
			notCut = previous[rodLength];
			if (rodLength >= index + 1)
				cut = price[index] + current[rodLength - (index + 1)];
			current[rodLength] = max(cut, notCut);
		}
		previous = current;
	}

	return previous[n];
}*/

// 1-D Array Optimization
int cutRod(vector<int> &price, int n) {
	vector<int> previous(n + 1, 0);
	for (int i = 0; i < n + 1; i++) {
		previous[i] = i * price[0];
	}

	for (int index = 1; index < n; index++) {
		for (int rodLength = 0; rodLength < n + 1; rodLength++) {
			int cut = INT_MIN, notCut;
			notCut = previous[rodLength];
			if (rodLength >= index + 1)
				cut = price[index] + previous[rodLength - (index + 1)];
			previous[rodLength] = max(cut, notCut);
		}
	}

	return previous[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	std::vector<int> cost(n);
	for (auto& i : cost)
		cin >> i;

	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	cout << cutRod(cost, n);

	return 0;
}