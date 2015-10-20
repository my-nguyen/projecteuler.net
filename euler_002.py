# for an explanation to the "Even Only" solution, refer to:
# http://www.mathblog.dk/project-euler-problem-2/
def mine_sum(limit):
  fib1 = 1
  fib2 = 1
  fib3 = 0
  sum = 0
  while True:
    fib3 = fib1 + fib2
    if (fib3 >= limit):
      break
    else:
      # take the sum of only even fibonacci numbers
      if (fib3 % 2 == 0):
        sum += fib3
      fib1 = fib2
      fib2 = fib3

  return sum

# Fn = Fn-1 + Fn-2 =
# Fn-2 + Fn-3 + Fn-3 +Fn-4 = (since Fn-1 = Fn-2 + Fn-3 and so on)
# Fn-3 + Fn-4 + Fn-3 +Fn-3 +Fn-4 = 3Fn-3 + 2Fn-4 =
# 3Fn-3 + Fn-4 + Fn-5 + Fn-6) =
# 4Fn-3 + Fn-6 (since Fn-4 + Fn-5 = Fn-3)
def even_sum(limit):
  fib3 = 2
  fib6 = 0
  result = 2
  sum = 0
  while (result < limit):
    sum += result
    result = 4*fib3 + fib6
    fib6 = fib3
    fib3 = result

  return sum

limit = 4000000
print "Mine:", mine_sum(limit)
print "Even only:", even_sum(limit)
