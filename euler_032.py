import math

# this class is used to retain the pair of multiplicand and multiplier of a product
class Pair:
  def __init__(self, left, right):
    self.first = left
    self.second = right

# this class keeps tracks of which of the 9 digits (from 1 to 9) in a number
# have been used
class Flags:
  # this method marks the digits in number as ON
  def mask(self, number):
    for digit in map(int, list(str(number))):
      self.data[digit] = True
    return self

  # this method counts all the ON digits
  def count(self):
    count = 0
    # skip digit 0
    for i in range(1, ALL_DIGITS):
      if (self.data[i]):
        count += 1
    return count

  # constructor
  def __init__(self, rhs = None):
    # @data = rhs.nil? Array.new(ALL_DIGITS, false) : rhs.data.dup
    self.data = ([False]*ALL_DIGITS) if (rhs is None) else rhs.data[:]

# this method returns a list of all divisors of a product number
def factors(number):
  divisors = []
  # 1 is always a divisor
  divisors.append(1)

  if (number > 1):
    # target number is also always a divisor
    divisors.append(number)
    # start looking for other divisors from 2 on up.
    i = 2
    while (i <= int(math.sqrt(number))):
      # if number is evenly divisible by i, then retain i
      if (number % i == 0):
        divisors.append(i)
        # possibly also retain the division of number/i.
        if (i != number/i):
          divisors.append(number/i)
      i += 1
    divisors.sort()
  return divisors

# this method returns a list of pairs of <multiplicand, multiplier> from a
# list of factors
def pairs(factors):
  pairs = []
  # only have to iterate thru half the list of factors, since beyond the
  # halfway line has already been accounted for in the pairs
  for i in range(len(factors)/2):
    pairs.append(Pair(factors[i], factors[-1]/factors[i]))
  return pairs

ALL_DIGITS = 10
# some products can be obtained more than one way, so using a Set will
# remove the duplicate products
pandigital = set()
# there's a total of 9 digits (1 to 9). how many digits must a product have?
# if it has 3 digits or less, then the pair of <multiplicand, multiplier>
# must have at least 6 digits combined, which is impossible. if it has 5
# digits or more, then <multiplicand, multiplier> must have at most 4
# digits combined, which is also impossible. therefore, a product has to
# have a 4 digits. the lower bound is just the smallest 4-digit number with
# all 4 distinct digits: 1234. similarly, the upper bound is just the
# highest 4-digit number with all 4 distinct digit: 9876
for product in range(1234, 9876):
  flags = Flags()
  flags.mask(product)
  # make sure product doesn't include 0
  if (flags.count() == 4):
    # process each pair of <multiplicand, multiplier>
    for pair in pairs(factors(product)):
      first = str(pair.first)
      second = str(pair.second)
      # make sure the pair of <multiplicand, multiplier> have 5 digits combined
      if (len(first) + len(second) == 5):
        # make a copy of flags
        copy = Flags(flags)
        copy.mask(first).mask(second)
        # all 9 digits are filled: a pandigital is found
        if (copy.count() == 9):
          pandigital.add(product)
          print("%s x %s = %d" %(first, second, product))

total = 0
for product in pandigital:
  total += product
print "Sum of all products:", total
