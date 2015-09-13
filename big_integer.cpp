#include "big_integer.h"
#include <iostream>
#include <algorithm> // reverse()
using namespace std;

BigInteger BigInteger::operator=(const BigInteger& rhs)
{
  data = rhs.data;
  return *this;
}

BigInteger BigInteger::operator+(BigInteger& rhs)
{
  // work on copies
  string left = data;
  string right = rhs.data;

  // pad the shorter number with leading zeroes so the 2 numbers have equal length
  if (right.size() > left.size())
    left.insert(0, right.size()-left.size(), '0');
  else if (left.size() > right.size())
    right.insert(0, left.size()-right.size(), '0');

  int carry = 0;
  string sum;
  for (int i = left.size()-1; i >= 0; i--)
  {
    int total = (left[i]-'0') + (right[i]-'0') + carry;
    if (total >= 10)
    {
      carry = 1;
      total -= 10;
    }
    else
      carry = 0;

    // this builds a string with the digits in reversed order
    sum += '0' + total;
  }
  if (carry)
    sum += '1';

  // therefore the resulting string needs to be reversed
  reverse(sum.begin(), sum.end());

  return BigInteger(sum);
}
