#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    int maxi = 1;
    vector<int> dp(n, 1), count(n, 1);
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < i; j++) {
    		if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
    			dp[i] = 1 + dp[j];
    			count[i] = count[j];
    		}
    		else if(arr[i] > arr[j] && dp[i] == dp[j] + 1)
    			count[i] += count[j];
    	}
    	maxi = max(maxi, dp[i]);
    }
    
    int c = 0;
    for(int i = 0; i < n; i++) {
    	if(dp[i] == maxi) c += count[i];
    }
    return c;
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
	cout << findNumberOfLIS(arr);
	return 0;
}