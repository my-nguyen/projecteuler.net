#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
using namespace std;

class BigInteger
{
public:
  BigInteger() : data() {}
  BigInteger(const string& number) : data(number) {}
  BigInteger operator=(const BigInteger& rhs);
  BigInteger operator+(BigInteger& rhs);
  operator string() const { return data; }

private:
  string data;
};

#endif
