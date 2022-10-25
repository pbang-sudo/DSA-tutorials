#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> transpose(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}

	reverse(transpose.begin(), transpose.end());
	for (auto& i : transpose) {
		for (auto& j :  i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}