#include <iostream>
#include <vector>
using namespace std;

int days(int month, int year)
{
  int map[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if (month != 2)
    return map[month-1];
  else
  {
    // calculate leap year
    // if year is not evenly divisible by 4, it's not a leap year
    if (year % 4 != 0)
      return 28;
    else
    {
      // if year is evenly divisible by 4 but not by 100, it's a leap year
      if (year % 100 != 0)
        return 29;
      else
        // if year is evenly divisible by 4, by 100 and by 400, it's a leap year
        // otherwise it's not a leap year
        return (year % 400 == 0 ? 29 : 28);
    }
  }
}

int main()
{
  const char* months[] =
  {
    "", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December", "January"
  };
  // to keep track of what months of what year have its first day fall on a Sunday
  vector<int> mois;
  vector<int> annees;
  // 1/1/1900 is a Monday, which means Sunday is on 1/7/1900, 1/14/1900,
  // 1/21/1900, 1/28/1900, etc. So any integer that is the first of a month
  // and is also evenly divisible by 7 is a Sunday.
  // date starts on 1/1/10900. one year later, date is updated to 366, and so on
  int date = 1;
  for (int year = 1900; year <= 2000; year++)
  {
    // offset is how many days there are from January 1st of the current year
    int offset = 0;
    for (int month = 1; month <= 12; month++)
    {
      // calculate the dates for Feb 1st, Mar 1st ... Dec 1st, and Jan 1st
      offset = 0;
      // the offset of the first day of a month is the sum of all the days in
      // all the previous months. for example, the offset of June 1st is the
      // sum of all the days in January (31), February (28 or 29), March (31),
      // April (30), and May (31)
      for (int i = 1; i <= month; i++)
        offset += days(i, year);
      // adjust to the correct year
      int annee = year + (month == 12 ? 1 : 0);
      if ((date+offset) % 7 == 0 && annee != 1900)
      {
        mois.push_back(month);
        annees.push_back(annee);
        cout << months[month] << " of " << annee << endl;
      }
    }
    // advance one year
    date += offset;
  }

  cout << mois.size() << " Sundays fell on the first of the month during the twentieth century" << endl;
}
