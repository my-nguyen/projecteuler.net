#ifndef PRIMES_H
#define PRIMES_H

#include <boost/dynamic_bitset.hpp>
using namespace boost;

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number.
class Sieve
{
public:
  Sieve(int size);

  unsigned long index(int position);

  unsigned long sum();

  bool is_prime(int number) { return field.test(number); }

private:
  dynamic_bitset<> field;
};

#endif
