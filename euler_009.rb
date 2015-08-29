# Special Pythagorean triplet
# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
# a**2 + b**2 = c**2
# For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product a*b*c.
#
# According to Wikipedia, Euclid's formula is a fundamental formula for
# generating Pythagorean triples given an arbitrary pair of positive integers
# m and n with m > n. The formula states that the integers
# a = m*m - n*n
# b = 2*m*n
# c = m*m + n*n
# This function returns the sum of a+b+c
# a + b + c = m*m - n*n + 2*m*n + m*m + n*n, or 2*m*(m+n)
def sum_abc(m, n)
  2 * m * (m + n)
end

def pythagorean_triplets
  m = 0
  # since c = m*m + n*n, and a+b+c = 1000, both m*m and n*n must be < 1000,
  # or m <= 31 and n <= 31
  while (m <= 31)
    m += 1
    n = 1
    # calculate all sums of a+b+c based on m and n between 1 and 31.
    while (n <= 31)
      sum = sum_abc(m, n)
      if sum < 1000
        # keep trying with the next n
        n += 1
      elsif sum == 1000
        # m and n are found. return immediately the product of a*b*c
        return [(m*m - n*n).abs, (2*m*n), (m*m + n*n)]
      else
        # the largest n is reached. let's restart with the next m and n being 1
        break
      end
    end
  end
end

triplet = pythagorean_triplets
puts("product: #{triplet.reduce(1, :*)} from #{triplet}")
