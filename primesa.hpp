#ifndef PRIMES_CPP_H
#define PRIMES_CPP_H

#include "bitfield.hpp"

// This type represents a set of primes up to a given number (space)
// While bitfield_t which is dedicated to bit manipulation (set(), clear(), test(),
// etc) only, primes_t is used to operate on a whole bitfield, such as index(),
// sum()
class primes_t
{
public:
  primes_t(int space);

  unsigned long index(int position);

  unsigned long sum();

  ~primes_t() {}

private:
  bitfield_t _field;
};

#endif
