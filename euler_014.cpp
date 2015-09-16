#include <iostream>
using namespace std;

#define MAX_NUMBER 1000000

// this method returns the next number in the Collatz sequence. must use long
// instead of int here, since the calculation could turn a positive integer
// into a negative one.
long next(long current)
{
  return (current % 2 == 0) ? current/2 : (3*current + 1);
}

// this method returns the length of the sequence started with number. there's
// no need to retain the integers that form the sequence, just return the length
int sequence(long number)
{
  int length = 0;
  while (number != 1)
  {
    length++;
    number = next(number);
  }
  return length;
}

int main()
{
  int max_index = 0;
  int max_sequence = 0;

  // only start retaining Collatz sequences at 2
  for (int i = 2; i < MAX_NUMBER; i++)
  {
    int length = sequence(i);
    if (length > max_sequence)
    {
      max_index = i;
      max_sequence = length;
      cout << "number: " << i << ", length: " << length << endl;
    }
  }
}
