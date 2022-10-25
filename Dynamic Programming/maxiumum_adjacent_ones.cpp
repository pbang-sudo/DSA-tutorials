#include <bits/stdc++.h>
using namespace std;
int n;

int maxCount(int matrix[][4], int size, int row_counter, int column_counter)
{
    if (row_counter == 0 || column_counter == 0)
        return 0;
    if (matrix[row_counter][column_counter] == 1)
    {
        if (matrix[row_counter - 1][column_counter] == 1 && matrix[row_counter][column_counter - 1] == 1)
            return maxCount(matrix, size, row_counter - 1, column_counter - 1) + 1;
        if (matrix[row_counter - 1][column_counter] == 1 || matrix[row_counter][column_counter - 1] == 1)
            return max(maxCount(matrix, size, row_counter - 1, column_counter) + 1, maxCount(matrix, size, row_counter, column_counter - 1) + 1);
    }
    else
        return 0;
}

int main()
{
    // cout << "Enter size: ";
    // cin >> n;
    int matrix[][4] = {{1, 0, 0, 1},
                       {0, 1, 1, 0},
                       {0, 1, 1, 0},
                       {1, 0, 0, 1}};
    int i, j;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    cout << "Maximum Adjacent Ones : " << maxCount(matrix, n, n - 1, n - 1) << endl;

    return 0;
}