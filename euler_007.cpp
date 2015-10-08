#include <iostream>
#include <boost/dynamic_bitset.hpp>
using namespace std;
using namespace boost;

bool worst_prime(int number)
{
  if (number == 2)
    return true;
  // only consider odd divisors from 3 up to half the test number
  for (int i = 3; i < number/2; i += 2)
    if (number % i == 0)
      return false;
  return true;
}

int worst_index(int position)
{
  // only consider numbers greater than 3
  int result = 3;
  // first two prime numbers (2 and 3) are already accounted for
  int incr = 2;
  while (incr < position)
  {
    // only consider odd numbers
    result += 2;
    if (worst_prime(result))
      incr += 1;
  }
  return result;
}

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number. This algorithm proves to be a vast improvement on my
// older prime-finding algorithm: while the older version took 13 seconds,
// this new version took less than 1 second.
// This constructor fills an array of bools from 2 to order, with prime
// numbers marked as ON bit and non-prime as OFF
dynamic_bitset<> sieve_init(int position)
{
  // the 100th prime is 541, the 1000th prime is 7919, the 10000th prime is
  // 104729, the 100000th prime is 1299709 so size is roughly 13 times the
  // prime number/position
  dynamic_bitset<> field(position * 13);
  // initialize all bits to ON
  field.set();

  // numbers 0 and 1 are not primes
  field.reset(0);
  field.reset(1);

  // start with 2, the very first prime number
  for (int i = 2; i < field.size(); i++)
  {
    // test whether bit at i is ON
    if (field.test(i))
    {
      int multiple = 2;
      while (i*multiple < field.size())
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        field.reset(i*multiple);
        multiple += 1;
      }
    }
  }
  return field;
}

// this method returns the natural number of the prime number at position.
// for example, for prime at position 100, it returns 541. for prime at 1000,
// it returns 7919. for prime at 5000, it returns 48611.
int sieve_index(int position)
{
  dynamic_bitset<> field = sieve_init(position);
  // index to the entire bool array
  int result = 1;
  // index by prime numbers
  int j = 1;
  while (j < position)
  {
    result += 2;
    if (field.test(result))
      j += 1;
  }
  return result;
}

bool sieve2_prime(int number)
{
  if (number == 2)
    return true;
  if (number % 2 == 0)
    return false;
  int i = 3;
  while (i*i <= number)
  {
    if (number % i == 0)
      return false;
    i += 2;
  }
  return true;
}

int sieve2_index(int position)
{
  int result = 1;
  int j = 1;
  while (j < position)
  {
    result += 2;
    if (sieve2_prime(result))
      j += 1;
  }
  return result;
}

int sieve3_index(int position)
{
  vector<int> primes;
  primes.push_back(2);
  int result = 1;
  while (primes.size() < position)
  {
    // only consider odd numbers
    result += 2;
    bool found = true;
    // result = 3, primes = [2], j = 0, primes[0]*primes[0] > 3 ==> prime
    // result = 5, primes = [2, 3], j = 0, result%primes[0] == 1
    //                              j = 1, primes[1]*primes[1] > 5 ==> prime
    // result = 7, primes = [2, 3, 5], j = 0, result%primes[0] == 1
    //                                 j = 1, primes[1]*primes[1] > 7 ==> prime
    // result = 9, primes = [2, 3, 5, 7], j = 0, result%primes[0] == 1
    //                                    j = 1, result%primes[1] == 0 ==> not prime
    int j = 0;
    while (found && j < primes.size() && primes[j]*primes[j] <= result)
    {
      if (result % primes[j] == 0)
        found = false;
      j += 1;
    }

    if (found)
      primes.push_back(result);
  }
  return result;
}

int main()
{
  int targets[] = { 6, 11, 101, 1001, 10001, 50001 };
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Worst(" << targets[i] << "): " << worst_index(targets[i]) << endl;
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Sieve(" << targets[i] << "): " << sieve_index(targets[i]) << endl;
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Modified Sieve(" << targets[i] << "): " << sieve2_index(targets[i]) << endl;
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Improved Sieve(" << targets[i] << "): " << sieve3_index(targets[i]) << endl;
}
