# The sequence of triangle numbers is generated by adding the natural numbers.
# So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first
# ten terms would be:
# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
# Let us list the factors of the first seven triangle numbers:
#      1: 1
#      3: 1,3
#      6: 1,2,3,6
#     10: 1,2,5,10
#     15: 1,3,5,15
#     21: 1,3,7,21
#     28: 1,2,4,7,14,28
#
# We can see that 28 is the first triangle number to have over five divisors.
# What is the value of the first triangle number to have over five hundred divisors?
#
def print_array numbers
  numbers.each_index do |i|
    print " #{numbers[i]}"
    puts if ((i+1) % 10 == 0 && i != (numbers.size-1))
  end
  puts
end

# find all divisors of a target number
def find_divisors(number)
  # 1 is always a divisor
  divisors = [1]
  if number > 1
    # number is also always a divisor
    divisors << number
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

divisors = []
triangles = [1]
number = 2
limit = 1
while limit < 500
  while divisors.size <= limit
    triangle = triangles[number-2] + number
    triangles << triangle
    divisors = find_divisors(triangle)
=begin
    print("number: #{number}, triangle: #{triangle}=>")
    print_array triangles
    puts("divisors:")
    print_array divisors
=end
    number += 1
  end
  puts("First that reach #{divisors.size}: number #{number-1}, triangle #{triangle}")
  limit = divisors.size + 1
end
