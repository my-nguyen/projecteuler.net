# Sum square difference
# The sum of the squares of the first ten natural numbers is,
# 1^2 + 2^2 + ... + 10^2 = 385
# The square of the sum of the first ten natural numbers is,
# (1 + 2 + ... + 10)^2 = 55^2 = 3025
# Hence the difference between the sum of the squares of the first ten natural
# numbers and the square of the sum is 3025 − 385 = 2640.
# Find the difference between the sum of the squares of the first one hundred
# natural numbers and the square of the sum.
#
def sum_squares(max)
  sum = 0
  1.upto(max) do |n|
    sum += n**2
  end
  sum
end

def square_sum(max)
  sum = 0
  1.upto(max) do |n|
    sum += n
  end
  sum ** 2
end

n = 10
puts("Difference(#{n}): #{square_sum(n) - sum_squares(n)}")
n = 100
puts("Difference(#{n}): #{square_sum(n) - sum_squares(n)}")
