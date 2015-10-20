def mine_square_sum(max):
  sum = 0
  for i in range(1, max+1):
    sum += i
  return sum**2

def mine_sum_squares(max):
  sum = 0
  for i in range(1, max+1):
    sum += i**2
  return sum

# 1+2+3+4+...+N = N*(N+1)/2
def arith_square_sum(max):
  sum = max * (max+1) / 2
  return sum**2

# sum of squares = N*(N+1)*(2*N+1)/6;
def arith_sum_squares(max):
  return max * (max+1) * (2*max+1) / 6

targets = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
for target in targets:
  print("Mine(%d): %d" %(target, mine_square_sum(target)-mine_sum_squares(target)))
for target in targets:
  print("Arithmetic(%d): %d" %(target, arith_square_sum(target)-arith_sum_squares(target)))
