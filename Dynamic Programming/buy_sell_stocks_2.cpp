// Return the maximum profit.
// Firstly buy stock then you can sell it.
// Buy as many stocks and sell as many as you want.
// After buy you can sell but hold no previous holding.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int index, int buy, vector<int> &arr, int n) {
	if (index == n) return 0;
	int transaction1, transaction2;
	if (buy == 0) {
		transaction1 = 0 + maxProfit(index + 1, 0, arr, n);
		transaction2 = -arr[index] + maxProfit(index + 1, 1, arr, n);
	}
	if (buy == 1) {
		transaction1 = 0 + maxProfit(index + 1, 1, arr, n);
		transaction2 = arr[index] + maxProfit(index + 1, 0, arr, n);
	}
	return max(transaction1, transaction2);
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

	cout << maxProfit(0, 0, arr, n);
	return 0;
}