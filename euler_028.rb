# this method returns the sum of all numbers in a list
def sum(list)
  list.inject(:+)
end

def spiral(size)
  increment = 2
  # special case: 1x1 spiral
  current = 1
  # the numbers on the 4 diagonals happen to be the numbers at the 4
  # corners of every spiral.
  corners = []
  corners << current
  # start from 3x3 spiral, advance to 5x5, 7x7, 9x9, etc spirals
  (3..size).step(2) do |i|
    # collect all 4 corners of the current spiral
    4.times do |j|
      current += increment
      corners << current
    end
    # next spiral is 2 units larger than the current one
    increment += 2
  end
  sum(corners)
end

# refer to: http://www.mathblog.dk/project-euler-28-sum-diagonals-spiral/
# n is ring number, starting from 0
# for n = 0, ring is:
# 1
# for n = 1, ring is:
# 7 8 9
# 6   2
# 5 4 3
# for n = 2, ring is
# 21 22 23 24 25
# 20          10
# 19          11
# 18          12
# 17 16 15 14 13
# f(n) is the sum of diagonals for the the rings up to and including n.
# special case for n = 0, f(0) = 1
# for other n:
# the sides of a ring is 2n+1 wide
# the upper right corner in the ring is (2n+1)^2
# moving counter clockwise, the second corner is (2n+1)^2 - 2n
# the third corner is (2n+1)^2 - 4n
# the fourth corner is (2n+1)^2 - 6n
# so the sum of all 4 corners is:
# (2n+1)^2 + (2n+1)^2 - 2n + (2n+1)^2 - 4n + (2n+1)^2 - 6n, or
# 4(2n+1)^2 - 12n
# so f(n) = 4(2n+1)^2 - 12n + f(n-1)
def formula(size)
  # f(0) = 1
  previous = 1
  # instead of advancing as 3, 5, 7 (in reference to 3x3, 5x5, 7x7 spirals),
  # we advance as 1, 2, 3
  (1..(size-1)/2).each do |i|
    # from formula for f(n) above
    current = 4*((2*i+1)**2) - 12*i + previous
    previous = current
  end

  previous
end

sizes = [ 5, 11, 101, 501, 1001 ]
sizes.each do |size|
  puts("Sum(#{size}): #{spiral(size)}")
end
sizes.each do |size|
  puts("Formula(#{size}): #{formula(size)}")
end
