# Special Pythagorean triplet
# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
# a**2 + b**2 = c**2
# For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product a*b*c.
#
# According to Wikipedia's Euclid's formula for generating most triplets:
# a = m**2 - n**2
# b = 2*m*n
# c = m**2 + n**2
# a + b + c = m**2 - n**2 + 2*m*n + m**2 + n**2, or 2*m*(m+n)
def sum_abc(m, n)
  2 * m * (m + n)
end

def pythagorean_triplets
  m = 0
  # since c = m**2 + n**2, and a+b+c = 1000, both m**2 and n**2 must be < 1000,
  # or m <= 31 and n <= 31
  while (m <= 31)
    m += 1
    n = 1
    while (n <= 31)
      sum = sum_abc(m, n)
      if sum < 1000
        n += 1
      elsif sum == 1000
        return [(m*m - n*n).abs, (2*m*n), (m*m + n*n)]
      else
        break
      end
    end
  end
end

triplet = pythagorean_triplets
puts("product: #{triplet.reduce(1, :*)} from #{triplet}")
