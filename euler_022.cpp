#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

// this method opens a file, reads the only line in the file which contains
// over 5,000 names, parse the names, store them in a list, then return the list
vector<string> input()
{
  // read from file.
  ifstream file("euler_022-names.txt");
  // there's only one huge line (46447 characters) to read
  string line;
  getline(file, line);

  vector<string> names;
  // parse the line into strings (names) based on delimeter ",\""
  char_separator<char> separator(",\"");
  tokenizer<char_separator<char> > tokens(line, separator);
  for (tokenizer<char_separator<char> >::iterator it = tokens.begin();
    it != tokens.end();
    it++)
  {
    string name = *it;
    // retain each name in a list
    names.push_back(name);
  }

  // sort the names alphabetically
  sort(names.begin(), names.end());
  file.close();

  return names;
}

// this method returns a list of scores of the corresponding names. each score
// is calculated by taking the total of the alphabetical value of all letters
// in a name before multiplying that total by the alphabetical position of
// that name.
vector<int> scores(vector<string> names)
{
  vector<int> scores;
  // go thru the name list
  for (int i = 0; i < names.size(); i++)
  {
    int sum = 0;
    for (string::iterator jt = names[i].begin(); jt != names[i].end(); jt++)
    {
      // sum of the alphabetical value of all letters of a name
      int value = *jt - 'A' + 1;
      sum += value;
      // cout << "char: " << *jt << ", value: " << value << endl;
    }
    // cout << "total: " << sum << ", index: " << i << endl;
    // multiply the sum with the alphabetical position of the name
    sum *= i + 1;

    // retain that product in a list
    scores.push_back(sum);
  }

  return scores;
}

// this method returns the sum of all integers in a list
int sum(vector<int> list)
{
  int sum = 0;
  for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
    sum += *it;
  return sum;
}

int main()
{
  vector<string> names = input();
  // vector<string>::iterator it = find(names.begin(), names.end(), "COLIN");
  // cout << "index of COLIN: " << distance(names.begin(), it) << endl;
  vector<int> points = scores(names);
  cout << "Total: " << sum(points) << endl;
}
