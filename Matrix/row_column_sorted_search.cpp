// Given a matrix of size n x m, where every row and column is sorted in increasing order,
// and a number x. Find whether element x is present in the matrix or not.

#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    // code here
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == x)
                return true;
        }
    }

    else if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == x)
                return true;
        }
    }

    else
    {
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == x)
                return true;
            else if (matrix[i][j] > x)
                j--;
            else
                i++;
        }
    }

    return false;
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
    cout << search(mat, n, m, k);
    return 0;
}