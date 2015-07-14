# Summation of primes
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
#
require 'benchmark'

def prime?(number)
  # only consider odd divisors from 3 up to half the test number
  (3..(number/2)).step(2) do |n|
    return false if (number % n == 0)
  end
  # puts("#{number} is prime")
  true
end

def fill_primes(max)
  # first 2 prime numbers (2 and 3) are already accounted for
  primes = [2, 3]
  # only consider numbers greater than 3
  i = 5
  while (i < max)
    # save a prime number
    primes << i if prime?(i)
    # only odd numbers can be candidates for prime
    i += 2
  end
  primes
end

maxima = [10, 2000000]
maxima.each do |maximum|
  Benchmark.bm do |bm|
    primes = []
    bm.report do
      primes = fill_primes(maximum)
    end
    bm.report do
      puts("Sum primes(#{maximum}): #{primes.reduce(:+)}")
    end
  end
end
