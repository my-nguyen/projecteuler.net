def word(number):
  units = [
    "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine",
  ]
  teens = [
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
  ]
  tens = [
    "ten", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
  ]

  word = ""
  if (number == 1000):
    word += "onethousand"
  else:
    cent = number / 100
    if (cent >= 1):
      word += units[cent-1]
      word += "hundred"
      if (number % 100 != 0):
        word += "and"

    if (number % 100 != 0):
      dix = number % 100
      if (dix >= 20):
        unite = dix / 10
        word += tens[dix/10 - 1]
        if (dix % 10 != 0):
          word += units[dix%10-1]
      elif (dix >= 10):
        word += teens[dix-10]
      else:
        word += units[dix-1]
  return word

sum = 0
for i in range(1, 1001):
  mot = word(i)
  sum += len(mot)
  print("%s, %d" %(mot, sum))
