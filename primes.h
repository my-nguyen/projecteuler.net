#ifndef PRIMES_T_H
#define PRIMES_T_H

struct array_t
{
  void* data;
  int count;
};
typedef struct array_t array_t;

// This type represents a set of primes up to a given number (space)
// bools is an array of true/false elements where true elements represent prime
// numbers and false elements represent non-prime numbers. this array is created
// via initialize()
// packed is an array of prime numbers extracted from bools. this array is
// created via pack()
struct primes_t
{
  array_t bools;
  array_t packed;
};
typedef struct primes_t primes_t;

// the name initialize() implies that this works like a C++ constructor
void initialize(primes_t* primes, int space);

array_t pack(primes_t* primes);

// the name destroy() implies this works like a C++ destructor
void destroy(primes_t* primes);

#endif
