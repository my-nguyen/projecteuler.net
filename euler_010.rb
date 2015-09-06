# Summation of primes
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
#
# The Sieve of Eratosthenes algorithm developed in Euler #7 was used here to
# yield marvelous result:
# Prime below     Sum             Pre-Sieve     Post-Sieve
# 10              17              0
# 100000          454396537       12
# 500000          9914236195      274
# 1000000         37550402023     1007
# 1500000         82074443256     2201
# 2000000         142913828922    3850
#
def get_primes(target)
  primes = Array.new(target+1, true)

  # numbers 0 and 1 are not primes
  primes[0] = false
  primes[1] = false

  # start with 2, the very first prime number
  2.upto(target) do |index|
    # only consider prime numbers
    if primes[index]
      multiple = 2
      while (index*multiple <= target)
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

targets = [10, 100000, 500000, 1000000, 1500000, 2000000]
# targets = [100000]
targets.each do |target|
  primes = pack_primes(get_primes(target))
  puts("Sum primes(#{target}): #{primes.reduce(:+)}")
end
