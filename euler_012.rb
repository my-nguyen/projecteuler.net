# this method returns a list of all divisors of a target number
def get_divisors(number)
  divisors = []
  # 1 is always a divisor
  divisors << 1

  if (number > 1)
    # target number is also always a divisor
    divisors << number
    # start looking for other divisors from 2 on up.
    i = 2
    while (i <= Math.sqrt(number).to_i)
      # if number is evenly divisible by i, then retain i
      if (number % i == 0)
        divisors << i
        # possibly also retain the division of number/i.
        if (i != number/i)
          divisors << number/i
        end
      end
      i += 1
    end
    divisors.sort!
  end
  divisors
end

triangles = []
# special case when number == 1: its triangle number is also 1
triangles << 1
# skip 1 and start with 2
number = 2
# initially target is set to 1. then while incrementing (natural) number,
# take its triangle number, then take all the divisors of the triangle
# number. once the count of divisors becomes greater than or equal to
# target, then a new target is set by adding 1 to the divisor count. keep
# this cycle until divisor count reaches at least 500. note the target gets
# increased pretty fast as shown in the resulting number of divisors:
# 2, 4, 6, 9, 16, 18, 20, 24, 36, 40, 48, 90, 112, 128, 144, 162, 168, 192,
# 240, 320, 480, 576, etc.
target = 1
# eventual target is 500
while (target < 500)
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
  triangle = 0
  # in each iteration, the goal is to find a natural number whose triangle
  # number has a divisor count that is greater than or equal target.
  while (divisors.size() <= target)
    # triangle is the sum of the previous entry and current number
    triangle = triangles[number-2] + number
    # retain that sum
    triangles << triangle
    # get all divisors for that sum
    divisors = get_divisors(triangle)
    # go to next number
    number += 1
  end
  puts("Target: #{target}, actual: #{divisors.size()}, number: #{(number-1)}, triangle: #{triangle}")
  # set a new target based on the divisor count of the current triangle
  target = divisors.size() + 1
end
