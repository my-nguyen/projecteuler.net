#include <iostream>
#include <vector>
using namespace std;

// helper method to print out contents of a vector<int>. while this feature is
// not available in C++, it's built-in for Java and Ruby
string to_string(vector<int>& data)
{
  string builder;
  builder.append("[");
  for (int i = 0; i < data.size(); i++)
    builder.append(std::to_string(data[i])).append(", ");
  builder.pop_back();
  builder.pop_back();
  builder.append("]");
  return builder;
}

vector<vector<int> > count(int total, int denominations[], int size)
{
  vector<vector<int> > list;
  // special case when there's only one denomination left: create and return a
  // vector<vector<int> > where the inner vector<int> contains only the
  // division of total over the one denomination.
  if (size == 1)
  {
    vector<int> sublist;
    sublist.push_back(total/denominations[0]);
    list.push_back(sublist);
  }
  else if (size > 1)
  {
    // try different combinations by multiplying the head denomination with
    // 0, 1, 2, etc.
    for (int i = 0; i <= total/denominations[0]; i++)
    {
      int new_total = total - denominations[0]*i;
      int* sub_denominations = denominations+1;
      // recursive call with a new total and a sub array formed by removing
      // the head element from the list of denominations.
      vector<vector<int> > tmp = count(new_total, sub_denominations, size-1);
      // generate a new vector<vector<int> > by prepending the head
      // denomination to the vector<vector<int> > returned from the recursive
      // call
      for (int j = 0; j < tmp.size(); j++)
      {
        vector<int> entry;
        entry.push_back(i);
        entry.insert(entry.end(), tmp[j].begin(), tmp[j].end());
        list.push_back(entry);
      }
    }
  }
  return list;
}

int main()
{
  int denominations[] = { 200, 100, 50, 20, 10, 5, 2, 1 };
  vector<vector<int> > list = count(200, denominations, sizeof(denominations)/sizeof(int));
  for (int i = 0; i < list.size(); i++)
    cout << to_string(list[i]) << endl;
  cout << list.size() << endl;
}
