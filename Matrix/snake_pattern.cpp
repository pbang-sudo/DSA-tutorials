#include <bits/stdc++.h>
using namespace std;

void snakePattern(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    for(int i = 0; i < r; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < c; j++)
            cout << mat[i][j] << "\t";
        }
        else {
            for(int j = c - 1; j > -1; j--)
            cout << mat[i][j] << "\t";
        }
        cout << endl;
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

    snakePattern(mat);
    return 0;
}