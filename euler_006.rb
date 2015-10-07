def mine_square_sum(max)
  sum = 0
  1.upto(max) do |i|
    sum += i
  end
  sum ** 2
end

def mine_sum_squares(max)
  sum = 0
  1.upto(max) do |i|
    sum += i**2
  end
  sum
end

# 1+2+3+4+…+N = N*(N+1)/2
def arith_square_sum(max)
  sum = max * (max+1) / 2
  sum ** 2
end

# sum of squares = N*(N+1)*(2*N+1)/6;
def arith_sum_squares(max)
  max * (max+1) * (2*max+1) / 6
end

targets = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
targets.each do |target|
  puts("Mine(#{target}): #{mine_square_sum(target) - mine_sum_squares(target)}")
end
targets.each do |target|
  puts("Arithmetic(#{target}): #{arith_square_sum(target) - arith_sum_squares(target)}")
end
