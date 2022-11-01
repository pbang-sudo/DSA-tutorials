// For 2 given matrices of size n x n. Your task is to multiply them.

#include <bits/stdc++.h>
using namespace std;

void Mutliply(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB)
{
    // Code here
    int n = matrixA.size();

    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][k] += matrixA[i][j] * matrixB[j][k];
            }
        }
    }
    matrixA = res;
}

int main()
{
    int n, m;
    cin >> n;
    vector<vector<int>> mat1(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    vector<vector<int>> mat2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat2[i][j];
        }
    }

    Mutliply(mat1, mat2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}