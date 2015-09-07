# 10001st prime
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
# What is the 10001st prime number?
#
require './primes.rb'
# reverse engineer: since I already solved this problem using a not-so-efficient
# algorithm to find primes (which took 13 seconds), I know the answer to be
# 104743, so I just have to declare array size as 105000
SIZE = 105000
primes = Primes.new(SIZE)
targets = [6, 11, 101, 1001, 2001, 3001, 4001, 5001, 6001, 7001, 8001, 9001, 10001]
targets.each do |target|
  puts("prime(#{target}): #{primes.index(target)}")
end
