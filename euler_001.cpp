// Refer to euler_001.rb for clarifying comments.
#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> array)
{
  int sum = 0;
  for (int i = 0; i < array.size(); i++)
    sum += array[i];
  return sum;
}

int main()
{
  int limits[] = {10, 20, 100, 500, 1000};
  for (int i = 0; i < sizeof(limits)/sizeof(int); i++)
  {
    vector<int> multiples;

    // collect all multiples of 3
    int highest_3 = (limits[i]-1) / 3;
    for (int j = 1; j <= highest_3; j++)
      multiples.push_back(j * 3);

    // collect all multiples of 5
    int highest_5 = (limits[i]-1) / 5;
    for (int j = 1; j <= highest_5; j++)
      if (j % 3 != 0)
        multiples.push_back(j * 5);

    cout << "limit: " << limits[i] << ", sum: " << sum(multiples) << endl;
  }
}
