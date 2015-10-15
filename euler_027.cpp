#include <iostream>
#include "sieve.h"
using namespace std;

int main()
{
  // n*n + a*n + b
  // where n < 80, a < 1000 and b < 1000. so max of that expression is
  // 80*80 + 1000*80 + 1000 = 87400
  Sieve primes(87400);
  int max_a = 0;
  int max_b = 0;
  // currently we know n = 40 when a = 1 and b = 41
  int max_n = 40;
  // iterate over all possibilities for a
  for (int a = -999; a <= 999; a++)
    // iterate over all possibilities for b
    for (int b = -999; b <= 999; b++)
    {
      // look for a series of consecutive primes starting with n = 0
      int n = 0;
      while (primes.is_prime(abs(n*n + a*n + b)))
        n += 1;

      // did we find a bigger series than the current one?
      if (n > max_n)
      {
        max_a = a;
        max_b = b;
        max_n = n;
      }
    }

  cout << "a: " << max_a << ", b: " << max_b << ", n: " << max_n << ", product: " << (max_a*max_b) << endl;
}
