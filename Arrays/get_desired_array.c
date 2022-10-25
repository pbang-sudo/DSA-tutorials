// Only two operations can be performed on the array {0, 0}
// 1. Incremental Operation - Choose one element from the array and increment its value by 1
// 2. Doubling Opeartion - Double all the elements of the array.
// Count the minimum number of steps to get the desired array

/*
      For eg: {2,3} Target = 4
      {0,0} --> {1,0} --> {1,1} --> {2,2} --> {2,3}
      2 consecutive increment operation
      1 doubling operation
      1 increment operation to get the last element to 3
*/

#include <stdio.h>
#include <stdlib.h>

int countSteps(int *arr, int n, int target)
{
      int result = 0;
      while (result <= target)
      {
            int zero_count = 0;
            int i, j;
            for (i = 0; i < n; i++)
            {
                  if (arr[i] & 1) // If odd number found
                        break;

                  else if (arr[i] == 0) // If found 0 the increment zero count
                        zero_count++;

                  else if (zero_count == n) // If all elements are zero then return the result
                        return result;

                  if (i == n)
                  { // All numbers are even
                        for (j = 0; j < n; j++)
                              arr[i] = arr[i] / 2;
                        result++;
                  }

                  for (j = i; j < n; j++)
                  {
                        if (arr[j] & 1)
                        {
                              arr[j] -= 1;
                              result++;
                        }
                  }
            }
      }
      return result;
}

int main()
{
      int n;
      scanf("%d", &n);
      int *arr = (int *)malloc(n * sizeof(int));
      int i;
      for (i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }
      int target, result = 0;
      scanf("%d", &target);

      if (target == countSteps(arr, n, target))
            printf("POSSIBLE %d\n", target);
      else
            printf("NOT POSSIBLE\n");

      return 0;
}