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

# divisors contains all the divisors/factors of a triangle, for example:
# triangle  divisors
#      1    1
#      3    1,3
#      6    1,2,3,6
#     10    1,2,5,10
#     15    1,3,5,15
#     21    1,3,7,21
#     28    1,2,4,7,14,28
divisors = []
# let's start numbering at 2 instead of 1, which means triangles already contains
# number 1
number = 2
triangles = [1]
# in the beginning, target is set at 1, but as a target is reached, a new target
# is set by adding 1 to the number of divisors of the current triangle. since
# the number of divisors is an arbitrary number that is greater than the current
# target, the target gets increased pretty fast as shown in the resulting number
# of divisors:
# 2, 4, 6, 9, 16, 18, 20, 24, 36, 40, 48, 90, 112, 128, 144, 162, 168, 192, 240,
# 320, 480, 576.
target = 1
# eventual target
while target < 500
  while divisors.size <= target
    # triangle is the sum of the previous entry and current number
    triangle = triangles[number-2] + number
    # retain that sum
    triangles << triangle
    # get all divisors for that sum
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
  # set a new target based on the number of divisors of the current triangle
  target = divisors.size + 1
end
