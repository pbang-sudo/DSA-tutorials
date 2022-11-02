#include <bits/stdc++.h>
using namespace std;

int countPair(int arr[], int n, int k) {
    unordered_set<int> s;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s.find(k - arr[i]) != s.end())
            count++;
        s.insert(arr[i]);
    }
    return ((count > 0) ? count : -1);
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countPair(arr, n, k) << endl;
    return 0;
}