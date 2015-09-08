// Summation of primes
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// The Sieve of Eratosthenes algorithm developed in Euler #7 was used here to
// yield marvelous result:
//
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
