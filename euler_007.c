#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h> // memset(), memcpy()
#include "primes.h"

void main()
{
  struct target_t
  {
    int prime; // which prime number to get to
    int space; // how much space is needed to cover the prime number
  };
  typedef struct target_t target_t;

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
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(target_t); i++)
  {
    // First, obtain all prime numbers up to space. The prime numbers are ON bits
    // while the non-prime numbers are OFF bits.
    primes_t primes;
    initialize(&primes, targets[i].space);

    printf("prime(%d): %lu\n", targets[i].prime, idx(&primes, targets[i].prime));

    // Lastly, don't forget to free memory.
    destroy(&primes);
  }
}
