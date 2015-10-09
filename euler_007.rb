require './sieve.rb'

def worst_prime(number)
  if (number == 2)
    return true
  end
  # only consider odd divisors from 3 up to half the test number
  (3..(number/2)).step(2) do |i|
    if (number % i == 0)
      return false
    end
  end
  true
end

def worst_index(position)
  # only consider numbers greater than 3
  result = 3
  # first two prime numbers (2 and 3) are already accounted for
  incr = 2
  while (incr < position)
    # only consider odd numbers
    result += 2
    if (worst_prime(result))
      incr += 1
    end
  end
  result
end

def sieve2_prime(number)
  if (number == 2)
    return true
  end
  if (number % 2 == 0)
    return false
  end
  i = 3
  while (i*i <= number)
    if (number % i == 0)
      return false
    end
    i += 2
  end
  true
end

def sieve2_index(position)
  result = 1
  j = 1
  while (j < position)
    result += 2
    if (sieve2_prime(result))
      j += 1
    end
  end
  result
end

def sieve3_index(position)
  primes = []
  primes << 2
  result = 1
  while (primes.size < position)
    # only consider odd numbers
    result += 2
    found = true
    # result = 3, primes = [2], j = 0, primes[0]*primes[0] > 3 ==> prime
    # result = 5, primes = [2, 3], j = 0, result%primes[0] == 1
    #                              j = 1, primes[1]*primes[1] > 5 ==> prime
    # result = 7, primes = [2, 3, 5], j = 0, result%primes[0] == 1
    #                                 j = 1, primes[1]*primes[1] > 7 ==> prime
    # result = 9, primes = [2, 3, 5, 7], j = 0, result%primes[0] == 1
    #                                    j = 1, result%primes[1] == 0 ==> not prime
    j = 0
    while (found && j < primes.size && primes[j]*primes[j] <= result)
      if (result % primes[j] == 0)
        found = false
      end
      j += 1
    end

    if (found)
      primes << result
    end
  end
  result
end

targets = [ 6, 11, 101, 1001, 10001, 50001 ]
sizes = [ 20, 40, 600, 8000, 105000, 612000 ]
=begin
targets.each do |target|
  puts("Worst(#{target}): #{worst_index(target)}")
end
=end
sizes.each_index do |i|
  sieve = Sieve.new(sizes[i])
  puts("Sieve(#{targets[i]}): #{sieve.index(targets[i])}")
end
targets.each do |target|
  puts("Modified Sieve(#{target}): #{sieve2_index(target)}")
end
targets.each do |target|
  puts("Improved Sieve(#{target}): #{sieve3_index(target)}")
end
