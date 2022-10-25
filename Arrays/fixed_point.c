#include <stdio.h>
#include <stdbool.h>

int main()
{
      int n;
      scanf("%d", &n);
      bool found = false;
      int counter = 0, value;
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &value);
            if (value == counter)
            {
                  printf("%d", value);
                  found = true;
                  break;
            }
            counter++;
      }

      if (!found)
            printf("-1");
      return 0;
}