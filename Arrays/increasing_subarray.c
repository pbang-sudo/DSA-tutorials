#include <stdio.h>

int countSubarrays(int arr[], int n)
{
      int count = 0, len = 1, i;

      for (i = 0; i < n - 1; i++)
      {
            if (arr[i] < arr[i + 1])
                  len++;
            else
            {
                  count += len * (len - 1) / 2;
                  len = 1;
            }
      }

      if (len > 1)
            count += len * (len - 1) / 2;

      return count;
}

int main()
{
      int n;
      scanf("%d", &n);
      int arr[n], i;

      for (int i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }

      printf("%d", countSubarrays(arr, n));

      return 0;
}