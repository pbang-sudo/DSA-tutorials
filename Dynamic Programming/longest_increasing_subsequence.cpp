#include <bits/stdc++.h>
using namespace std;

// Naive
/*int lis(vector<int> arr, int n, int index, int previous) {
	if(index == n) return 0;
	int take = INT_MIN, notTake;
	notTake = lis(arr, n, index + 1, previous);
	if(previous == -1 || arr[index] > arr[previous])
		take = 1 + lis(arr, n, index + 1, index);
	return max(take, notTake);
}*/

// Memoization
/*int lis(vector<int> arr, int n, int index, int previous, vector<vector<int>> &dp) {
	if(index == n) return 0;
	if(dp[index][previous + 1] != -1) return dp[index][previous + 1];
	int take = INT_MIN, notTake;
	notTake = lis(arr, n, index + 1, previous, dp);
	if(previous == -1 || arr[index] > arr[previous]) 
		take = 1 + lis(arr, n, index + 1, index, dp);
	return dp[index][previous + 1] = max(take, notTake);
}*/

// Tabulation
/*int longestIncreasingSubsequence(vector<int> arr, int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int index = n - 1; index >= 0; index--) {
        for(int previous = index - 1; previous >= -1; previous--) {
            int pick = INT_MIN, notPick;
            notPick = dp[index + 1][previous + 1];
            if(previous == -1 || arr[index] > arr[previous])
            	pick = 1 + dp[index + 1][index + 1];
            dp[index][previous + 1] = max(pick, notPick);
        }
    }

    return dp[0][0];
}*/

// Space Optimization
/*int longestIncreasingSubsequence(vector<int> arr, int n)
{
    vector<int> after(n + 1, 0), current(n + 1, 0);
    for(int index = n - 1; index >= 0; index--) {
        for(int previous = index - 1; previous >= -1; previous--) {
            int pick = INT_MIN, notPick;
            notPick = after[previous + 1];
            if(previous == -1 || arr[index] > arr[previous])
            	pick = 1 + after[index + 1];
            current[previous + 1] = max(pick, notPick);
        }
        after = current;
    }
    return after[0];
}*/

// Tabulation 2
/*int longestIncreasingSubsequence(vector<int> &arr, int n) {
	vector<int> dp(n, 1), hash(n);
	vector<int> lis;
	int lastIndex = 0, maxi = 0;
	for(int index = 0; index < n; index++) {
		hash[index] = index;
		for(int previous = 0; previous < index; previous++) {
			if(arr[index] > arr[previous] && 
				1 + dp[previous] > dp[index]) {
					dp[index] = 1 + dp[previous];
					hash[index] = previous;	
				}
		}
		if(maxi < dp[index]) {
			maxi = dp[index];
			lastIndex = index;
		}
	}

	lis.push_back(lastIndex);
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		lis.push_back(arr[hash[lastIndex]]);
	}
	for(auto& i : lis)
		cout << i << " ";
	cout << endl;
	return *max_element(dp.begin(), dp.end());
}*/

// LIS using Binary Search
int longestIncreasingSubsequence(vector<int> &arr, int n) {
	vector<int> temp;
	temp.push_back(arr[0]);
	int len = 1;
	for(int i = 1; i < n; i++) {
		if(arr[i] > temp.back()) {
			temp.push_back(arr[i]);
			len++;
		}
		else {
			int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[index] = arr[i];
		}
	}
	return len;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	std::vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	// vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	// cout << lis(arr, n, 0, -1, dp);
	cout << longestIncreasingSubsequence(arr, n);
	return 0;
}