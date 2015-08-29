#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class int_array
{
public:
  int_array() {}

  void push(int number) { _vector.push_back(number); }

  void sort() { std::sort(_vector.begin(), _vector.end()); }

  int sum()
  {
    int sum = 0;
    for (vector<int>::iterator i = _vector.begin(); i != _vector.end(); i++)
      sum += *i;
    return sum;
  }

  friend ostream& operator<<(ostream& output, const int_array& array)
  {
    for (int i = 0; i < array._vector.size(); i++)
    {
      output << " " << array._vector[i];
      if ((i+1) % 10 == 0)
        output << endl;
    }
    output << endl;
  }

private:
  vector<int> _vector;
};
