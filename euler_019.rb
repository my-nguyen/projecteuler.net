def days(month, year)
  map = [ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ]
  if (month != 2)
    map[month-1]
  else
    # calculate leap year
    # if year is not evenly divisible by 4, it's not a leap year
    if (year % 4 != 0)
      28
    else
      # if year is evenly divisible by 4 but not by 100, it's a leap year
      if (year % 100 != 0)
        29
      else
        # if year is evenly divisible by 4, by 100 and by 400, it's a leap year
        # otherwise it's not a leap year
        year % 400 == 0 ? 29 : 28
      end
    end
  end
end

months =
[
  "", "February", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December", "January"
]
# to keep track of what months of what year have its first day fall on a Sunday
mois = []
annees = []
# 1/1/1900 is a Monday, which means Sunday is on 1/7/1900, 1/14/1900,
# 1/21/1900, 1/28/1900, etc. So any integer that is the first of a month
# and is also evenly divisible by 7 is a Sunday.
# date starts on 1/1/10900. one year later, date is updated to 366, and so on
date = 1
1900.upto(2000) do |year|
  # offset is how many days there are from January 1st of the current year
  offset = 0
  1.upto(12) do |month|
    # calculate the dates for Feb 1st, Mar 1st ... Dec 1st, and Jan 1st
    offset = 0
    # the offset of the first day of a month is the sum of all the days in
    # all the previous months. for example, the offset of June 1st is the
    # sum of all the days in January (31), February (28 or 29), March (31),
    # April (30), and May (31)
    1.upto(month) do |i|
      offset += days(i, year)
    end
    # adjust to the correct year
    annee = year + (month == 12 ? 1 : 0)
    if ((date+offset) % 7 == 0 && annee != 1900)
      mois << month
      annees << annee
      puts("#{months[month]} of #{annee}")
    end
  end
  # advance one year
  date += offset
end

puts("#{mois.size} Sundays fell on the first of the month during the twentieth century")
