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

# Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
# up to a target number. This algorithm proves to be a vast improvement on my
# older prime-finding algorithm: while the older version took 13 seconds,
# this new version took less than 1 second.
# This constructor fills an array of bools from 2 to order, with prime
# numbers marked as ON bit and non-prime as OFF
def sieve_init(position)
  # the 100th prime is 541, the 1000th prime is 7919, the 10000th prime is
  # 104729, the 100000th prime is 1299709 so size is roughly 13 times the
  # prime number/position
  # initialize all bits to ON
  field = Array.new(position*13, true)

  # numbers 0 and 1 are not primes
  field[0] = false
  field[1] = false
  # start with 2, the very first prime number
  2.upto(position*13) do |i|
    # test whether bit at i is ON
    if (field[i])
      multiple = 2
      while (i*multiple < field.size)
        # all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        # So turn off bit at (i*multiple)th position.
        field[i*multiple] = false
        multiple += 1
      end
    end
  end
  field
end

# this method returns the natural number of the prime number at position.
# for example, for prime at position 100, it returns 541. for prime at 1000,
# it returns 7919. for prime at 5000, it returns 48611.
def sieve_index(position)
  field = sieve_init(position)
  # index to the entire bool array
  result = 1
  # index by prime numbers
  j = 1
  while (j < position)
    result += 2
    if (field[result])
      j += 1
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
targets.each do |target|
  puts("Worst(#{target}): #{worst_index(target)}")
end
targets.each do |target|
  puts("Sieve(#{target}): #{sieve_index(target)}")
end
targets.each do |target|
  puts("Modified Sieve(#{target}): #{sieve2_index(target)}")
end
targets.each do |target|
  puts("Improved Sieve(#{target}): #{sieve3_index(target)}")
end
