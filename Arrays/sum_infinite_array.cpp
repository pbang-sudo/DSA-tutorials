#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
	// Write your code here
	vector<int> ans(q); int sum = 0;
	vector<int> prefix(n, 0);
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		prefix[i] = sum % mod;
	}
	int value;
	for (int i = 0; i < q; i++) {
		int l = queries[i][0];
		int r = queries[i][1];

		/*if (l < n && r < n)
			value = (prefix[r] - prefix[l] + arr[l]) % mod;
		else if (l < n && r >= n) {
			value = (r / n) * prefix[n - 1] + prefix[r % n];
			value = (value - prefix[l] + arr[l]) % mod;
		}
		else if (l >= n && r >= n) {
		}*/
		int lval = (l / n) * prefix[n - 1] + prefix[l % n];
		int rval = (r / n) * prefix[n - 1] + prefix[r % n];
		value = (rval - lval + prefix[l % n]) % mod;
		ans.push_back(value);
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../Dynamic Programming/input.txt", "r", stdin);
	freopen("../Dynamic Programming/output.txt", "w", stdout);
#endif

	int n, T;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> T;
	int t = 0;
	vector<vector<long long>> query(T, vector<int>(2, 0));
	while (t < T) {
		int L, R;
		cin >> L >> R;
		query[t][0] = L;
		query[t][1] = R;
		t++;
	}

	vector<int> dp = sumInRanges(arr, n, query, T);
	for (auto& i : dp)
		cout << i << " ";


	return 0;
}