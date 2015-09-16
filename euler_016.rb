exponents = [ 15, 50, 100, 250, 500, 750, 1000 ]

exponents.each do |exponent|
  # take 2 to the power of exponent. this will be a huge number as exponent gets
  # bigger
  power = 2**exponent

  # convert the huge integer into string, break that string into an array of
  # characters, then turn that array into an array of digits
  numbers = power.to_s.chars.map(&:to_i);

  # take the sum of all the digits in the array of digits
  sum = numbers.inject(:+)

  puts("2^#{exponent}: #{power}, sum: #{sum}")
end
