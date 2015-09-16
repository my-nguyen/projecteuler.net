// Refer to http://www.mathblog.dk/project-euler-18/
// for an explanation of the solution to the problem
//
#include <iostream>
#include <sstream>    // stringstream
#include <vector>
#include <algorithm>  // max()
using namespace std;

void input(vector<vector<int> >* triangle)
{
  // triangle is a 2-dimensional array of integers
  int i = 1;
  string line;
  // fetch one whole line until the end of input
  while (getline(cin, line))
  {
    vector<int> row;
    // convert line into a stringstream
    stringstream stream(line);
    // read 1 int at row 1, 2 int's at row 2, etc
    for (int j = 0; j < i; j++)
    {
      int number;
      // read integers from the stringstream
      stream >> number;
      row.push_back(number);
    }
    triangle->push_back(row);
    i++;
  }
}

void print(const vector<vector<int> >& triangle)
{
  cout << "INPUT" << endl;
  for (int i = 0; i < triangle.size(); i++)
  {
    for (int j = 0; j < triangle[i].size(); j++)
      cout << " " << triangle[i][j];
    cout << endl;
  }
}

void process(vector<vector<int> >& triangle)
{
  cout << "OUTPUT" << endl;
  for (int i = triangle.size()-2; i >= 0; i--)
  {
    // must use reference here; otherwise a copy would be created locally and
    // the line current[j] = maxi would cause the local copy, and not the
    // triangle itself, to save the max value.
    vector<int>& current = triangle[i];
    vector<int> next = triangle[i+1];
    // start from next-to-bottom row, work back to top
    for (int j = 0; j < current.size(); j++)
    {
      // for each entry, take 2 sums: triangle[i][j] + triangle[i+1][j] and
      // triangle[i][j] + triangle[i+1][j+1]
      // then replace entry with the max of the 2 sums
      int maxi = max(current[j]+next[j], current[j]+next[j+1]);
      current[j] = maxi;
      cout << " " << current[j];
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int> > triangle;
  input(&triangle);
  print(triangle);
  process(triangle);
}
