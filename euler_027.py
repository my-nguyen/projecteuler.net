from sieve import Sieve

# n*n + a*n + b
# where n < 80, a < 1000 and b < 1000. so max of that expression is
# 80*80 + 1000*80 + 1000 = 87400
primes = Sieve(87400)
max_a = 0
max_b = 0
# currently we know n = 40 when a = 1 and b = 41
max_n = 40
# iterate over all possibilities for a
for a in range(-999, 999):
  # iterate over all possibilities for b
  for b in range(-999, 999):
    # look for a series of consecutive primes starting with n = 0
    n = 0
    while (primes.is_prime(abs(n*n + a*n + b))):
      n += 1

    # did we find a bigger series than the current one?
    if (n > max_n):
      max_a = a;
      max_b = b;
      max_n = n;

print("a: %d, b: %d, n: %d, product: %d" %(max_a, max_b, max_n, (max_a*max_b)))
