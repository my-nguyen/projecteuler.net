#include <iostream>
#include <vector>
using namespace std;

// this method returns the greatest common divisor of 2 integers
long gcd(long one, long two)
{
  while (one != 0)
  {
    long tmp = one;
    one = two % one;
    two = tmp;
  }
  return two;
}

// this method returns the least common multiple of 2 integers
// must declare parameter type and return type as long; otherwise an overflow
// would occur at one * two when one becomes too large.
long lcm(long one, long two)
{
  return (one * two) / gcd(one, two);
}

// this method returns the least common multiple of an array of more than 2 integers
long my_algorithm(int size)
{
  long multiple = 2;
  for (int i = 3; i <= size; i++)
    multiple = lcm(multiple, i);
  return multiple;
}

long brute_force(int size)
{
  int i = size;
  int j = 0;
  while (j <= size)
  {
    i += size;
    j = 2;
    while (j <= size)
      if (i % j != 0)
        break;
      else
        j += 1;
  }
  return i;
}

int main()
{
  int sizes[] = { 5, 10, 15, 20 };
  for (int i = 0; i < sizeof(sizes)/sizeof(int); i++)
  {
    cout << "My algorithm(" << sizes[i] << "): " << my_algorithm(sizes[i]) << endl;
    cout << "Brute force(" << sizes[i] << "): " << brute_force(sizes[i]) << endl;
  }
}
