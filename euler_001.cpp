// Refer to euler_001.rb for clarifying comments.
// Be sure to compile with g++ not gcc
#include "int_arrayp.h"

int main()
{
  int limits[] = {10, 20, 100, 500, 1000};
  for (int i = 0; i < sizeof(limits)/sizeof(int); i++)
  {
    int_array multiples;
    int highest_3 = (limits[i]-1) / 3;
    for (int j = 1; j <= highest_3; j++)
      multiples.push(j * 3);

    int highest_5 = (limits[i]-1) / 5;
    for (int j = 1; j <= highest_5; j++)
      if (j % 3 != 0)
        multiples.push(j * 5);

    multiples.sort();
    cout << "limit: " << limits[i] << ", sum: " << multiples.sum() << endl;
    // cout << multiples;
  }
}
