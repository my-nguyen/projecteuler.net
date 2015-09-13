#include "big_integer.h"
#include <iostream>
using namespace std;

int main()
{
  string strings[] =
  {
    "37107287533902102798797998220837590246510135740250",
    "46376937677490009712648124896970078050417018260538",
    "74324986199524741059474233309513058123726617309629"
  };

  BigInteger numbers[3];
  for (int i = 0; i < 3; i++)
    numbers[i] = strings[i];

  cout << "num: " << (string)numbers[0] << endl;
  cout << "num: " << (string)numbers[1] << endl;
  BigInteger sum = numbers[0] + numbers[1];
  cout << "sum: " << (string)sum << endl;
  cout << "num: " << (string)numbers[2] << endl;
  sum = sum + numbers[2];
  cout << "sum: " << (string)sum << endl;
  string tmp = sum;
  cout << "high 10: " << tmp.substr(0, 10) << ", low 10: " << endl;
  // cout << tmp.substr(tmp.length()-11, 10) << endl;
}
