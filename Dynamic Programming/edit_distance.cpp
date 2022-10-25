#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

// Naive
/*int editDistance(string &s, string &t, int i, int j)
{
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;

	if (s[i] == t[j]) return editDistance(s, t, i - 1, j - 1);
	else
		return min(1 + editDistance(s, t, i, j - 1), // Insertion
		           min(1 + editDistance(s, t, i - 1, j), // Deletion
		               1 + editDistance(s, t, i - 1, j - 1) // Replace
		              )
		          );
}*/

// Memoization
/*int editDistance(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;
	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == t[j]) return dp[i][j] = editDistance(s, t, i - 1, j - 1, dp);
	else
		return dp[i][j] = min(1 + editDistance(s, t, i, j - 1, dp), // Insertion
		                      min(1 + editDistance(s, t, i - 1, j, dp), // Deletion
		                          1 + editDistance(s, t, i - 1, j - 1, dp) // Replace
		                         )
		                     );
}*/

// Tabulation
/*int editDistance(string &s, string &t)
{
	int m = s.size();
	int n = t.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// base case
	for (int i = 0; i < m + 1; i++) dp[i][0] = i;
	for (int j = 0; j < n + 1; j++) dp[0][j] = j;

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
		}
	}
	return dp[m][n];
}*/

// Space Optimization
int editDistance(string &s, string &t)
{
	int m = s.size();
	int n = t.size();
	vector<int> previous(n + 1, 0), current(n + 1, 0);

	// base case
	for (int j = 0; j < n + 1; j++) {
		previous[j] = j;
	}

	for (int i = 1; i < m + 1; i++) {
		current[0] = i;
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == t[j - 1])
				current[j] = previous[j - 1];
			else
				current[j] = min(1 + previous[j], min(1 + current[j - 1], 1 + previous[j - 1]));
		}
		previous = current;
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

	// vector<vector<int>> dp(x.size(), vector<int>(y.size(), -1));

	cout << editDistance(x, y);

	return 0;
}