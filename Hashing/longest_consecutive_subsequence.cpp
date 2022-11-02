#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int arr[], int n)
{
    vector<int> k;
    k.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            k.push_back(arr[i]);
    }
    return k;
}

int findLongestConseqSubseq(int arr[], int n)
{
    // Your code here
    sort(arr, arr + n);
    vector<int> ans = removeDuplicates(arr, n);
    int N = ans.size();
    int res = 1, curr = 1;
    for (int i = 1; i < N; i++)
    {
        if (ans[i] == ans[i - 1] + 1)
            curr++;
        else
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findLongestConseqSubseq(arr, n) << endl;
    return 0;
}