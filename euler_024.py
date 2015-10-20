# For explanations of the solution to this problem, refer to
# http://www.davidespataro.it/project-euler-problem-24/
# http://mahendrakariya.blogspot.com/2009/08/project-euler-problem-24-different.html
# http://www.mathblog.dk/project-euler-24-millionth-lexicographic-permutation/
# http://blog.singhanuvrat.com/problems/project-euler-the-millionth-lexicographic-permutation-of-the-digits
# http://math.stackexchange.com/questions/60742/finding-the-n-th-lexicographic-permutation-of-a-string
# http://www.eggwall.com/2012/01/project-euler-in-r-problem-24.html
# https://www.quora.com/What-is-the-most-efficient-solution-for-Project-Euler-problem-24-in-C-or-C++
def factorial(number):
  product = 1
  for i in range(1, number+1):
    product *= i
  return product

# this method returns the largest number whose factorial is under a limit
def largest(limit):
  i = 1
  while (factorial(i) <= limit):
    i += 1
  return i - 1

# this method returns the proper index to an array of boolean's based on a
# target and the ON and OFF elements in the array
def rank(used, target):
  count = 0
  i = 0
  while (i < len(used) and count <= target):
    if (not used[i]):
      count += 1
    i += 1
  return i-1

# this method collects the index of all OFF elements in a boolean array and
# returns that collection as a String
def unused(used):
  result = ""
  for i in range(len(used)):
    if (not used[i]):
      result += chr(i + ord('0'))
  return result

limits = [ 100, 1000, 10000, 100000, 1000000, 119, 120, 121 ]
for limit in limits:
  permutation = ""
  index = largest(limit)
  print("limit: %d, over: %d, factorial: %d" %(limit, (index+1), factorial(index+1)))
  # array of booleans all initialized to false
  used = [False] * (index+1)

  while (index >= 1):
    # how many factorial(index) does it take to reach just below limit?
    divisor = limit / factorial(index)
    # adjust divisor when limit evenly divides factorial(index)
    if (limit % factorial(index) == 0):
      divisor -= 1
    # calculate the proper placement/index of this divisor within the bool array
    digit = rank(used, divisor)
    # mark the bool array accordingly
    used[digit] = True
    # collect this index in the permutation
    permutation += chr(digit + ord('0'))
    print("limit: %d, index: %d, factorial: %d, divisor: %d, digit: %d, permutation: %s" %(limit, index, factorial(index), divisor, digit, permutation))
    # calculations for the next iteration
    if (limit % factorial(index) == 0):
      limit = factorial(index)
    else:
      limit %= factorial(index)
    index -= 1
  permutation += unused(used)

  print "permutation:", permutation
