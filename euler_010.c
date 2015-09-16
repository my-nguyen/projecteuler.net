#include <stdio.h>
#include "primes.h"

void main()
{
  int targets[] = {10, 100000, 500000, 1000000, 1500000, 2000000};
  // for some reason the program bombs when freeing memory when target is 1000000
  // int targets[] = {10, 100000, 500000, 1500000, 2000000};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    primes_t primes;
    initialize(&primes, targets[i]);

    printf("Sum primes(%d): %lu\n", targets[i], sum(&primes));

    // Lastly, don't forget to free memory.
    destroy(&primes);
  }
}
