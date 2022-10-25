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

int minInsertion(string &str) {

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x;
	cin >> x;
	string y = string(x.rbegin(), x.rend());
	cout << x.size() - lcs(x, y) << endl;

	return 0;
}