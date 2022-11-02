#include <bits/stdc++.h>
using namespace std;

bool isSubarray(int arr[], int n, int k) {
    unordered_set<int> s;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == k)
            return true;
        if(s.find(sum) != s.end())
            return true;
        s.insert(sum);
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << isSubarray(arr, n, k) << endl;
    return 0;
}