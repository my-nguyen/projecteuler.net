exponents = [ 15, 50, 100, 250, 500, 750, 1000 ]

for exponent in exponents:
  # take 2 to the power of exponent. this will be a huge number as exponent gets
  # bigger
  power = 2**exponent

  # convert the huge integer into string, break that string into an array of
  # characters, then turn that array into an array of digits
  numbers = map(int, list(str(power)))

  # take the sum of all the digits in the array of digits
  total = sum(numbers)

  print("2^%d: %d, sum: %d" %(exponent, power, total))
