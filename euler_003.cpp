#include <iostream>
using namespace std;

long largest_prime(long target)
{
  long prime = 2;
  while (target > prime)
    // if target is divisible by the current prime, then keep dividing
    // target by the current prime
    if (target % prime == 0)
      target /= prime;
    // otherwise move on to the next number
    else
      prime += 1;
  return prime;
}

int main()
{
  long targets[] = {13915, 475143, 1475143, 51475143, 1851475143, 10851475143, 600851475143};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(long); i++)
    cout << "target: " << targets[i] << ", largest prime: " << largest_prime(targets[i]) << endl;
}
