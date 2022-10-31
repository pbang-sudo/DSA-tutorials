// Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.
#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &v, int c)
{
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < c; i++)
    {
        sum += v[i];
        if (sum > mx)
            mx = sum;
        if (sum < 0)
            sum = 0;
    }
    return mx;
}
int maximumSumRectangle(int r, int c, vector<vector<int>> m)
{
    // code here

    int res = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        vector<int> v(c);
        for (int j = i; j < r; j++)
        {

            for (int col = 0; col < c; col++)
            {
                v[col] += m[j][col];
            }
            int temp = kadane(v, c);
            res = max(res, temp);
        }
    }
    return res;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }

    cout << maximumSumRectangle(r, c, m);
}