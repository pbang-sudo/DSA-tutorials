#include <bits/stdc++.h>
using namespace std;

// Taking space optimized algorithm from subset_target_sum.cpp
int subsetSumToK(int n, int k, vector<int> &arr) {
	vector<bool> previous(k + 1, false);
	previous[0] = true;
	previous[arr[0]] = true;

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
	int minDiff = INT_MAX;
	for (int i = 0; i < k + 1; i++) {
		if (previous[i] == true) {
			minDiff = min(abs(2 * i - k), minDiff);
		}
	}
	return minDiff;
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

	int sum = 0;
	std::for_each(arr.begin(), arr.end(), [&] (int n) {
		sum += n;
	});

	// vector<bool> result = subsetSumToK(n, sum, arr);
	// int length = result.size();

	// int s2, minDiff = INT_MAX;
	// for (int i = 1; i < length; i++) {
	// 	if (result[i] == true) {
	// 		s2 = sum - i;
	// 		minDiff = min(abs(2 * i - s2), minDiff);
	// 	}
	// }

	cout << subsetSumToK(n, sum, arr);

	return 0;
}