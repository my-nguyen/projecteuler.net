# this method returns a list of all proper divisors of n (numbers less than n
# which divide evenly into n)
def divisors(number)
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

MAX_AMICABLE = 10000
pairs = []
1.upto(MAX_AMICABLE) do |i|
  # take the sum of all divisors of the current number (i)
  total = sum(divisors(i))
  # only need to check for a possible pair if sum is greater than i
  if (total > i)
    # take the sum of all divisors of the sum, and see if that equals the
    # current number (i)
    if (sum(divisors(total)) == i)
      puts("#{i} and #{total}")
      pairs << i
      pairs << total
    end
  end
end
puts("sum: #{sum(pairs)}")
