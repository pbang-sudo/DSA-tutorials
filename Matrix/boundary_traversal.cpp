#include <bits/stdc++.h>
using namespace std;

vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
{
    // code here
    vector<int> ans;
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            ans.push_back(matrix[0][i]);
        }
    }

    else if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            ans.push_back(matrix[i][0]);
        }
    }

    else
    {
        for (int i = 0; i < m; i++)
            ans.push_back(matrix[0][i]);
        for (int i = 1; i < n; i++)
            ans.push_back(matrix[i][m - 1]);
        for (int i = m - 2; i > -1; i--)
            ans.push_back(matrix[n - 1][i]);
        for (int i = n - 2; i > 0; i--)
            ans.push_back(matrix[i][0]);
    }

    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<int> ans = boundaryTraversal(mat, r, c);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}