// Given an array a[] of size N which contains elements from 0 to N-1,
// you need to find all the elements occurring more than once in the given array.
#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n)
{
    // code here
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n > 1)
            num.push_back(i);
    }

    if (num.size() == 0)
        return {-1};
    return num;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> ans = duplicates(arr, n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}