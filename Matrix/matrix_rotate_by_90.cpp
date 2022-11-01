// Given a square matrix of size N x N. The task is to rotate it by 90 degrees in
//  anti-clockwise direction without using any extra space.

#include <bits/stdc++.h>
using namespace std;

void rotateby90(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(matrix[low][i], matrix[high][i]);
            low++;
            high--;
        }
    }
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
    rotateby90(mat, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}