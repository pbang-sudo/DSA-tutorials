#include <bits/stdc++.h>
using namespace std;

// Naive
/*int maxPoints(vector<vector<int>> &task, int day, int last) {
	int mPoints = 0;
	if (day == 0) {
		for (int i = 0; i < 3; i++) {
			if (i != last)
				mPoints = max(mPoints, task[day][i]);
		}
		return mPoints;
	}
	for (int i = 0; i < 3; i++) {
		if (i != last) {
			int points = task[day][i] + maxPoints(task, day - 1, i);
			mPoints = max(mPoints, points);
		}
	}
	return mPoints;
}*/

// Memoization
/*
int maxPoints(vector<vector<int>> &task, vector<vector<int>> &dp, int day, int last) {
	int mPoints = 0;
	if (day == 0) {
		for (int i = 0; i < 3; i++) {
			if (i != last)
				mPoints = max(mPoints, task[day][i]);
		}
		return mPoints;
	}
	if (dp[day][last] != -1) return dp[day][last];
	for (int i = 0; i < 3; i++) {
		if (i != last) {

			int points = task[day][i] + maxPoints(task, dp, day - 1, i);
			mPoints = max(mPoints, points);
		}
	}
	return dp[day][last] = mPoints;
}
*/

// Tabulation
/*
int maxPoints(vector<vector<int>> &points, int n) {
	vector<vector<int>> dp(n, vector<int>(4, -1));
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day = 1; day < n; day++) {
		for (int last = 0; last < 4; last++) {
			dp[day][last] = 0;
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					int point = points[day][task] + dp[day - 1][task];
					dp[day][last] = max(dp[day][last], point);
				}
			}
		}
	}
	return dp[n - 1][3];
}*/

// Space Optimization
int maxPoints(vector<vector<int>> &points, int n) {
	vector<int>prev(4, 0);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day = 1; day < n; day++) {
		vector<int> temp(4, 0);
		for (int last = 0; last < 4; last++) {
			temp[last] = 0;
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					temp[last] = max(temp[last], points[day][task] + prev[task]);
				}
			}
		}
		prev = temp;
	}
	return prev[3];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, value;
	cin >> n;
	vector<vector<int>> task(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> value;
			task[i].push_back(value);
		}
	}


	//cout << maxPoints(task, n - 1, 3);
	cout << maxPoints(task, n);
	return 0;
}