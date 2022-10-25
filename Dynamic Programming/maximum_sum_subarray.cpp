#include <bits/stdc++.h>
using namespace std;

int maxSum(int index, vector<int> &arr, int sum) {
	if (index == 0) {
		return arr[0];
	}

	int pick = -1e9, notPick;
	notPick = maxSum(index - 1, arr, 0);
	if (sum > arr[index])
		pick = arr[index] + maxSum(index - 1, arr, arr[index]);
	else
		pick = arr[index] + maxSum(index - 1, arr, sum);
	return max(pick, notPick);
}

int main() {
#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxSum(n - 1, arr, 0);
	return 0;
}