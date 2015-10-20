import math

# this method returns a list of all proper divisors of n (numbers less than n
# which divide evenly into n)
def proper_divisors(number):
  factors = []
  # 1 is always a divisor
  factors.append(1)
  if (number > 1):
    # start looking for other divisors from 2 on up.
    i = 2
    while (i <= int(math.sqrt(number))):
      # if number is evenly divisible by i, then retain i, and possibly also
      # the division of number/i.
      if (number % i == 0):
        factors.append(i)
        if (i != number/i):
          factors.append(number/i)
      i += 1
    factors.sort()
  return factors

LIMIT = 28123

# calculate all abundant numbers from 1 to the LIMIT
abundants = []
for i in range(1, LIMIT):
  # an abundant number is one where the sum of all the proper divisors of
  # the number is greater than the number
  if (sum(proper_divisors(i)) > i):
    abundants.append(i)

# take all the sums of any 2 abundant numbers within LIMIT
# fortunately Ruby array has the ability to initialize upon construction
abundant_sums = [False] * LIMIT
for i in range(len(abundants)):
  for j in range(len(abundants)):
    # sum of any 2 abundant numbers, both of which must be within LIMIT
    sum = abundants[i] + abundants[j]
    # the sum must also be within LIMIT
    if (sum < LIMIT):
      # flag this number as the sum of some 2 abundant numbers
      abundant_sums[sum] = True

# take the sum of all numbers that are not the sums of 2 abundant numbers
result = 0
for i in range(len(abundant_sums)):
  # any unflagged number within LIMIT
  if (not abundant_sums[i]):
    # take the sum of all those unflagged numbers
    result += i

print("result: %d" %result)
