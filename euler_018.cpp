// Refer to http://www.mathblog.dk/project-euler-18/
// for an explanation of the solution to the problem
#include <iostream>
#include <vector>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

// this method converts a string containing integers separated by spaces into
// an array of integers
vector<int> to_ints(string line)
{
  vector<int> array;
  tokenizer<char_separator<char> > tokens(line);
  for (tokenizer<char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); it++)
    array.push_back(stoi(*it));
  return array;
}

vector<vector<int> > input()
{
  string lines[] =
  {
    "75",
    "95 64",
    "17 47 82",
    "18 35 87 10",
    "20 04 82 47 65",
    "19 01 23 75 03 34",
    "88 02 77 73 07 63 67",
    "99 65 04 28 06 16 70 92",
    "41 41 26 56 83 40 80 70 33",
    "41 48 72 33 47 32 37 16 94 29",
    "53 71 44 65 25 43 91 52 97 51 14",
    "70 11 33 28 77 73 17 78 39 68 17 57",
    "91 71 52 38 17 14 91 43 58 50 27 29 48",
    "63 66 04 68 89 53 67 30 73 16 69 87 40 31",
    "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"
  };

  vector<vector<int> > triangle;
  for (int i = 0; i < sizeof(lines)/sizeof(string); i++)
    triangle.push_back(to_ints(lines[i]));
  return triangle;
}

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

void process(vector<vector<int> >& triangle)
{
  cout << "OUTPUT" << endl;
  for (int i = triangle.size()-2; i >= 0; i--)
  {
    vector<int>& current = triangle[i];
    vector<int> next = triangle[i+1];
    // start from next-to-bottom row, work back to top
    for (int j = 0; j < current.size(); j++)
    {
      // for each entry, take 2 sums:
      // triangle[i][j] + triangle[i+1][j] AND triangle[i][j] + triangle[i+1][j+1]
      // then replace entry with the max of the 2 sums
      int entry = max(current[j]+next[j], current[j]+next[j+1]);
      current[j] = entry;
    }
    cout << to_string(current) << endl;
  }
}

int main()
{
  vector<vector<int> > triangle = input();
  cout << "INPUT" << endl << to_string(triangle);
  process(triangle);
}
