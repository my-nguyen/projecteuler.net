#include <iostream>
#include <vector>
#include <algorithm>  // sort()
#include <cmath>      // sqrt()
using namespace std;

// this method returns a list of all proper divisors of n (numbers less than n
// which divide evenly into n)
vector<int> divisors(int number)
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

#define MAX_AMICABLE 10000
int main()
{
  vector<int> pairs;
  for (int i = 1; i <= MAX_AMICABLE; i++)
  {
    // take the sum of all divisors of the current number (i)
    int total = sum(divisors(i));
    // only need to check for a possible pair if sum is greater than i
    if (total > i)
    {
      // take the sum of all divisors of the sum, and see if that equals the
      // current number (i)
      if (sum(divisors(total)) == i)
      {
        cout << i << " and " << total << endl;
        pairs.push_back(i);
        pairs.push_back(total);
      }
    }
  }
  cout << "sum: " << sum(pairs) << endl;
}
