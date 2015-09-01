#include "int_arrayp.h"

int main()
{
  int limits[] = {10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000};
  for (int i = 0; i < sizeof(limits)/sizeof(int); i++)
  {
    int_array fibs;
    fibs.push(1);
    fibs.push(2);

    int fib;
    while ((fib = fibs[fibs.size()-2] + fibs[fibs.size()-1]) < limits[i])
      fibs.push(fib);

    int sum = 0;
    for (int j = 0; j < fibs.size(); j++)
      if (fibs[j] % 2 == 0)
        sum += fibs[j];

    cout << "limit: " << limits[i] << ", sum: " << sum << endl;
    // cout << fibs;
  }
}
