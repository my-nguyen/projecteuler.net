#include <iostream>
#include <vector>
#include <set>
#include <algorithm>  // sort()
#include <cmath>      // sqrt()
using namespace std;

// this class is used to retain the pair <multiplicand, multiplier> of a product
struct Pair
{
  int first;
  int second;

  Pair(int left, int right)
  {
    first = left;
    second = right;
  }
};

// this class keeps tracks of which of the 9 digits (from 1 to 9) in a number
// have been used
#define ALL_DIGITS 10
class Flags
{
  // cover all 10 digits from 0 to 9. vector of bools are initialized to 0.
  vector<bool> data;

public:
  // this method marks the digits in number as ON
  Flags& mask(string number)
  {
    for (int i = 0; i < number.length(); i++)
      data[number[i]-'0'] = true;
    return *this;
  }

  // this method counts all the ON digits
  int count()
  {
    int count = 0;
    // skip digit 0
    for (int i = 1; i < ALL_DIGITS; i++)
      if (data[i])
        count += 1;
    return count;
  }

  // constructor based on an integer
  Flags() : data(ALL_DIGITS)
  {
  }

  // copy constructor
  Flags(const Flags& rhs) : data(rhs.data)
  {
  }
};

// this method returns a list of all divisors of a target number
vector<int> factors(int number)
{
  vector<int> divisors;
  // 1 is always a divisor
  divisors.push_back(1);

  if (number > 1)
  {
    // target number is also always a divisor
    divisors.push_back(number);
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

// this method returns a list of pairs of <multiplicand, multiplier> from a
// list of factors
vector<Pair> pairs(vector<int> factors)
{
  vector<Pair> result;
  // only have to iterate thru half the list of factors, since beyond the
  // halfway line has already been accounted for in the pairs
  for (int i = 0; i < factors.size()/2; i++)
    result.push_back(Pair(factors[i], factors[factors.size()-1]/factors[i]));
  return result;
}

int main()
{
  // some products can be obtained more than one way, so using a Set will
  // remove the duplicate products
  set<int> pandigital;
  // there's a total of 9 digits (1 to 9). how many digits must a product have?
  // if it has 3 digits or less, then the pair of <multiplicand, multiplier>
  // must have at least 6 digits combined, which is impossible. if it has 5
  // digits or more, then <multiplicand, multiplier> must have at most 4
  // digits combined, which is also impossible. therefore, a product has to
  // have a 4 digits. the lower bound is just the smallest 4-digit number with
  // all 4 distinct digits: 1234. similarly, the upper bound is just the
  // highest 4-digit number with all 4 distinct digit: 9876
  for (int product = 1234; product <= 9876; product++)
  {
    Flags flags;
    flags.mask(to_string(product));
    // make sure product doesn't include 0
    if (flags.count() == 4)
    {
      // process each pair of <multiplicand, multiplier>
      vector<Pair> multipl = pairs(factors(product));
      for (vector<Pair>::iterator it = multipl.begin(); it != multipl.end(); it++)
      {
        string first = to_string(it->first);
        string second = to_string(it->second);
        // make sure the pair of <multiplicand, multiplier> have 5 digits combined
        if (first.length() + second.length() == 5)
        {
          // make a copy of flags
          Flags copy(flags);
          copy.mask(first).mask(second);
          // all 9 digits are filled: a pandigital is found
          if (copy.count() == 9)
          {
            pandigital.insert(product);
            cout << first << " x " << second << " = " << product << endl;
          }
        }
      }
    }
  }

  int sum = 0;
  for (set<int>::iterator it = pandigital.begin(); it != pandigital.end(); it++)
    sum += *it;
  cout << "Sum of all products: " << sum << endl;
}
