#ifndef PRIMES_H
#define PRIMES_H

#include <boost/dynamic_bitset.hpp>
using namespace boost;

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number.
class sieve_t
{
public:
  sieve_t(int size);

  unsigned long index(int position);

  unsigned long sum();

private:
  dynamic_bitset<> field;
};

#endif
