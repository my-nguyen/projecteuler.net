// compile: g++ -std=c++11 this_file (to enable std::to_string())
// for an explanation on how to find the recurring cycles, refer to
// http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // find()
using namespace std;

// this is a convenience class to bundle several pieces of information to return
// to the caller
class Decimal
{
public:
  string data;
  bool recurring;
  int start;
  int length;

  Decimal(string info, bool repeating)
  {
    data = info;
    recurring = repeating;
  }

  Decimal(string info, bool repeating, int commencement, int longueur)
  : Decimal(info, repeating)
  {
    start = commencement;
    length = longueur;
  }
};

Decimal decimal(int number)
{
  vector<int> remainders;
  string builder;
  int divider = 10;
  while (divider != 0)
  {
    int remainder = divider % number;
    vector<int>::iterator it = find(remainders.begin(), remainders.end(), remainder);
    // a cycle recurs when a remainder repeats
    if (it != remainders.end())
    {
      // record the length of the recurring cycle
      int start = it - remainders.begin();
      int length = remainders.size() - start;
      return Decimal(builder, true, start, length);
    }
    // no cycle found: keep recording divisor
    else
    {
      remainders.push_back(remainder);
      builder += (char)(divider/number + '0');
    }
    divider = (divider%number) * 10;
  }
  return Decimal(builder, false);
}

int main()
{
  int max = 0;
  int number = 999;
  string recurrence;
  for (int i = 999; i >= 2; i--)
  {
    Decimal decim = decimal(i);
    cout << "1/" << i << ": ";
    if (!decim.recurring)
      cout << "non-recurring" << endl;
    else
    {
      int length = decim.data.length() - decim.start;
      cout << "recurring, length: " << length << endl;

      // look for and record the max cycle length and other useful info
      if (length > max)
      {
        max = length;
        number = i;
        recurrence = decim.data.substr(decim.start);
      }
    }
  }
  cout << "number: " << number << ", length: " << max << endl;
}
