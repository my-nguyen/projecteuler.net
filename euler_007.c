#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h> // memset(), memcpy()
// #include "int_arrayc.h" // only needed for debugging
#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(long)*BITS_PER_BYTE)

// This method converts a long integer in decimal base to a binary string.
char* decimal2binary(long decimal, char binary[])
{
  int i = 0;
  for (i = 0; i < BITS_PER_LONG; i++)
  {
    binary[i] = (decimal & 1 ? '1' : '0');
    decimal >>= 1;
  }
  return binary;
}

// this method prints out all 64 bits in an unsigned long bitfield
void bitfield_print(unsigned long field)
{
  char binary[BITS_PER_LONG+1];
  binary[BITS_PER_LONG] = '\0';
  printf("%s\n", decimal2binary(field, binary));
}

// all the bit operations below were lifted from
// stackoverflow.com/questions/2525310/how-to-define-and-work-with-an-array-of-bits-in-c
int byte_index(int long_index)
{
  return long_index / BITS_PER_LONG;
}

int bit_index(int long_index)
{
  return long_index % BITS_PER_LONG;
}

// this method clears a bit at a given index
void bitfield_clear(unsigned long field[], int long_index)
{
  // literal 1 is an int which is 32 bits. the shift (<<) and complement (~)
  // will yield inaccurate results for a 32-bit integer. Thus a long literal 1l
  // is used instead because it's 64 bits.
  field[byte_index(long_index)] &= ~(1l << bit_index(long_index));
}

// this method sets a bit at a given index
void bitfield_set(unsigned long field[], int long_index)
{
  field[byte_index(long_index)] |= (1l << bit_index(long_index));
}

// this method tests whether a bit is on at a given index
// return type needs to be unsigned long instead of int, for reason similar
// to that in bitfield_clear()
unsigned long bitfield_test(unsigned long field[], int long_index)
{
  return field[byte_index(long_index)] & (1l << bit_index(long_index));
}

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
unsigned long* get_primes(int space)
{
  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  int long_count = (space/BITS_PER_LONG) + ((space%BITS_PER_LONG) ? 1 : 0);
  int byte_count = long_count * sizeof(long);
  unsigned long* primes = (unsigned long*)malloc(byte_count);
  printf("space required: %d, which fits in %d long's, or %ld bits\n", space, long_count, (long_count*BITS_PER_LONG));

  // initialize all bits to ON
  memset(primes, 0xFF, byte_count);

  // numbers 0 and 1 are not primes
  bitfield_clear(primes, 0);
  bitfield_clear(primes, 1);

  // start with 2, the very first prime number
  int i;
  for (i = 2; i < space; i++)
  {
    // test whether bit at i is ON
    if (bitfield_test(primes, i))
    {
      int multiple = 2;
      while (i*multiple <= space)
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        bitfield_clear(primes, i*multiple);
        multiple += 1;
      }
    }
  }
  return primes;
}

// this method converts an array of booleans, where ON elements represent prime
// numbers and OFF otherwise, into an array of prime numbers
void pack_primes(unsigned long* bools, int bool_count, int** primes, int* prime_count)
{
  // 105000 currently accommodates up to the biggest test prime number: 10001
  // so it covers all the smaller test prime numbers.
  int tmp[105000];
  *prime_count = 0;
  int i = 0;
  for (i = 0; i < bool_count; i++)
    if (bitfield_test(bools, i))
    {
      tmp[*prime_count] = i;
      *prime_count += 1;
    }

  *primes = (int*)malloc(*prime_count * sizeof(int));
  memcpy(*primes, tmp, (*prime_count * sizeof(int)));
}

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
    unsigned long* bools = get_primes(targets[i].space);

    // Next, extract those ON bits into another array of prime numbers
    int* primes;
    int prime_count;
    pack_primes(bools, targets[i].space, &primes, &prime_count);

    printf("found %d prime numbers below %d\n", prime_count, targets[i].space);
    // array_print(primes, prime_count);
    printf("the %dth prime number is %d\n", targets[i].prime, primes[targets[i].prime-1]);
    printf("**********************************************\n");

    // Lastly, don't forget to free memory.
    free(primes);
    free(bools);
  }
}
