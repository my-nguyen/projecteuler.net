#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
string to_string(vector<int>& array)
{
  string builder;
  builder.append("[");
  for (int i = 0; i < array.size(); i++)
    builder.append(to_string(array[i])).append(", ");
  builder.pop_back();
  builder.pop_back();
  builder.append("]");
  return builder;
}

string to_string(vector<vector<int> >& list)
{
  string builder;
  for (int i = 0; i < list.size(); i++)
  {
    builder.append(to_string(list[i]));
    builder.append("\n");
  }
  return builder;
}
*/

int main()
{
  /*
  vector<int> tmp;
  for (int i = 0; i < 5; i++)
    tmp.push_back(i);
  tmp[2] = tmp[2]*3;
  cout << to_string(tmp) << endl;

  // cout << "func(): " << func() << endl;
  vector<vector<int> > list;
  for (int i = 0; i < 3; i++)
  {
    vector<int> array;
    for (int j = 0; j < 5; j ++)
      array.push_back(i*j);
    list.push_back(array);
  }

  cout << to_string(list);
  */

  cout << "NEW TEST" << endl;
  vector<bool> array(5);
  for (int i = 0; i < 5; i++)
    cout << " " << array[i];
  cout << endl;
}
