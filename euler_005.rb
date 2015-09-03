# Smallest multiple
# 2520 is the smallest number that can be divided by each of the numbers from 1
# to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the
# numbers from 1 to 20?
#
# greatest common divisor of 2 integers
def gcd(one, two)
  while (one != 0)
    tmp = one
    one = two % one
    two = tmp
  end
  two
end

# least common multiple of 2 integers
def lcm(one, two)
  (one * two) / gcd(one, two)
end

# least common multiple of an array of more than 2 integers
def lcm_array(array)
  multiple = lcm(array[0], array[1])
  2.upto(array.size-1) do |i|
    multiple = lcm(multiple, array[i])
  end
  multiple
end

# fill array with 20 integers from 1 to 20
array = []
20.times do |i|
  array[i] = i+1
end

# test with different sizes
sizes = [5, 10, 15, 20]
sizes.each do |size|
  puts("LCM(1..#{size}): #{lcm_array(array[0, size])}")
end
