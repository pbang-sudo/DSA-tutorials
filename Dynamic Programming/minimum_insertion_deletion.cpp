// Source has been copied from longest common subsequence problem then edited.
#include <bits/stdc++.h>
using namespace std;

int lcs(string &s, string &t) {
	int m = s.length();
	int n = t.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x, y;

	// cout << "Enter string 1 : ";
	cin >> x;
	// cout << "Enter string 2 : ";
	cin >> y;

	int m = x.length();
	int n = y.length();

	cout << n + m - 2 * lcs(x, y);

	return 0;
}