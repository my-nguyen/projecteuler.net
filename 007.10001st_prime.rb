# 10001st prime
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
# What is the 10001st prime number?
#
require 'benchmark'

def prime?(number)
  # only consider odd divisors from 3 up to half the test number
  (3..(number/2)).step(2) do |n|
    if (number % n == 0)
       return false
    end
  end
  true
end

def nth_prime(max)
  # only consider numbers greater than 3
  i = 3
  # first two prime numbers (2 and 3) are already accounted for
  prm = 2
  time = Benchmark.realtime do
    while (prm < max)
      # only consider odd numbers
      i += 2
      prm += 1 if prime?(i)
    end
  end
  time = time.to_i
  puts "Time: #{time/60} minutes #{time%60} seconds"
  i
end

puts("prime(10001): #{nth_prime(10001)}")
