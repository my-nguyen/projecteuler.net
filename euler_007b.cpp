// Euler 7, in C++, version C: replaced user-defined class bitfield with
// boost::dynamic_bitset
#include <iostream>
#include <vector>
#include <boost/dynamic_bitset.hpp>
using namespace std;

void bitset_print(const boost::dynamic_bitset<>& field)
{
  for (int i = 0; i < field.size(); i++)
    cout << field[i];
  cout << endl;
}

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
void get_primes(boost::dynamic_bitset<>* field)
{
  // numbers 0 and 1 are not primes
  field->reset(0);
  field->reset(1);

  // start with 2, the very first prime number
  for (int i = 2; i < field->size(); i++)
  {
    // test whether bit at i is ON
    if (field->test(i))
    {
      int multiple = 2;
      while (i*multiple < field->size())
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        field->reset(i*multiple);
        multiple += 1;
      }
    }
  }
}

// this method converts an array of booleans, where ON elements represent prime
// numbers and OFF otherwise, into an array of prime numbers
void pack_primes(const boost::dynamic_bitset<>& field, vector<int>* primes)
{
  for (int i = 0; i < field.size(); i++)
    if (field.test(i))
      primes->push_back(i);
}

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
    boost::dynamic_bitset<> field(targets[i].space);
    // initialize all bits to ON
    field.set();
    get_primes(&field);

    // Next, extract those ON bits into another array of prime numbers
    vector<int> primes;
    pack_primes(field, &primes);

    cout << "found " << primes.size() << " prime numbers below " << targets[i].space << endl;
    // array_print(primes, prime_count);
    cout << "the " << targets[i].prime << "th prime number is " << primes[targets[i].prime-1] << endl;
    cout << "**********************************************" << endl;
  }
}
