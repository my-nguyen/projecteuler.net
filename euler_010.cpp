#include <iostream>
#include "sieve.h"
using namespace std;

int main()
{
  int targets[] = {10, 100000, 500000, 1000000, 1500000, 2000000};
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    Sieve primes(targets[i]);
    cout << "Sum primes(" << targets[i] << "): " << primes.sum() << endl;
  }
}
