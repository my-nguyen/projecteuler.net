#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000000;

void longest_sequence()
{
  int max_index = 0;
  int max_sequence = 0;

  // only start retaining Collatz terms at 2
  for (int index = 2; index <= MAX_NUMBER; index++)
  {
    int sequence = 1;
    long term = index;
    while (term != 1)
    {
      sequence += 1;
      // get the next number in the Collatz term. term needs to be of
      // type long; if it were of type int, then (3*term + 1) would
      // overflow the max integer
      term = (term % 2 == 0) ? term/2 : (3*term + 1);
    }

    if (sequence > max_sequence)
    {
      max_index = index;
      max_sequence = sequence;
      cout << "number: " << index << ", sequence: " << sequence << endl;
    }
  }
}

void caching()
{
  int max_index = 0;
  int max_sequence = 0;

  // cache storage of sequence length of all numbers up to the current one,
  // and will eventually store all 1000000 sequence lengths.
  int cache[MAX_NUMBER+1];
  for (int i = 0; i <= MAX_NUMBER; i++)
    cache[i] = 0;
  cache[1] = 1;

  for (int index = 2; index <= MAX_NUMBER; index++)
  {
    int sequence = 0;
    long term = index;
    // if term < index, then it's already in cache
    while (term != 1 && term >= index)
    {
      sequence += 1;
      term = (term % 2 == 0) ? term/2 : (3*term + 1);
    }

    // cache[1] is 1
    // cache[2] is 2 (2, {cache[1]})
    // cache[3] is 8 (3, 10, 5, 16, 8, 4, {cache[2]})
    // cache[4] is 3 (4, {cache[2]})
    // cache[5] is 6 (5, 16, 8, {cache[4]})
    cache[index] = sequence + cache[(int)term];
    // cout << "index: " << index << ", cache[" << index << "]: " << cache[index] << ", sequence: " << sequence << ", term: " << term << ", cache[" << term << "]: " << cache[(int)term]) << endl;
    if (cache[index] > max_sequence)
    {
      max_index = index;
      max_sequence = cache[index];
      cout << "caching: " << index << ", sequence: " << cache[index] << endl;
    }
  }
}

int main()
{
  longest_sequence();
  caching();
}
