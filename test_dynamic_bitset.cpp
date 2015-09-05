#include <boost/dynamic_bitset.hpp>
#include <iostream>
using namespace std;

void change(boost::dynamic_bitset<>* bits)
{
  for (int i = 0; i*4 < bits->size(); i++)
    bits->reset(i*4);
  cout << "size: " << bits->size() << endl;
}

int main()
{
  boost::dynamic_bitset<> bits(100);
  bits.set();
  cout << "bits: " << bits << endl;
  change(&bits);
  cout << "bits: " << bits << endl;
}
