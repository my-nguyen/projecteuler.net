# Problem: given a number, find its largest divisor that is also a prime
def largest_prime(target):
  prime = 2
  while (target > prime):
    # if target is divisible by the current prime number, then keep dividing
    # target by the current prime number. that way, if target is divisible by
    # 4, 8, 16, 32, the repeated divisions by 2 will take care of those
    # powers of 2. similarly, if target is divisible by 9, 27, 81, the
    # repeated divisions by 3 will take care of those powers of 3. and so on.
    if (target % prime == 0):
      target /= prime
    # otherwise move on to the next number
    else:
      prime += 1
  # the last standing prime is the result looked for.
  return prime

def alternative(target):
  number = target
  largest = 0
  count = 2
  while (count*count <= number):
    if (number % count == 0):
      number /= count
      largest = count
    else:
      count += 1

  if (number > largest):
    largest = number
  return largest

targets = [13915, 475143, 1475143, 51475143, 1851475143, 10851475143, 600851475143]
for target in targets:
  # print "target: ", target, ", largest prime:", largest_prime(target)
  print "target: %d, largest prime: %d" %(target, largest_prime(target))
for target in targets:
  print "target: %d, alternative: %d" %(target, alternative(target))
