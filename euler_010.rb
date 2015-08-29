# Summation of primes
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
#
require 'benchmark'

# user     system      total        real
# 0.000000   0.000000   0.000000 (  0.000015)
# Sum primes(10): 17
# user     system      total        real
# 12.420000   0.000000  12.420000 ( 12.425753)
# Sum primes(100000): 454396537
# user     system      total        real
# 274.430000   0.000000 274.430000 (274.588815)
# Sum primes(500000): 9914236195
# user     system      total        real
# 1007.150000   0.000000 1007.150000 (1007.677096)
# Sum primes(1000000): 37550402023
# user     system      total        real
# 2201.480000   0.000000 2201.480000 (2202.601856)
# Sum primes(1500000): 82074443256
# user     system      total        real
# 3850.580000   0.030000 3850.610000 (3853.315824)
# Sum primes(2000000): 142913828922
#
# bottleneck is in this method but so far I can't think of a way to improve
# performance yet.
def prime?(number)
  # only consider odd divisors from 3 up to half the target number
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
  Benchmark.bm do |bm|
    bm.report do
      while (i < max)
        # save a prime number
        primes << i if prime?(i)
        # only odd numbers can be candidates for prime
        i += 2
      end
    end
  end
  primes
end

maxima = [10, 100000, 500000, 1000000, 1500000, 2000000]
# maxima = [100000]
maxima.each do |maximum|
  primes = fill_primes(maximum)
  puts("Sum primes(#{maximum}): #{primes.reduce(:+)}")
end
