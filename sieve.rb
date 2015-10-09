# Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
# up to a target number.
# class name must begin with a capital letter
class Sieve
  # the 20th prime is 71, the 200th prime is 1,223, the 2,000th prime is
  # 17,389, the 20,000th prime is 224,737, the 200,000th prime is 2,750,159,
  # and the 2,000,000th prime is 32,452,843 so the ratio of natural to prime
  # is roughly 17. round this ratio up to 20.
  NATURAL_2_PRIME = 20
  # This constructor fills an array of bools up to a certain size, with prime
  # numbers marked as ON bit and non-prime as OFF
  def initialize(position)
    @index = position
    size = position * NATURAL_2_PRIME
    # initialize all bits to ON
    @field = Array.new(size, true)

    # numbers 0 and 1 are not primes
    @field[0] = false
    @field[1] = false

    # start with 2, the very first prime number
    2.upto(size) do |index|
      # test whether bit at i is ON
      if @field[index]
        multiple = 2
        while (index*multiple <= size)
          # all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
          # So turn off bit at (i*multiple)th position.
          @field[index*multiple] = false
          multiple += 1
        end
      end
    end
    @field
  end

  # this method returns the natural number of the prime number at index. for
  # example, for the prime number at 100, it returns 541. for the prime number
  # at 1000, it returns 7919. for the prime number at 5000, it returns 48611.
  def index()
    # index to the entire bool array
    i = 1
    # index by prime numbers
    j = 0
    while (j < @index)
      i += 1
      j += 1 if @field[i]
    end
    i
  end

  # this method returns the sum of all the prime numbers within the bools array
  def sum()
    sum = 0
    # iterate the entire bools array
    @field.each_index do |i|
      # only add to sum if bools at i is ON
      sum += i if @field[i]
    end
    sum
  end
end
