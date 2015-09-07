// Euler 7, in C++, version C: replaced user-defined class bitfield with
// boost::dynamic_bitset
#include <iostream>
#include <vector>
#include "primesb.hpp"

using namespace std;

int main()
{
  struct target_t
  {
    int prime; // which prime number to get to
    int space; // how much space is needed to cover the prime number
  };

  target_t targets[] =
  {
    { 6, 20 },        // 6th prime is 13, round-up space is 20
    { 11, 50 },       // 11th prime is 31, round-up space is 50
    { 101, 600 },     // 101th prime is 547, round-up space is 600
    { 1001, 8100 },   // 1001st prime is 7927
    { 2001, 17500 },  // 10001st prime is 17393
    { 3001, 27600 },  // 10001st prime is 27457
    { 4001, 38000 },  // 10001st prime is 37831
    { 5001, 48800 },  // 10001st prime is 48619
    { 6001, 59500 },  // 10001st prime is 59369
    { 7001, 70800 },  // 10001st prime is 70663
    { 8001, 82000 },  // 10001st prime is 81817
    { 9001, 93300 },  // 10001st prime is 93187
    { 10001, 105000 } // 10001st prime is 104743
  };

  for (int i = 0; i < sizeof(targets)/sizeof(target_t); i++)
  {
    // First, obtain all prime numbers up to space. The prime numbers are ON bits
    // while the non-prime numbers are OFF bits.
    primes_t primes(targets[i].space);

/*
    cout << "found " << primes.size() << " prime numbers below " << targets[i].space << endl;
    // array_print(primes, prime_count);
    cout << "the " << targets[i].prime << "th prime number is " << primes[targets[i].prime-1] << endl;
    cout << "**********************************************" << endl;
*/
    cout << "prime(" << targets[i].prime << "): " << primes.index(targets[i].prime) << endl;
  }
}
