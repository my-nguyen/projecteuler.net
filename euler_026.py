# for an explanation on how to find the recurring cycles, refer to
# http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/

# this is a convenience class to bundle several pieces of information to return
# to the caller
class Decimal:
  def __init__(self, info, repeating, commencement=0, longueur=0):
    self.data = info
    self.recurring = repeating
    self.start = commencement
    self.length = longueur

def decimal(number):
  remainders = []
  builder = ""
  divider = 10
  while (divider != 0):
    remainder = divider % number
    # a cycle recurs when a remainder repeats
    if (remainder in remainders):
      start = remainders.index(remainder)
      # record the length of the recurring cycle
      length = len(builder) - start
      return Decimal(builder, True, start, length)
    # no cycle found: keep recording divisor
    else:
      remainders.append(remainder)
      builder += chr(divider/number + ord('0'))
    divider = (divider%number) * 10
  return Decimal(builder, False)

max = 0
number = 999
recurrence = ""
for i in range(999, 1, -1):
  decim = decimal(i)
  if (not decim.recurring):
    print("1/%d: non-recurring" %i)
  else:
    length = len(decim.data) - decim.start
    print("1/%d: recurring, length: %d" %(i, length))

    # look for and record the max cycle length and other useful info
    if (length > max):
      max = length
      number = i
      recurrence = decim.data[decim.start]
print("number: %d, length: %d" %(number, max))
