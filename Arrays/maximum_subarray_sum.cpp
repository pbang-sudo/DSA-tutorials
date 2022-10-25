#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    cin >> arr[i];

    int currSum = INT_MIN;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        sum = max(sum, arr[i]);
        currSum = max(sum, currSum);
    }

    cout << currSum << endl;
    return 0;
}