#include <iostream>
#include <vector>
#include <algorithm>  // sort()
#include <cmath>      // sqrt()
using namespace std;

void print_vector(const vector<int>& numbers)
{
  for (int i = 0; i < numbers.size(); i++)
  {
    cout << " " << numbers[i];
    if ((i+1) % 10 == 0 && i != (numbers.size()-1))
      cout << endl;
  }
  cout << endl;
}

// find all divisors of a target number
vector<int> find_divisors(int number)
{
  // at least 2 elements, since 1 and number are always divisors
  vector<int> divisors;
  divisors.push_back(1);

  if (number > 1)
  {
    // target number is also always a divisor
    divisors.push_back(number);
    // start looking for other divisors from 2 on up.
    int i = 2;
    while (i <= (int)sqrt(number))
    {
      // if number is evenly divisible by i, then retain i
      if (number % i == 0)
      {
        divisors.push_back(i);
        // possibly also retain the division of number/i.
        if (i != number/i)
          divisors.push_back(number/i);
      }
      i += 1;
    }
    sort(divisors.begin(), divisors.end());
  }
  return divisors;
}

int main()
{
  // divisors contains all the divisors/factors of a triangle, for example:
  // triangle  divisors
  //      1    1
  //      3    1,3
  //      6    1,2,3,6
  //     10    1,2,5,10
  //     15    1,3,5,15
  //     21    1,3,7,21
  //     28    1,2,4,7,14,28
  vector<int> divisors;
  // let's start numbering at 2 instead of 1, which means triangles already
  // contains number 1
  int number = 2;
  vector<int> triangles;
  triangles.push_back(1);
  // in the beginning, target is set at 1, but as that target is reached, a new
  // target is set by adding 1 to the number of divisors of the current
  // triangle. since the number of divisors is an arbitrary number that is
  // greater than the current target, the target gets increased pretty fast as
  // shown in the resulting number of divisors:
  // 2, 4, 6, 9, 16, 18, 20, 24, 36, 40, 48, 90, 112, 128, 144, 162, 168, 192,
  // 240, 320, 480, 576.
  int target = 1;
  // eventual target is 500, as required by the program
  while (target < 500)
  {
    // triangle of 1
    int triangle = 1;
    while (divisors.size() <= target)
    {
      // triangle is the sum of the previous entry and current number
      triangle = triangles[number-2] + number;
      // retain that sum
      triangles.push_back(triangle);
      // get all divisors for that sum
      divisors = find_divisors(triangle);
      // go to next number
      number += 1;
    }
    cout << "First that reach " << divisors.size() << ": number "
      << (number-1) << ", triangle " << triangle << endl;
    // set a new target based on the number of divisors of the current triangle
    target = divisors.size() + 1;
  }
}
