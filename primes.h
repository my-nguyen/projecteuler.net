#ifndef PRIMES_T_H
#define PRIMES_T_H

// This type represents a set of primes up to a given number (space)
// bools is an array of true/false elements where true elements represent prime
// numbers and false elements represent non-prime numbers. this array is created
// via initialize()
struct primes_t
{
  unsigned long* data;
  int count;
};
typedef struct primes_t primes_t;

// the name initialize() implies that this works like a C++ constructor
void initialize(primes_t* primes, int space);

// extract the prime number at position
unsigned long idx(primes_t* primes, int position);

// the name destroy() implies this works like a C++ destructor
void destroy(primes_t* primes);

#endif
