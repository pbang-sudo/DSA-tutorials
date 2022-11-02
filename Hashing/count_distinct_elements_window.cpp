#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int A[], int n, int k)
{
    // code here.
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        mpp[A[i]]++;
    }
    ans.push_back(mpp.size());
    for (int i = k; i < n; i++)
    {
        if (mpp[A[i - k]] == 1)
            mpp.erase(A[i - k]);
        else
            mpp[A[i - k]]--;

        mpp[A[i]]++;
        ans.push_back(mpp.size());
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> ans = countDistinct(arr, n, k);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}