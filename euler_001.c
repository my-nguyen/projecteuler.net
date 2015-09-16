// Refer to euler_001.rb for clarifying comments.
// Compile with gcc
#include <stdio.h>
#include "int_arrayc.h"

void main()
{
  int limits[] = {10, 20, 100, 500, 1000};
  int i;
  for (i = 0; i < sizeof(limits)/sizeof(int); i++)
  {
    int multiples[1000];
    int size = 0;

    int highest_3 = (limits[i]-1) / 3;
    int j;
    for (j = 1; j <= highest_3; j++)
      array_push(multiples, &size, (j*3));

    int highest_5 = (limits[i]-1) / 5;
    for (j = 1; j <= highest_5; j++)
      if (j % 3 != 0)
        array_push(multiples, &size, (j*5));

    array_sort(multiples, size);
    printf("limit: %d, sum: %d\n", limits[i], array_sum(multiples, size));
    // array_print(multiples, size);
  }
}
