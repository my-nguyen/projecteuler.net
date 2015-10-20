def gcd(one, two):
  while (one != 0):
    tmp = one
    one = two % one
    two = tmp
  return two

def lcm(one, two):
  return (one*two) / gcd(one,two)

# this method returns the least common multiple of an array of more than 2 integers
def mine_lcm(size):
  multiple = 2
  for i in range(3, size+1):
    multiple = lcm(multiple, i)
  return multiple

def brute_lcm(size):
  i = size
  j = 0
  while (j <= size):
    i += size
    j = 2
    while (j <= size):
      if (i % j != 0):
        break
      else:
        j += 1

  return i

sizes = [ 5, 10, 15, 20 ]
for size in sizes:
  print("Mine(%d): %d" %(size, mine_lcm(size)))
  print("Brute force(%d): %d" %(size, brute_lcm(size)))
