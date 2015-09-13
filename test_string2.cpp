#include <iostream>
#include <string>
using namespace std;

// test inserting (padding) a character multiple times at the beginning of a string
int main()
{
  string a = "1920834";
  string b = "dd";
  b.insert(0, a.size()-b.size(), 'x');
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
}
