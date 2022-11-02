#include <bits/stdc++.h>
using namespace std;

bool pairExists(int arr[], int n, int k) {
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
        s.insert(arr[i]);
    
    for(int i = 0; i < n; i++) {
        if(s.find(k - arr[i]) != s.end())
            return true;
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

    cout << (pairExists(arr, n, k) ? "true" : "false");
    return 0;
}