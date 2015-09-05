#include <bitset>
#include <iostream>
using namespace std;

void change(bitset<64>* bits)
{
  for (int i = 0; i < 16; i++)
    bits->reset(i*4);
  bits->reset(100);
}

int main()
{
  bitset<64> bits(0xFFFFFFFFFFFFFFFF);
  cout << "bits: " << bits << endl;
  change(&bits);
  cout << "bits: " << bits << endl;
}
