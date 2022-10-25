// Return the maximum profit.
// Firstly buy stock then you can sell it
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
	int n = arr.size(), profit = 0;
	int minimum = arr[0];
	for (int i = 1; i < n; i++) {
		int cost = arr[i] - minimum;
		profit = max(profit, cost);
		minimum = min(minimum, arr[i]);
	}
	return profit;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	std::vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxProfit(arr);
	return 0;
}