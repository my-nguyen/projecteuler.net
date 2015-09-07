#ifndef PRIMES_CPP_H
#define PRIMES_CPP_H

#include <boost/dynamic_bitset.hpp>

// This type represents a set of primes up to a given number (space)
// bools is an array of true/false elements where true elements represent prime
// numbers and false elements represent non-prime numbers. this array is created
// via initialize()
class primes_t
{
public:
  primes_t(int space);

  unsigned long index(int position);

  ~primes_t() {}

private:
  boost::dynamic_bitset<> _field;
};

#endif
