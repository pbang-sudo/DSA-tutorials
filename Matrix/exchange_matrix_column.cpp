// You are given a matrix of dimensions (n1 x m1). 
// You have to exchange its first column with the last column.
#include <bits/stdc++.h>
using namespace std;

void interchange(vector<vector<int>> &arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        swap(arr[i][0], arr[i][c - 1]);
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    interchange(mat, r, c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}