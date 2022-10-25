// Put 'n' items with given weight and value in a knapsack of capacity W to get the maximum of the total value in knapsack
#include <iostream>
using namespace std;

int maximumValue(int value[], int weight[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
        return 0;

    if (weight[n - 1] > capacity)
        return maximumValue(value, weight, n - 1, capacity);

    return max(maximumValue(value, weight, n - 1, capacity - weight[n - 1]) + value[n - 1],
               maximumValue(value, weight, n - 1, capacity));
}

int main()
{
    int n;
    cin >> n;
    int value[n], weight[n];

    cout << "Enter (Value  Weight):\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
    }

    cout << "Capacity: ";
    int capacity;
    cin >> capacity;

    cout << maximumValue(value, weight, n, capacity) << endl;

    return 0;
}