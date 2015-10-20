def factorial(number):
  product = 1
  for i in range(1, number+1):
    product *= i
  return product

targets = [ 10, 100 ]
for target in targets:
  # take the factorial of target number, the factorial being a huge integer
  fact = factorial(target)
  # convert the huge integer into a string, break that string into an array of
  # characters, turn that array into an array of digits, then take the sum of
  # all the digits in the array of digits
  total = sum(map(int, list(str(fact))))
  print("factorial(%d): %d, sum: %d" %(target, fact, total))
