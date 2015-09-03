#include <iostream>
#include <cmath>
using namespace std;
// compile with -lm

long sum_squares(int max)
{
  long sum = 0;
  for (int i = 1; i <= max; i++)
    sum += (long)pow(i, 2);
  return sum;
}

long square_sum(int max)
{
  long sum = 0;
  for (int i = 1; i <= max; i++)
    sum += i;
  return (long)pow(sum, 2);
}

int main()
{
  int targets[] = {10, 50, 100};
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
    cout << "Difference(" << targets[i] << "): " << (square_sum(targets[i]) - sum_squares(targets[i])) << endl;
}
