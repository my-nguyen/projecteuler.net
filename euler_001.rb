def sum(array)
  array.reduce(:+)
end

def mine_sum(limit)
  multiples = []

  # collect all multiples of 3
  1.upto(limit/3) do |j|
    multiples << j * 3
  end

  # collect all multiples of 5
  1.upto(limit/5) do |j|
    if (j % 3 != 0)
      multiples << j * 5
    end
  end

  sum(multiples)
end

# sum of multiples of 3: 3+6+9+12+…+999 = 3*(1+2+3+4+…+333)
# whereas 1+2+3+4+…+N = N*(N+1)/2
# so sum of multiples of 3 is 3*(N*(N+1)/2) where N=999/3=333
# similarly, sum of multiples of 5 is 5*(N*(N+1)/2) where N=999/5=199
def sum_of_multiples(divisor, limit)
  n = limit/divisor
  divisor * (n * (n+1) / 2)
end

def geo_sum(limit)
  sum_of_multiples(3, limit) + sum_of_multiples(5, limit) - sum_of_multiples(15, limit)
end

limit = 999
puts("Brute force: #{mine_sum(limit)}")
puts("Geometric: #{geo_sum(limit)}")
