#include <bits/stdc++.h>
using namespace std;

// Naive
/*long long int inversionCount(long long arr[], long long n) {
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j])
                count++;
        }
    }
    return count;
}*/

// Efficient approach (using merge sort)
long long int countAndMerge(long long arr[], long long l, long long m, long long r) {
    long long n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    long long left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    
    long long res = 0, i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
            res += n1 - i;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

long long int countInv(long long arr[], long long l, long long r) {
    long long res = 0;
    if(l < r) {
        long long m = (l + r) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

long long int inversionCount(long long arr[], long long n) {
    return countInv(arr, 0, n - 1);
}

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << inversionCount(arr, n);
}