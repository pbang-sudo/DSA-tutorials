#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c)
{
    // code here
    int minimum = matrix[0][0], maximum = matrix[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        minimum = min(minimum, matrix[i][0]);
        maximum = max(maximum, matrix[i][c - 1]);
    }
    int medPos = (r * c + 1) / 2;
    while (minimum < maximum)
    {
        int mid = minimum + (maximum - minimum) / 2;
        int midPos = 0;

        for (int i = 0; i < r; i++)
            midPos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        if (midPos < medPos)
            minimum = mid + 1;
        else
            maximum = mid;
    }
    return minimum;
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

    cout << median(mat, n, m);
    return 0;
}