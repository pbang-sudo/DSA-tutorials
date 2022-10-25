#include <iostream>
#include <vector>
using namespace std;

void printSequence(vector<int> arr)
{
    for (auto& it : arr)
        cout << it << " ";
    cout << endl;
}

void getSubsequence(int index, vector<int> arr, int k, int sum, int *source, int n)
{
    if (index == n)
    {
        if (k == sum)
            printSequence(arr);
        return;
    }
    arr.push_back(source[index]);
    sum += source[index];
    getSubsequence(index + 1, arr, k, sum, source, n);
    sum -= source[index];
    arr.pop_back();
    getSubsequence(index + 1, arr, k, sum, source, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    cout << endl;
    getSubsequence(0, ar, k, 0, arr, n);

    return 0;
}