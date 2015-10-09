#include <iostream>
#include <vector>
#include "sieve.h"
using namespace std;

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
    // result = 3, primes = [2], j = 0, primes[0]*primes[0] > 3 => 3 is prime
    // result = 5, primes = [2, 3], j = 0, result%primes[0] == 1
    //                              j = 1, primes[1]*primes[1] > 5 => 5 is prime
    // result = 7, primes = [2, 3, 5], j = 0, result%primes[0] == 1
    //                                 j = 1, primes[1]*primes[1] > 7 => 7 is prime
    // result = 9, primes = [2, 3, 5, 7], j = 0, result%primes[0] == 1
    //                                    j = 1, result%primes[1] == 0 ==> 9 is not prime
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
  int sizes[] = { 20, 40, 600, 8000, 105000, 612000 };
  /*
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Worst(" << targets[i] << "): " << worst_index(targets[i]) << endl;
  */
  for (int i = 0; i < sizeof(sizes)/sizeof(int); i++)
  {
    sieve_t sieve(sizes[i]);
    cout << "Sieve(" << targets[i] << "): " << sieve.index(targets[i]) << endl;
  }
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Modified Sieve(" << targets[i] << "): " << sieve2_index(targets[i]) << endl;
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Improved Sieve(" << targets[i] << "): " << sieve3_index(targets[i]) << endl;
}
