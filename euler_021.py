import math

# this method returns a list of all proper divisors of n (numbers less than n
# which divide evenly into n)
def divisors(number):
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

MAX_AMICABLE = 10000
pairs = []
for i in range(1, MAX_AMICABLE+1):
  # take the sum of all divisors of the current number (i)
  total = sum(divisors(i))
  # only need to check for a possible pair if sum is greater than i
  if (total > i):
    # take the sum of all divisors of the sum, and see if that equals the
    # current number (i)
    if (sum(divisors(total)) == i):
      print("%d and %d" %(i, total))
      pairs.append(i)
      pairs.append(total)

print("sum: %d" %sum(pairs))
