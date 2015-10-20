def mine_sum(limit):
  multiples = []

  # collect all multiples of 3
  for j in range(1, (limit/3+1)):
    multiples.append(j * 3)

  # collect all multiples of 5
  for j in range(1, (limit/5+1)):
    if (j % 3 != 0):
      multiples.append(j * 5)

  return sum(multiples)

# sum of multiples of 3: 3+6+9+12+...+999 = 3*(1+2+3+4+...+333)
# whereas 1+2+3+4+...+N = N*(N+1)/2
# so sum of multiples of 3 is 3*(N*(N+1)/2) where N=999/3=333
# similarly, sum of multiples of 5 is 5*(N*(N+1)/2) where N=999/5=199
def sum_of_multiples(divisor, limit):
  n = limit/divisor
  return divisor * (n * (n+1) / 2)

def geo_sum(limit):
  return sum_of_multiples(3, limit) + sum_of_multiples(5, limit) - sum_of_multiples(15, limit)

limit = 999
print "Brute force:", mine_sum(limit)
print "Geometric:", geo_sum(limit)
