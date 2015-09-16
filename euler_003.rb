# In other words: Given a number, find the largest divisor that is also a prime
#
def largest_prime(target)
  prime = 2
  while (target > prime)
    # if target is divisible by the current prime, then keep dividing
    # target by the current prime
    if (target % prime == 0)
      target /= prime
    # otherwise move on to the next number
    else
      prime += 1
    end
  end
  prime
end

targets = [13915, 475143, 1475143, 51475143, 1851475143, 10851475143, 600851475143]
# targets = [851475143]
# targets = [3239, 16843009, 13915, 475143]
targets.each do |target|
  # puts("Factors of #{target}: #{divisors}")
  # puts("Largest prime factor of #{target}: #{largest_prime(divisors)}")
  puts("target: #{target}, largest prime: #{largest_prime(target)}")
end
