#include <stdio.h>
#include <stdlib.h>

int findPeak(int *arr, int low, int high, int n);

int main()
{
      int n;
      scanf("%d", &n);
      int *arr = (int *)malloc(n * sizeof(int));
      int n;

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }

      printf("%d", arr[findPeak(arr, 0, n - 1, n)]);

      return 0;
}

int findPeak(int *arr, int low, int high, int n)
{
      int mid = low + (high - low) / 2;
      if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
      else if (mid > 0 && arr[mid - 1] > arr[mid])
            return findPeak(arr, low, mid - 1, n);
      else
            return findPeak(arr, mid + 1, high, n);
}