#include <iostream>
#include <vector>
using namespace std;

vector<int> leader(int *arr, int n)
{
    int i, leader = arr[n - 1];
    vector<int> lead;
    for (i = n - 2; i >= 0; i--)
    {
        if (leader < arr[i])
        {
            leader = arr[i];
            lead.push_back(leader);
        }
    }
    return lead;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ar = leader(arr, n);
    int length = ar.size();
    for (int i = length - 1; i > -1; i--)
        cout << ar[i] << " ";

    cout << endl;

    return 0;
}