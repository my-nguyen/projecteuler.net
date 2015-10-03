# this method returns a list of all proper divisors of n (numbers less than n
# which divide evenly into n)
def proper_divisors(number)
  # 1 is always a divisor
  divisors = [1]
  if number > 1
    # start looking for other divisors from 2 on up.
    i = 2
    while (i <= Math.sqrt(number).to_i)
      # if number is evenly divisible by i, then retain i, and possibly also
      # the division of number/i.
      if (number % i == 0)
        divisors << i
        divisors << number/i if (i != number/i)
      end
      i += 1
    end
    divisors.sort!
  end
  divisors
end

# this method returns the sum of all numbers in a list
def sum(list)
  list.inject(:+)
end

LIMIT = 28123;

# calculate all abundant numbers from 1 to the LIMIT
abundants = []
1.upto(LIMIT-1) do |i|
  # an abundant number is one where the sum of all the proper divisors of
  # the number is greater than the number
  if (sum(proper_divisors(i)) > i)
    abundants << i
  end
end

# take all the sums of any 2 abundant numbers within LIMIT
# fortunately Ruby array has the ability to initialize upon construction
abundant_sums = Array.new(LIMIT, false)
abundants.size.times do |i|
  abundants.size.times do |j|
    # sum of any 2 abundant numbers, both of which must be within LIMIT
    sum = abundants[i] + abundants[j]
    # the sum must also be within LIMIT
    if (sum < LIMIT)
      # flag this number as the sum of some 2 abundant numbers
      abundant_sums[sum] = true
    end
  end
end

# take the sum of all numbers that are not the sums of 2 abundant numbers
result = 0
abundant_sums.size.times do |i|
  # any unflagged number within LIMIT
  if (!abundant_sums[i])
    # take the sum of all those unflagged numbers
    result += i
  end
end

puts("result: #{result}")
