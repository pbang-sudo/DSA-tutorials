/*
	Given three integers x, y, and z, the task is to find the sum of all the numbers formed by
	having 4 at most x times, having 5 at most y times, and having 6 at most z times as a digit.
*/

#include <bits/stdc++.h>
using namespace std;

int getSum(int X, int Y, int Z) {
	// Your code goes here
	if (X == 0 && Y == 0 && Z == 0) return 0;
	long long num[X + 1][Y + 1][Z + 1], sum[X + 1][Y + 1][Z + 1];
	long long ans = 0;
	int mod = pow(10, 9) + 7;
	for (int i = 0; i <= X; i++) {
		for (int j = 0; j <= Y; j++) {
			for (int k = 0; k <= Z; k++) {
				num[i][j][k] = 0;
				sum[i][j][k] = 0;
			}

		}

	}
	num[0][0][0] = 1LL;
	for (int i = 0; i < X + 1; i++) {
		for (int j = 0; j < Y + 1; j++) {
			for (int k = 0; k < Z + 1; k++) {
				if (i > 0) {
					sum[i][j][k] += (sum[i - 1][j][k] * 10 + 4 * num[i - 1][j][k]) % mod;
					num[i][j][k] += num[i - 1][j][k] % mod;
				}
				if (j > 0) {
					sum[i][j][k] += (sum[i][j - 1][k] * 10 + 5 * num[i][j - 1][k]) % mod;
					num[i][j][k] += num[i][j - 1][k] % mod;
				}
				if (k > 0) {
					sum[i][j][k] += (sum[i][j][k - 1] * 10 + 6 * num[i][j][k - 1]) % mod;
					num[i][j][k] += num[i][j][k - 1] % mod;
				}
				ans += sum[i][j][k] % mod;
				ans %=  mod;
			}
		}
	}
	return (int)ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x, y, z;
	cin >> x >> y >> z;

	cout << getSum(x, y, z);
	return 0;
}