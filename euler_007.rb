# 10001st prime
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
# What is the 10001st prime number?
#
# class name must begin with a capital letter
class Primes
  # Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
  # up to a target number
  # This algorithm proves to be a vast improvement on my older prime-finding
  # algorithm: while the older version took 13 seconds, this new version took
  # less than 1 second.
  # This method finds all prime numbers from 2 up to size and stores them in an
  # array, with prime numbers represented as ON bit and non-prime as OFF
  def initialize(size)
    # first initialize all elements in array to TRUE
    @bools = Array.new(size+1, true)

    # numbers 0 and 1 are not primes
    @bools[0] = false
    @bools[1] = false

    # start with 2, the very first prime number
    2.upto(size) do |index|
      # only consider prime numbers
      if @bools[index]
        multiple = 2
        while (index*multiple <= size)
          # all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes
          @bools[index*multiple] = false
          multiple += 1
        end
      end
    end
    @bools
  end

  # there's no need to create another array that contains only prime numbers
  # extracted from the array of bools (as in the previous version): Just look in
  # the array of bools for the target prime number.
  def index(target)
    # index to the entire bool array
    i = 1
    # index only up to target
    j = 0
    while (j < target)
      i += 1
      j += 1 if @bools[i]
    end
    i
  end
end

# reverse engineer: since I already solved this problem using a not-so-efficient
# algorithm to find primes (which took 13 seconds), I know the answer to be
# 104743, so I just have to declare array size as 105000
SIZE = 105000
primes = Primes.new(SIZE)
targets = [6, 11, 101, 1001, 2001, 3001, 4001, 5001, 6001, 7001, 8001, 9001, 10001]
targets.each do |target|
  puts("prime(#{target}): #{primes.index(target)}")
end
