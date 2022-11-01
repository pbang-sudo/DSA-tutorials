// Given a matrix of size N x M. You have to find the Kth element which will obtain while
// traversing the matrix spirally starting from the top-left corner of the matrix.

#include <bits/stdc++.h>
using namespace std;

int findK(vector<vector<int>> &a, int n, int m, int k)
{
    // Your code goes here
    int top = 0, left = 0, right = m - 1, bottom = n - 1;
    vector<int> arr;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            arr.push_back(a[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            arr.push_back(a[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr.push_back(a[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr.push_back(a[i][left]);
            }
            left++;
        }
    }
    return arr[k];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;
    cout << findK(mat, n, m, k);
    return 0;
}