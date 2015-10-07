# this method returns the least common multiple of 2 integers
# must declare parameter type and return type as long; otherwise an overflow
# would occur at one * two when one becomes too large.
def lcm(one, two)
  one.lcm(two)
end

# this method returns the least common multiple of an array of more than 2 integers
def mine_lcm(size)
  multiple = 2
  3.upto(size) do |i|
    multiple = lcm(multiple, i)
  end
  multiple
end

def brute_lcm(size)
  i = size
  j = 0
  while (j <= size)
    i += size
    j = 2
    while (j <= size)
      if (i % j != 0)
        break
      else
        j += 1
      end
    end
  end
  i
end

sizes = [ 5, 10, 15, 20 ]
sizes.each do |size|
  puts("Mine(#{size}): #{mine_lcm(size)}")
  puts("Brute force(#{size}): #{brute_lcm(size)}")
end
