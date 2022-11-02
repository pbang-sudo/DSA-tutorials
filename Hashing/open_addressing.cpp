#include <bits/stdc++.h>
using namespace std;

struct Hash
{
    /* data */
    int *arr;
    int capacity, size;
    Hash(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
        memset(arr, -1, sizeof(arr));
    }

    int hash(int key)
    {
        return key % capacity;
    }

    bool insert(int key);
    bool erase(int key);
    bool search(int key);
};

bool Hash::search(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
            return true;
        i = (i + 1) % capacity;
        if (i == h)
            return false;
    }
    return false;
}

bool Hash::insert(int key)
{
    if (size == capacity)
        return false;
    int i = hash(key);
    while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
    {
        i = (i + 1) % capacity;
    }
    if (arr[i] == key)
        return false;
    else
    {
        arr[i] = key;
        size++;
        return true;
    }
}

bool Hash::erase(int key) {
    int i = hash(key);
    int h = i;
    while(arr[i] != -1) {
        if(arr[i] == key) {
            arr[i] = -2;
            return true;
        }
        i = (i + 1) % capacity;
        if(i == h)
            return false;
    }
    return false;
}