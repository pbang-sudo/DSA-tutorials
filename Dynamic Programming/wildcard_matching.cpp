#include <bits/stdc++.h>
using namespace std;

// Naive
/*bool wildcardMatching(string pattern, string text, int i, int j)
{
	// base case
	if (i < 0 && j < 0) return true; // if both pattern and text are exhausted.
	if (i < 0 && j > -1) return false; // if pattern is exhausted and text is not.
	if (j < 0 && i > -1) {
		// if text is exhausted but pattern is not then pattern has to contain all '*'.
		for (int k = 0; k < i + 1; k++) {
			if (pattern[k] != '*')
				return false;
		}

	}

	if (pattern[i] == text[j] || pattern[i] == '?')
		return wildcardMatching(pattern, text, i - 1, j - 1);
	if (pattern[i] == '*') {
		bool takeStar = wildcardMatching(pattern, text, i, j - 1);
		bool notTakeStar = wildcardMatching(pattern, text, i - 1, j);
		return takeStar | notTakeStar;
	}
	return false;
}*/

// Memoization
/*bool wildcardMatching(string pattern, string text, int i, int j, vector<vector<int>> &dp)
{
	// base case
	if (i < 0 && j < 0) return true; // if both pattern and text are exhausted.
	if (i < 0 && j > -1) return false; // if pattern is exhausted and text is not.
	if (j < 0 && i > -1) {
		// if text is exhausted but pattern is not then pattern has to contain all '*'.
		for (int k = 0; k < i + 1; k++) {
			if (pattern[k] != '*')
				return false;
		}
		return true;
	}
	if (dp[i][j] != -1) return dp[i][j];

	if (pattern[i] == text[j] || pattern[i] == '?')
		return dp[i][j] = wildcardMatching(pattern, text, i - 1, j - 1, dp);
	if (pattern[i] == '*') {
		bool takeStar = wildcardMatching(pattern, text, i, j - 1, dp);
		bool notTakeStar = wildcardMatching(pattern, text, i - 1, j, dp);
		return dp[i][j] = takeStar | notTakeStar;
	}
	return dp[i][j] = false;
}*/

// Tabulation
/*bool wildcardMatching(string pattern, string text)
{
	int m = pattern.size();
	int n = text.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int j = 1; j < n + 1; j++) dp[0][j] = false;
	for (int i = 1; i < m + 1; i++) {
		bool flag = true;
		for (int j = 1; j < i + 1; j++) {
			if (pattern[j - 1] != '*') {
				flag = false;
				break;
			}
		}
		dp[i][0] = flag;
	}

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (pattern[i - 1] == '*')
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
			else
				dp[i][j] = false;
		}
	}

	return dp[m][n];
}*/

// Space Optimization
bool wildcardMatching(string pattern, string text)
{
	int m = pattern.size();
	int n = text.size();
	vector<bool> previous(n + 1, false), current(n + 1, false);
	previous[0] = true;
	for (int j = 1; j < n + 1; j++) previous[j] = false;

	for (int i = 1; i < m + 1; i++) {
		bool flag = true;
		for (int j = 1; j < i + 1; j++) {
			if (pattern[j - 1] != '*') {
				flag = false;
				break;
			}
		}
		current[0] = flag; // 0th row has to be assigned everytime.
		for (int j = 1; j < n + 1; j++) {
			if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
				current[j] = previous[j - 1];
			else if (pattern[i - 1] == '*')
				current[j] = previous[j] | current[j - 1];
			else
				current[j] = false;
		}
		previous = current;
	}

	return previous[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../Dynamic Programming/input.txt", "r", stdin);
	freopen("../Dynamic Programming/output.txt", "w", stdout);
#endif


	string x, y;
	cin >> x;
	cin >> y;
	// vector<vector<int>> dp(x.size(), vector<int>(y.size(), -1));

	if (wildcardMatching(x, y)) cout << "True";
	else cout << "False";
	return 0;
}