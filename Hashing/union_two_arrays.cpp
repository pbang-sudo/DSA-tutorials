#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(a[i]);
        for(int j = 0; j < m; j++)
            s.insert(b[j]);
        return s.size();
    }

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int j = 0; j < m; j++)
        cin >> b[j];
    
    cout << doUnion(a, n, b, m) << endl;
    return 0;
}