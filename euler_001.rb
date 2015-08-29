# Multiples of 3 and 5
# If we list all the natural numbers below 10 that are multiples of 3 or 5,
# we get 3, 5, 6, and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#
def print_array numbers
  numbers.each_index do |i|
    print " #{numbers[i]}"
    puts if ((i+1) % 10 == 0 && i != (numbers.size-1))
  end
  puts
end

limits = [10, 20, 100, 500, 1000]
limits.each do |limit|
  multiples = []
  # If limit is 20, then the multiples of 3 that are below 20 are 1*3, 2*3, 3*3,
  # 4*3, 5*3, 6*3, OR 3, 6, 9, 12, 15, and 18. 18 is the highest multiple of 3
  # that is still less than the limit, and we can obtain the divisor of that
  # highest multiple by dividing the limit by 3: 20/3 = 6. Then sum them all as
  # per the problem's requirement
  highest_3 = (limit-1) / 3
  1.upto(highest_3) do |number|
    multiples << number * 3
  end

  # similarly with multiples of 5, except that we need to discount those that are
  # multiples of both 5 and 3, because those are already accounted for in the
  # other loop above
  highest_5 = (limit-1) / 5
  1.upto(highest_5) do |number|
    multiples << (number * 5) if (number % 3 != 0)
  end

  multiples.sort!
  puts("limit: #{limit}, sum: #{multiples.reduce(:+)}")
  # print_array multiples
end
# ANSWER for limit 1000: sum is 233168
