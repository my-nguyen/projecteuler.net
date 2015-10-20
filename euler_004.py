# this method returns the reverse of a number.
def reverse(number):
  return int(str(number)[::-1])

# this method returns whether a number is a palindrome
def is_palindrome(number):
  return number == reverse(number)

# this method counts the number of digits in a number
def count_digits(number):
  return len(str(number))

# this method returns number 1, repeated as many times as specified in param
def repeat(times):
  return int("1" * times)

# this method finds the largest palindrome found in all products of 1-digit,
# 2-digit and 3-digit numbers
def mine_palindrome(target):
  result = [None]*2
  max = 1
  # use 2 indices: upper starts from target down to 1, and lower starts from
  # upper down to 1
  lower_bound = repeat(count_digits(target))
  for upper in range(target, lower_bound-1, -1):
    for lower in range(upper, lower_bound-1, -1):
      product = upper * lower
      if (is_palindrome(product) and product > max):
        max = product
        result[0] = lower
        result[1] = upper

  return result

# this method generates a palindrome by combining a number with its own reverse
def make_palindrome(first_half):
  forward = str(first_half)
  backward = forward[::-1]
  return int(forward + backward)

# this method is based on http://www.optimized.dk/project-euler-problem-4/
def optimized(target):
  result = [None]*2
  found = False
  index = target-1
  while (not found):
    # first create a fictional palindrome from index, e.g. 998899 from 998
    palindrome = make_palindrome(index)
    # then look for a number by which palindrome is evenly divisible
    for i in range(target, repeat(count_digits(target))-1, -1):
      # that number has to be between the square root of the palindrome(1)
      # and the target number(2)
      # (1) any factor less than the square root of the palindrome will have
      # a corresponding factor larger than the square root.
      # (2) problem requires the factor to be less than target
      if (i*i < palindrome or palindrome/i > target):
        break

      if (palindrome % i == 0):
        found = True
        result[0] = palindrome / i
        result[1] = i
        break

    index -= 1
  return result

targets = [99, 999, 9999]
for target in targets:
  result = mine_palindrome(target)
  print("Mine: %dx%d = %d" %(result[0], result[1], result[0]*result[1]))
for target in targets:
  result = optimized(target)
  print("Optimized: %dx%d = %d" %(result[0], result[1], result[0]*result[1]))
