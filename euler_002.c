#include <stdio.h>
#include "int_arrayc.h"

void main()
{
  int limits[] = {10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000};
  int i;
  for (i = 0; i < sizeof(limits)/sizeof(int); i++)
  {
    int fibs[40];
    fibs[0] = 1;
    fibs[1] = 2;
    int size = 2;

    int fib;
    while ((fib = fibs[size-2] + fibs[size-1]) < limits[i])
      array_push(fibs, &size, fib);

    int sum = 0;
    int j;
    for (j = 0; j < size; j++)
      if (fibs[j] % 2 == 0)
        sum += fibs[j];

    printf("limit: %d, sum: %d\n", limits[i], sum);
    // array_print(fibs, size);
  }
}
