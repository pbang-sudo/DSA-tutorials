#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sorting the array is must!!!
    vector<int> dp(n,1), hash(n,1);
    for(int i = 0; i < n; i++){    
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index < i; prev_index ++) {
            if(arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
  
    int ans = -1;
    int lastIndex =-1;
    
    for(int i = 0; i < n; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> lds;
    lds.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        lds.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(lds.begin(),lds.end());
    return lds;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans = divisibleSet(arr);
	n = ans.size();
	for(int i = 0; i < n; i++) 
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}