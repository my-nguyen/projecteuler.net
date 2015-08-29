// Be sure to compile with g++ not gcc
#include "int_array.h"

int main()
{
  int_array myv;
  srand(time(0));
  for (int i = 0; i < 55; i++)
    myv.push(rand() % 100);
  cout << "int array UNSORTED" << endl;
  cout << myv;
  myv.sort();
  cout << "int array SORTED" << endl;
  cout << myv;
  return 0;
}
