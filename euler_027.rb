require './sieve.rb'

# n*n + a*n + b
# where n < 80, a < 1000 and b < 1000. so max of that expression is
# 80*80 + 1000*80 + 1000 = 87400
primes = Sieve.new(87400)
max_a = 0
max_b = 0
# currently we know n = 40 when a = 1 and b = 41
max_n = 40
# iterate over all possibilities for a
(-999..999).each do |a|
  # iterate over all possibilities for b
  (-999..999).each do |b|
    # look for a series of consecutive primes starting with n = 0
    n = 0
    while (primes.is_prime((n*n + a*n + b).abs))
      n += 1
    end

    # did we find a bigger series than the current one?
    if (n > max_n)
      max_a = a;
      max_b = b;
      max_n = n;
    end
  end
end

puts("a: #{max_a}, b: #{max_b}, n: #{max_n}, product: #{(max_a*max_b)}")
