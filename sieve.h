#ifndef PRIMES_H
#define PRIMES_H

#include <boost/dynamic_bitset.hpp>
using namespace boost;

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number.
class sieve_t
{
public:
  sieve_t(int position);

  unsigned long index();

  unsigned long sum();

private:
  dynamic_bitset<> field;
  int position;
};

#endif
