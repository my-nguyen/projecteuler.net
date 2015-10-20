require 'set'

# this class is used to retain the pair of multiplicand and multiplier of a product
class Pair
  attr_accessor :first, :second
  def initialize(left, right)
    @first = left
    @second = right
  end
end

# this class keeps tracks of which of the 9 digits (from 1 to 9) in a number
# have been used
class Flags
  attr_accessor :data
  ALL_DIGITS = 10

  # this method marks the digits in number as ON
  def mask(number)
    number.to_s.chars.map(&:to_i).each do |digit|
      @data[digit] = true
    end
    self
  end

  # this method counts all the ON digits
  def count()
    count = 0
    # skip digit 0
    (1..(ALL_DIGITS-1)).each do |i|
      if (@data[i])
        count += 1
      end
    end
    count
  end

  # constructor
  def initialize(rhs = nil)
    # @data = rhs.nil? Array.new(ALL_DIGITS, false) : rhs.data.dup
    if rhs.nil?
      @data = Array.new(ALL_DIGITS, false)
    else
      @data = rhs.data.dup
    end
  end
end

# this method returns a list of all divisors of a product number
def factors(number)
  divisors = []
  # 1 is always a divisor
  divisors << 1
  if number > 1
    # target number is also always a divisor
    divisors << number
    # start looking for other divisors from 2 on up.
    i = 2
    while (i <= Math.sqrt(number).to_i)
      # if number is evenly divisible by i, then retain i, and possibly also
      # the division of number/i.
      if (number % i == 0)
        divisors << i
        divisors << number/i if (i != number/i)
      end
      i += 1
    end
    divisors.sort!
  end
  divisors
end

# this method returns a list of pairs of <multiplicand, multiplier> from a
# list of factors
def pairs(factors)
  pairs = []
  # only have to iterate thru half the list of factors, since beyond the
  # halfway line has already been accounted for in the pairs
  (factors.size/2).times do |i|
    pairs << Pair.new(factors[i], factors.last/factors[i])
  end
  pairs
end

# some products can be obtained more than one way, so using a Set will
# remove the duplicate products
pandigital = Set.new
# there's a total of 9 digits (1 to 9). how many digits must a product have?
# if it has 3 digits or less, then the pair of <multiplicand, multiplier>
# must have at least 6 digits combined, which is impossible. if it has 5
# digits or more, then <multiplicand, multiplier> must have at most 4
# digits combined, which is also impossible. therefore, a product has to
# have a 4 digits. the lower bound is just the smallest 4-digit number with
# all 4 distinct digits: 1234. similarly, the upper bound is just the
# highest 4-digit number with all 4 distinct digit: 9876
(1234..9876).each do |product|
  flags = Flags.new
  flags.mask(product)
  # make sure product doesn't include 0
  if (flags.count() == 4)
    # process each pair of <multiplicand, multiplier>
    pairs(factors(product)).each do |pair|
      first = pair.first.to_s
      second = pair.second.to_s
      # make sure the pair of <multiplicand, multiplier> have 5 digits combined
      if (first.length() + second.length() == 5)
        # make a copy of flags
        copy = Flags.new(flags)
        copy.mask(first).mask(second)
        # all 9 digits are filled: a pandigital is found
        if (copy.count() == 9)
          pandigital.add(product)
          puts("#{first} x #{second} = #{product}")
        end
      end
    end
  end
end

sum = 0
pandigital.each do |product|
  sum += product
end
puts("Sum of all products: #{sum}")
