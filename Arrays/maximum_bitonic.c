#include <stdio.h>
#include <stdlib.h>

int max_bitonic_subarray(int arr[], int n);

int main()
{
      int n;
      scanf("%d", &n);
      int arr[n], i;

      for (i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }

      printf("%d", max_bitonic_subarray(arr, n));

      return 0;
}

int max_bitonic_subarray(int arr[], int n)
{
      int inc[n], dec[n], max, i;

      inc[0] = 1;
      dec[n - 1] = 1;

      for (i = 1; i < n; i++)
            inc[i] = (arr[i] > arr[i - 1]) ? inc[i - 1] + 1 : 1;

      for (i = n - 2; i > -1; i--)
            dec[i] = (arr[i] > arr[i + 1]) ? dec[i + 1] + 1 : 1;

      max = inc[0] + dec[0] - 1;

      for (i = 0; i < n; i++)
      {
            if (inc[i] + dec[i] - 1 > max)
                  max = inc[i] + dec[i] - 1;
      }

      return max;
}