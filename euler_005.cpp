#include <iostream>
using namespace std;

// greatest common divisor of 2 integers
int gcd(int one, int two)
{
  while (one != 0)
  {
    int tmp = one;
    one = two % one;
    two = tmp;
  }
  return two;
}

// least common multiple of 2 integers
// must declare type of parameter one and return as long; otherwise an overflow
// would occur at one * two when one becomes too large.
long lcm(long one, int two)
{
  return (one * two) / gcd(one, two);
}

// least common multiple of an array of more than 2 integers
long lcm_array(int array[], int size)
{
  long multiple = lcm(array[0], array[1]);
  for (int i = 2; i < size; i++)
    multiple = lcm(multiple, array[i]);
  return multiple;
}

int main()
{
  int array[20];
  for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    array[i] = i+1;

  // test with different sizes
  int sizes[] = {5, 10, 15, 20};
  for (int j = 0; j < sizeof(sizes)/sizeof(int); j++)
    cout << "LCM(1.." << sizes[j] << "): " << lcm_array(array, sizes[j]) << endl;
}
