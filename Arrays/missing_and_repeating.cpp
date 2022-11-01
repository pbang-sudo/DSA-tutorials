#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *A, int n)
{
	// code here
	long long int len = n;

	long long int S = (len * (len + 1)) / 2;
	long long int P = (len * (len + 1) * (2 * len + 1)) / 6;
	long long int missingNumber = 0, repeating = 0;

	for (int i = 0; i < n; i++)
	{
		S -= (long long int)A[i];
		P -= (long long int)A[i] * (long long int)A[i];
	}

	missingNumber = (S + P / S) / 2;

	repeating = missingNumber - S;

	int *ans = new int[2];

	ans[0] = repeating;
	ans[1] = missingNumber;

	return ans;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << findTwoElement(arr, n) << endl;
}