#include <iostream>
#include <cstring>
using namespace std;

const char* word(int number)
{
  const char* units[] =
  {
    "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine",
  };
  const char* teens[] =
  {
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
  };
  const char* tens[] =
  {
    "ten", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
  };

  string word;
  if (number == 1000)
    word.append("onethousand");
  else
  {
    int cent = number / 100;
    if (cent >= 1)
    {
      word.append(units[cent-1]).append("").append("hundred");
      if (number % 100 != 0)
        word.append("and");
    }

    if (number % 100 != 0)
    {
      int dix = number % 100;
      if (dix >= 20)
      {
        int unite = dix / 10;
        word.append(tens[dix/10 - 1]);
        if (dix % 10 != 0)
        {
          word.append("");
          word.append(units[dix%10-1]);
        }
      }
      else if (dix >= 10)
        word.append(teens[dix-10]);
      else
        word.append(units[dix-1]);
    }
  }

  return word.c_str();
}

int main()
{
  int sum = 0;
  for (int i = 1; i <= 1000; i++)
  {
    const char* mot = word(i);
    sum += strlen(mot);
    cout << mot << ", " << sum << endl;
  }
}
