#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<bool> previous(k + 1, false);
	previous[0] = true;
	if (arr[0] <= k) previous[arr[0]] = true;

	for (int index = 1; index < n; index++) {
		vector<bool> current(k + 1, false);
		current[0] = true;
		for (int target = 0; target < k + 1; target++) {
			bool notPick = previous[target];
			bool pick = false;
			if (target >= arr[index])
				pick = previous[target - arr[index]];
			current[target] = pick | notPick;
		}
		previous = current;
	}

	return previous[k];
}

bool canPartition(vector<int> &arr, int n) {
	int sum = 0;
	std::for_each(arr.begin(), arr.end(), [&] (int n) {
		sum += n;
	});

	if (sum % 2 != 0) return false;

	return (subsetSumToK(n, sum / 2, arr));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;

	cout << (canPartition(arr, n) ? "true" : "false");
	return n;
}