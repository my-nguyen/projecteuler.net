# test up to 1 million only
targets = [10, 100, 1000, 10000, 100000, 1000000]
targets = [13915, 475143, 1475143, 51475143, 851475143, 1851475143, 10851475143, 600851475143]
targets = [851475143]
targets = [1475143, 51475143]
targets.each do |target|
  # Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
  # up to a target number
  #
  # First create an array of booleans, initializing all its elements to true
  # primes = Array.new(target+1) { |i| true }
  primes = Array.new(target+1, true)
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

  puts("target: #{target}, highest prime: #{primes.rindex(true)}")
=begin
  j = 1
  2.upto(primes.size) do |i|
    if primes[i]
      print(" #{i}")
      puts if (j % 10 == 0)
      j += 1
    end
  end
  puts
=end
end
