#include <iostream>
#include <string>
using namespace std;

string table[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
class Convert
{
public:
  Convert(int digit) : _digit(digit) {}
  operator string() const { return table[_digit]; }
  // operator string() const { return "NGUYEN"; }

private:
  int _digit;
};

int main()
{
  string name = "MY NGUYEN";
  cout << name << endl;

  Convert con(7);
  cout << "convert(7): " << con.operator string() << endl;
}
