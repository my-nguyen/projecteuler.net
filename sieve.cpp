#include "sieve.h"
#include <iostream>
using namespace std;

// the 20th prime is 71, the 200th prime is 1,223, the 2,000th prime is
// 17,389, the 20,000th prime is 224,737, the 200,000th prime is 2,750,159,
// and the 2,000,000th prime is 32,452,843 so the ratio of natural to prime
// is roughly 17. round this ratio up to 20.
const int NATURAL_2_PRIME = 20;
// This constructor fills an array of bools up to a certain size, with prime
// numbers marked as ON bit and non-prime as OFF
sieve_t::sieve_t(int number) : field(number * NATURAL_2_PRIME), position(number)
{
  // initialize all bits to ON
  field.set();

  // numbers 0 and 1 are not primes
  field.reset(0);
  field.reset(1);

  // start with 2, the very first prime number
  for (int i = 2; i < field.size(); i++)
  {
    // test whether bit at i is ON
    if (field.test(i))
    {
      int multiple = 2;
      while (i*multiple < field.size())
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        field.reset(i*multiple);
        multiple += 1;
      }
    }
  }
}

// this method returns the natural number of the prime number at index. for
// example, for the prime number at 100, it returns 541. for the prime number
// at 1000, it returns 7919. for the prime number at 5000, it returns 48611.
unsigned long sieve_t::index()
{
  // index to the entire bool array
  unsigned long i = 1;
  // index only up to target
  int j = 0;
  while (j < position)
  {
    i += 1;
    if (field.test(i))
      j += 1;
  }
  return i;
}

// this method returns the sum of all the prime numbers within the bools array
unsigned long sieve_t::sum()
{
  unsigned long sum = 0;
  // iterate the entire bitfield
  int i;
  for (i = 0; i < field.size(); i++)
    if (field.test(i))
      sum += i;
  return sum;
}
