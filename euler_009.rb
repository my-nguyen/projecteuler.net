# According to Wikipedia, Euclid's formula is a fundamental formula for
# generating Pythagorean triples given an arbitrary pair of positive integers
# m and n with m > n. The formula states that the integers
# a = m*m - n*n
# b = 2*m*n
# c = m*m + n*n

# This method returns the sum of a+b+c
# a + b + c = m*m - n*n + 2*m*n + m*m + n*n, or 2*m*(m+n)
def sum_abc(m, n)
  2 * m * (m + n)
end

# This method returns a pythagorean triplet [a, b, c] if such a triplet is found.
# if not it returns nil.
def pythagorean_triplets(target)
  m = 0
  # since c = m*m + n*n, and a+b+c = 1000, both m*m and n*n must be < 1000,
  # or m <= 31 and n <= 31
  while (m <= Math.sqrt(target))
    m += 1
    n = 1
    # calculate all sums of a+b+c based on m and n between 1 and 31.
    while (n <= Math.sqrt(target))
      sum = sum_abc(m, n)
      if sum < target
        # keep trying with the next n
        n += 1
      elsif sum == target
        # m equals n means (m*m - n*n).abs equals 0, OR a equals 0 and b equals c,
        # which violates the requirement a < b < c. since the largest n is reached,
        # restart with the next m and n at 1.
        if (m == n)
          break
        else
          # m and n are found. return immediately the triplet [a, b, c]
          return [(m*m - n*n).abs, (2*m*n), (m*m + n*n)].sort!
        end
      else
        # the largest n is reached. let's restart with the next m and n at 1
        break
      end
    end
  end

  # return nil if no such triplet is found
end

targets = [50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
# targets = [200, 500, 1000]
targets.each do |target|
  print("triplet(#{target}): ")
  triplet = pythagorean_triplets(target)
  if triplet.nil?
    puts("none found")
  else
    puts("product #{triplet.reduce(1, :*)} from #{triplet}")
  end
end
