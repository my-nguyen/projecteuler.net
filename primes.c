// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
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
  primes->bools.data = malloc(byte_count);
  primes->bools.count = space;
  // printf("space required: %d, which fits in %d long's, or %ld bits\n", space, long_count, (long_count*BITS_PER_LONG));

  // initialize all bits to ON
  memset(primes->bools.data, 0xFF, byte_count);

  // numbers 0 and 1 are not primes
  bitfield_clear(primes->bools.data, 0);
  bitfield_clear(primes->bools.data, 1);

  // start with 2, the very first prime number
  int i;
  for (i = 2; i < space; i++)
  {
    // test whether bit at i is ON
    if (bitfield_test(primes->bools.data, i))
    {
      int multiple = 2;
      while (i*multiple <= space)
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        bitfield_clear(primes->bools.data, i*multiple);
        multiple += 1;
      }
    }
  }
}

// this method converts an array of booleans, where ON elements represent prime
// numbers and OFF otherwise, into an array of prime numbers
array_t pack(primes_t* primes)
{
  // 105000 currently accommodates up to the biggest test prime number: 10001
  // so it covers all the smaller test prime numbers.
  int tmp[105000];
  primes->packed.count = 0;
  int i = 0;
  for (i = 0; i < primes->bools.count; i++)
    if (bitfield_test(primes->bools.data, i))
    {
      tmp[primes->packed.count] = i;
      primes->packed.count += 1;
    }

  primes->packed.data = malloc(primes->packed.count * sizeof(int));
  memcpy(primes->packed.data, tmp, (primes->packed.count * sizeof(int)));
  return primes->packed;
}

void destroy(primes_t* primes)
{
  free(primes->bools.data);
  free(primes->packed.data);
}
