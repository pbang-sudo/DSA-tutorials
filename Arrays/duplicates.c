#include <stdio.h>
#include <stdlib.h>

int main()
{
      int n;
      scanf("%d", &n);
      int arr[n], i;

      for (i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }

      for (i = 0; i < n; i++)
      {
            if (arr[abs(arr[i])] >= 0)
                  arr[abs(arr[i])] = -arr[abs(arr[i])];
            else
                  printf("%d ", abs(arr[i]));
      }

      return 0;
}