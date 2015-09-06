# 10001st prime
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
# What is the 10001st prime number?
#
# Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
# up to a target number
# This algorithm proves to be a vast improvement on my older prime-finding
# algorithm: while the older version took 13 seconds, this new version took
# less than 1 second.
# This method finds all prime numbers from 2 up to size and stores them in an
# array, with prime numbers represented as ON bit and non-prime as OFF
def get_primes()
  # first initialize all elements in array to TRUE
  primes = Array.new(SIZE+1, true)

  # numbers 0 and 1 are not primes
  primes[0] = false
  primes[1] = false

  # start with 2, the very first prime number
  2.upto(SIZE) do |index|
    # only consider prime numbers
    if primes[index]
      multiple = 2
      while (index*multiple <= SIZE)
        # all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes
        primes[index*multiple] = false
        multiple += 1
      end
    end
  end
  primes
end

# this method converts an array of booleans, where ON elements represent prime
# numbers and OFF otherwise, into an array of prime numbers
def pack_primes(primes)
  result = []
  primes.each_index do |i|
    result << i if primes[i]
  end
  result
end

# reverse engineer: since I already solved this problem using a not-so-efficient
# algorithm to find primes (which took 13 seconds), I know the answer to be
# 104743, so I just have to declare array size as 105000
SIZE = 105000
primes = pack_primes(get_primes)
targets = [6, 11, 101, 1001, 10001]
targets.each do |target|
  puts("prime(#{target}): #{primes[target+1]}")
end
