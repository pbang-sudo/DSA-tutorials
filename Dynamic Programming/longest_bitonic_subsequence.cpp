#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n, 1), dp2(n, 1);
    for(int index = 0; index < n; index++) {
        for(int previous = 0; previous < index; previous++) {
            if(arr[index] > arr[previous]) {
                    dp1[index] = max(dp1[index], 1 + dp1[previous]);  
                }
        }
    }

    // checking for LIS(arr) in reversed order
    for(int index = n - 1; index > -1; index--) {
        for(int previous = n - 1; previous > index; previous--) {
            if(arr[index] > arr[previous]) {
                    dp2[index] = max(dp2[index], 1 + dp2[previous]);  
                }
        }
    }

    int maxi = -1;
    for(int i = 0; i < n; i++) {
    	maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
} 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << longestBitonicSequence(arr, n);
	return 0;
}