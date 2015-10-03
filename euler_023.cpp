#include <iostream>
#include <vector>
#include <algorithm>  // sort()
#include <cmath>      // sqrt()
using namespace std;

// this method returns a list of all proper divisors of n (numbers less than n
// which divide evenly into n)
vector<int> proper_divisors(int number)
{
  // at least 2 elements, since 1 and number are always divisors
  vector<int> divisors;
  divisors.push_back(1);

  if (number > 1)
  {
    // start looking for other divisors from 2 on up.
    int i = 2;
    while (i <= (int)sqrt(number))
    {
      // if number is evenly divisible by i, then retain i
      if (number % i == 0)
      {
        divisors.push_back(i);
        // possibly also retain the division of number/i.
        if (i != number/i)
          divisors.push_back(number/i);
      }
      i += 1;
    }
    sort(divisors.begin(), divisors.end());
  }
  return divisors;
}

// this method returns the sum of all numbers in a list
int sum(const vector<int>& list)
{
  int sum = 0;
  for (int i = 0; i < list.size(); i++)
    sum += list[i];
  return sum;
}

int main()
{
  int LIMIT = 28123;

  // calculate all abundant numbers from 1 to the LIMIT
  vector<int> abundants;
  for (int i = 1; i < LIMIT; i++)
    // an abundant number is one where the sum of all the proper divisors of
    // the number is greater than the number
    if (sum(proper_divisors(i)) > i)
      abundants.push_back(i);

  // take all the sums of any 2 abundant numbers within LIMIT
  // vector<bool> is chosen over bool[] because of its ability to allocate and
  // initialize upon construction
  vector<bool> abundant_sums(LIMIT);
  for (int i = 0; i < abundants.size(); i++)
    for (int j = i; j < abundants.size(); j++)
    {
      // sum of any 2 abundant numbers, both of which must be within LIMIT
      int sum = abundants[i] + abundants[j];
      // the sum must also be within LIMIT
      if (sum < LIMIT)
        // flag this number as the sum of some 2 abundant numbers
        abundant_sums[sum] = true;
    }

  // take the sum of all numbers that are not the sums of 2 abundant numbers
  int result = 0;
  for (int i = 0; i < abundant_sums.size(); i++)
    // any unflagged number within LIMIT
    if (!abundant_sums[i])
      // take the sum of all those unflagged numbers
      result += i;

  cout << "result: " << result << endl;
}
