// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // memcpy()
#include "primes.h"
#include "bitfield.h"

// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
void initialize(primes_t* primes, int space)
{
  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  int long_count = (space/BITS_PER_LONG) + ((space%BITS_PER_LONG) ? 1 : 0);
  int byte_count = long_count * sizeof(long);
  primes->data = malloc(byte_count);
  primes->count = space;
  // printf("space required: %d, which fits in %d long's, or %ld bits\n", space, long_count, (long_count*BITS_PER_LONG));

  // initialize all bits to ON
  memset(primes->data, 0xFF, byte_count);

  // numbers 0 and 1 are not primes
  bitfield_clear(primes->data, 0);
  bitfield_clear(primes->data, 1);

  // start with 2, the very first prime number
  int i;
  for (i = 2; i < space; i++)
  {
    // test whether bit at i is ON
    if (bitfield_test(primes->data, i))
    {
      int multiple = 2;
      while (i*multiple <= space)
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        bitfield_clear(primes->data, i*multiple);
        multiple += 1;
      }
    }
  }

  // bitfield_print(primes->data, long_count);
}

// there's no need to create another array that contains only prime numbers
// extracted from the array of bools: Just look in the array of bools for the
// prime number at position.
// must name the method "idx" since gcc doesn't like the word "index"
unsigned long idx(primes_t* primes, int position)
{
  // index to the entire bool array
  unsigned long i = 1;
  // index only up to target
  int j = 0;
  while (j < position)
  {
    i += 1;
    if (bitfield_test(primes->data, i))
      j += 1;
  }
  return i;
}

void destroy(primes_t* primes)
{
  free(primes->data);
}
