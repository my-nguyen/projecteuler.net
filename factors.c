#include <stdio.h>
#include <math.h>
#include <string.h>

// find all factors of a target number
void find_factors(int number, int factors[], int* size)
{
  // 1 is always a divisor
  factors[(*size)++] = 1;
  if (number > 1)
  {
    // number is also always a divisor
    factors[(*size)++] = number;
    // start looking for other factors from 2 on up.
    int i = 2;
    while (i <= sqrt(number))
    {
      // if number is evenly divisible by i, then retain i, and possibly also
      // the division of number/i.
      if (number % i == 0)
      {
        factors[(*size)++] = i;
        if (i != number/i)
          factors[(*size)++] = number/i;
      }
      i += 1;
    }
    // factors.sort!
  }
}

char* tostring(int array[], int size, char* string)
{
  strcpy(string, "[");
  int i;
  for (i = 0; i < size; i++)
  {
    if (i)
      strcat(string, " ");
    sprintf(string+strlen(string), "%d", array[i]);
  }
  strcat(string, "]");
  return string;
}
void main()
{
  int targets[] = {8051, 10403};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    int factors[1000];
    int size = 0;
    find_factors(targets[i], factors, &size);
    char string[1000];
    printf("FACTORS of %d: %s\n", targets[i], tostring(factors, size, string));
  }
}
