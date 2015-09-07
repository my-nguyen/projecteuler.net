// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
#include <stdio.h>
#include "primes.h"
#include "bitfield.h"

// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
void initialize(primes_t* primes, int size)
{
  init(&primes->_field, size);

  // numbers 0 and 1 are not primes
  clear(&primes->_field, 0);
  clear(&primes->_field, 1);

  // start with 2, the very first prime number
  int i;
  for (i = 2; i < size; i++)
  {
    // test whether bit at i is ON
    if (test(&primes->_field, i))
    {
      int multiple = 2;
      while (i*multiple <= size)
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        clear(&primes->_field, i*multiple);
        multiple += 1;
      }
    }
  }

  // print(&primes->_field);
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
    if (test(&primes->_field, i))
      j += 1;
  }
  return i;
}

void destroy(primes_t* primes)
{
  destruct(&primes->_field);
}
