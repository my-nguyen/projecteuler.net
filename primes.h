#ifndef PRIMES_C_H
#define PRIMES_C_H

#include "bitfield.h"

// This type represents a set of primes up to a given number (space)
// bools is an array of true/false elements where true elements represent prime
// numbers and false elements represent non-prime numbers. this array is created
// via initialize()
struct primes_t
{
  bitfield_t _field;
};
typedef struct primes_t primes_t;

void initialize(primes_t* primes, int size);

// extract the prime number at position
unsigned long idx(primes_t* primes, int position);

unsigned long sum(primes_t* primes);

void destroy(primes_t* primes);

#endif
