#include <iostream>
using namespace std;

int *zFunction(string str, int n)
{
    int *z = new int[n];
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = i;
            r = i;
            while (r < n && str[r - l] == str[r])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else
        {
            int j = i - l;
            if (z[j] < r - i + 1)
            {
                z[i] = z[j];
            }
            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    return z;
}

int getPivot(int *z, int n) {
    int pos = 1, count = 0, currCount = 0;
    for(int i = 1; i < n; i++) {
        if(z[i] == 0) {
            count++;
            pos = i;
        }
        else {
            currCount = max(count, currCount);
            pos -= count;
            count = 0;
        }
        //pos -= currCount;
    }
    return pos;
}

int main()
{
    string str = "amanaplanacanal";
    // cin >> str;
    int n = str.size();
    int *z = zFunction(str, n);

    cout << getPivot(z, n) << endl;
    
    // for(auto i : str)
    //     cout << i << " ";
    // cout << endl;
    // cout << "  ";
    // for (int i = 1; i < n; i++)
    //     cout << z[i] << " ";
    // cout << endl;
    return 0;
}