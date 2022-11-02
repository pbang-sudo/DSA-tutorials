#include <bits/stdc++.h>
using namespace std;

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    int res = 0;
    for (int j = 0; j < m; j++)
    {
        if (s.find(b[j]) != s.end())
        {
            res++;
            s.erase(b[j]);
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int j = 0; j < m; j++)
        cin >> b[j];
    
    cout << NumberofElementsInIntersection(a, b, n, m) << endl;
    return 0;
}