// Given a square matrix of size N*N, print the sum of upper and lower triangular elements.
#include <bits/stdc++.h>
using namespace std;

vector<int> sumTriangles(const vector<vector<int>> &matrix, int n)
{
    int supper = 0, slower = 0;
    vector<int> ans(2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j)
            supper += matrix[i][j];
            if(i >= j)
            slower += matrix[i][j];
        }
    }

    ans[0] = supper;
    ans[1] = slower;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = sumTriangles(mat, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}