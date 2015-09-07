// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // memcpy()
#include "primesa.hpp"

// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
primes_t::primes_t(int space) : _field(space)
{
  // initialize all bits to ON
  memset(_field.data(), 0xFF, _field.long_count()*sizeof(long));

  // numbers 0 and 1 are not primes
  _field.clear(0);
  _field.clear(1);

  // start with 2, the very first prime number
  for (int i = 2; i < space; i++)
  {
    // test whether bit at i is ON
    if (_field.test(i))
    {
      int multiple = 2;
      while (i*multiple <= space)
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        _field.clear(i*multiple);
        multiple += 1;
      }
    }
  }

  // field.print();
}

// there's no need to create another array that contains only prime numbers
// extracted from the array of bools: Just look in the array of bools for the
// prime number at position.
unsigned long primes_t::index(int position)
{
  // index to the entire bool array
  unsigned long i = 1;
  // index only up to target
  int j = 0;
  while (j < position)
  {
    i += 1;
    if (_field.test(i))
      j += 1;
  }
  return i;
}
