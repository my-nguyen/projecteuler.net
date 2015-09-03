#include <stdio.h>
#include <math.h>
// compile with -lm

long sum_squares(int max)
{
  long sum = 0;
  int i;
  for (i = 1; i <= max; i++)
    sum += (long)pow(i, 2);
  return sum;
}

long square_sum(int max)
{
  long sum = 0;
  int i;
  for (i = 1; i <= max; i++)
    sum += i;
  return (long)pow(sum, 2);
}

void main()
{
  int targets[] = {10, 50, 100};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
    printf("Difference(%d): %ld\n", targets[i], square_sum(targets[i]) - sum_squares(targets[i]));
}
