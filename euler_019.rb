# this method returns the number of days within a month of a certain year
def days(month, year)
  # except for entry 2 (February), each entry is the number of days within
  # that month
  map = [ 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ]
  # things are simple when month is not February
  if (month != 2)
    return map[month-1]
  # otherwise, must calculate leap year
  else
    # if year is not evenly divisible by 4, it's not a leap year
    if (year % 4 != 0)
      return 28
    else
      # if year is evenly divisible by 4 but not by 100, it's a leap year
      if (year % 100 != 0)
        return 29
      else
        # if year is evenly divisible by 4, by 100 and by 400, it's a leap year
        # otherwise it's not a leap year
        return (year % 400 == 0 ? 29 : 28)
      end
    end
  end
end

months =
[
  "", "February", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December", "January"
]
# how many months have its first day fall on a Sunday
count = 0
# date 1 is 1/1/1900. one year later, date is updated to 366, and so on
date = 1
# check each year, including 1900 even though the spec starts at 1901,
# because day 1 starts in 1900.
(1900..2000).each do |year|
  # offset is how many days there are between January 1st of the current
  # year and the first day of the current month (Feb 1st, Mar 1st ...
  # Dec 1st, and Jan 1st)
  offset = 0
  # check each month of the current year
  (1..12).each do |month|
    # the offset of the first day of a month is the sum of all the days in
    # all the previous months. for example, the offset of June 1st is the
    # sum of all the days in January (31), February (28 or 29), March (31),
    # April (30), and May (31), or sum is either 151 or 152
    offset += days(month, year)
    # the end of month 12 (December) falls on the next year, so adjust the
    # year accordingly
    annee = year + (month == 12 ? 1 : 0)
    # puts("offset: #{offset}, 1st of #{months[month]} of #{annee}: #{(date+offset)}")
    # since day 1 (1/1/1900) is a Monday, day 7, day 14, day 21, day 28
    # (which all happen to be divisible by 7), are all Sundays. So any
    # integer that falls on the first of a month and is also divisible by 7
    # is a Sunday.
    # also we must discount year 1900 as per problem spec
    if ((date+offset) % 7 == 0 && annee != 1900)
      count += 1
      puts("#{months[month]} of #{annee}")
    end
  end
  # advance one year
  date += offset
end

puts("#{count} Sundays fell on the first of the month during the twentieth century")
