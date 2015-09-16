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

targets = [10, 50, 100]
targets.each do |target|
  puts("Difference(#{target}): #{square_sum(target) - sum_squares(target)}")
end
