// g++ -std=c++11 this-file
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::reverse
using namespace std;

// this method returns the reverse of a number.
int reverse(int number)
{
  string tmp = to_string(number);
  reverse(tmp.begin(), tmp.end());
  return stoi(tmp);
}

// this method returns whether a number is a palindrome
bool is_palindrome(int number)
{
  return number == reverse(number);
}

// this method counts the number of digits in a number
int count_digits(int number)
{
  return to_string(number).length();
}

// this method returns number 1, repeated as many times as specified in param
int repeat(int times)
{
  return stoi(string(times, '1'));
}

// this method finds the largest palindrome found in all products of 1-digit,
// 2-digit and 3-digit numbers
vector<int> brute_force(int target)
{
  vector<int> result;
  int max = 1;
  // use 2 indices: upper starts from target down to 1, and lower starts from
  // upper down to 1
  int lower_bound = repeat(count_digits(target));
  for (int upper = target; upper >= lower_bound; upper--)
  {
    for (int lower = upper; lower >= lower_bound; lower--)
    {
      int product = upper * lower;
      if (is_palindrome(product) && product > max)
      {
        max = product;
        result.clear();
        result.push_back(lower);
        result.push_back(upper);
      }
    }
  }
  return result;
}

// this method generates a palindrome by combining a number with its own
// reverse
int make_palindrome(int first_half)
{
  string forward = to_string(first_half);
  string backward(forward);
  reverse(backward.begin(), backward.end());
  return stoi(forward + backward);
}

// this method is based on http://www.mathblog.dk/project-euler-problem-4/
vector<int> mathblog(int target)
{
  vector<int> result;
  bool found = false;
  int index = target-1;
  while (!found)
  {
    // first create a fictional palindrome from index, e.g. 998899 from 998
    int palindrome = make_palindrome(index);
    // then look for a number by which palindrome is evenly divisible
    for (int i = target; i >= repeat(count_digits(target)); i--)
    {
      // that number has to be between the square root of the palindrome(1)
      // and the target number(2)
      // (1) any factor less than the square root of the palindrome will have
      // a corresponding factor larger than the square root.
      // (2) problem requires the factor to be less than target
      if (i*i < palindrome || palindrome/i > target)
        break;
      if (palindrome % i == 0)
      {
        found = true;
        result.push_back(palindrome / i);
        result.push_back(i);
        break;
      }
    }
    index -= 1;
  }
  return result;
}

int main()
{
  int targets[] = {99, 999, 9999};
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    vector<int> result = brute_force(targets[i]);
    cout << "brute-force: " << result[0] << "x" << result[1] << " = " << result[0]*result[1] << endl;
  }
  for (int i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    vector<int> result = mathblog(targets[i]);
    cout << "optimized: " << result[0] << "x" << result[1] << " = " << result[0]*result[1] << endl;
  }
}
