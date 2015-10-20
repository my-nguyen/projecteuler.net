# Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
# up to a target number.
# class name must begin with a capital letter
class Sieve:
  # the 101st prime is 547
  # the 1,001st prime is 7,927
  # the 10,001st prime is 104,743
  # the 50,001st prime is 611,957
  # This constructor fills an array of bools up to a certain size, with prime
  # numbers marked as ON bit and non-prime as OFF
  def __init__(self, size):
    # initialize all bits to ON
    self.field = [True]*size

    # numbers 0 and 1 are not primes
    self.field[0] = False
    self.field[1] = False

    # start with 2, the very first prime number
    for index in range(2, size):
      # test whether bit at i is ON
      if (self.field[index]):
        multiple = 2
        while (index*multiple < size):
          # all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
          # So turn off bit at (i*multiple)th position.
          self.field[index*multiple] = False
          multiple += 1

  # this method returns the natural number of the prime number at position. for
  # example, for the prime number at 100, it returns 541. for the prime number
  # at 1000, it returns 7919. for the prime number at 5000, it returns 48611.
  def index(self, position):
    # index to the entire bool array
    i = 1
    # index by prime numbers
    j = 0
    while (j < position):
      i += 1
      if (self.field[i]):
        j += 1
    return i

  # this method returns the sum of all prime numbers in the bool array.
  def sum(self):
    sum = 2
    # sum includes 2, the first prime number (at index 0) so that index i
    # (which starts at 1) can increment by 2
    for i in range(1, len(self.field), 2):
      if (self.field[i]):
        sum += i
    return sum

  def is_prime(self, number):
    return self.field[number]
