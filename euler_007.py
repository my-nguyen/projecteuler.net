from sieve import Sieve

def worst_prime(number):
  if (number == 2):
    return True
  # only consider odd divisors from 3 up to half the test number
  for i in range(3, (number/2+1), 2):
    if (number % i == 0):
      return False
  return True

def worst_index(position):
  # only consider numbers greater than 3
  result = 3
  # first two prime numbers (2 and 3) are already accounted for
  incr = 2
  while (incr < position):
    # only consider odd numbers
    result += 2
    if (worst_prime(result)):
      incr += 1
  return result

def sieve2_prime(number):
  if (number == 2):
    return True
  if (number % 2 == 0):
    return False

  i = 3
  while (i*i <= number):
    if (number % i == 0):
      return False
    i += 2
  return True

def sieve2_index(position):
  result = 1
  j = 1
  while (j < position):
    result += 2
    if (sieve2_prime(result)):
      j += 1
  return result

def sieve3_index(position):
  primes = []
  primes.append(2)
  result = 1
  while (len(primes) < position):
    # only consider odd numbers
    result += 2
    found = True
    # result = 3, primes = [2], j = 0, primes[0]*primes[0] > 3 ==> prime
    # result = 5, primes = [2, 3], j = 0, result%primes[0] == 1
    #                              j = 1, primes[1]*primes[1] > 5 ==> prime
    # result = 7, primes = [2, 3, 5], j = 0, result%primes[0] == 1
    #                                 j = 1, primes[1]*primes[1] > 7 ==> prime
    # result = 9, primes = [2, 3, 5, 7], j = 0, result%primes[0] == 1
    #                                    j = 1, result%primes[1] == 0 ==> not prime
    j = 0
    while (found and j < len(primes) and primes[j]*primes[j] <= result):
      if (result % primes[j] == 0):
        found = False
      j += 1

    if (found):
      primes.append(result)
  return result

targets = [ 6, 11, 101, 1001, 10001, 50001 ]
sizes = [ 20, 40, 600, 8000, 105000, 612000 ]
# for target in targets:
  # print("Worst(%d): %d" %(target, worst_index(target)))
for i, target in enumerate(targets):
  sieve = Sieve(sizes[i])
  print("Sieve(%d): %d" %(target, sieve.index(target)))
for target in targets:
  print("Modified Sieve(%d): %d" %(target, sieve2_index(target)))
for target in targets:
  print("Improved Sieve(%d): %d" %(target, sieve3_index(target)))
