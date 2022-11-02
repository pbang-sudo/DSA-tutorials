#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string &s, string &t) {
    if(s.size() != t.size() + 1) return false;
    unsigned int i = 0, j = 0;
    while(i < s.size()) {
        if(j < t.size() && s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    if(i == s.size() && j == t.size()) return true;
    else return false;
}

bool comp(string &s, string &t) {
	return s.size() < t.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int index = 0; index < n; index++) {
        for(int previous = 0; previous < index; previous++) {
            if(checkPossible(arr[index], arr[previous]) && 1 + dp[previous] > dp[index]) {
                    dp[index] = 1 + dp[previous];  
                }
        }
        maxi = max(maxi, dp[index]);
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
	vector<string> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << longestStrChain(arr);
	return 0;
}