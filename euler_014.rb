# The following iterative sequence is defined for the set of positive integers:
# n → n/2 (n is even)
# n → 3n + 1 (n is odd)
# Using the rule above and starting with 13, we generate the following sequence:
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
# It can be seen that this sequence (starting at 13 and finishing at 1)
# contains 10 terms. Although it has not been proved yet (Collatz Problem), it
# is thought that all starting numbers finish at 1.
# Which starting number, under one million, produces the longest chain?
# NOTE: Once the chain starts the terms are allowed to go above one million.
#
MAX_NUMBER = 1000000

# this method returns the next number in the Collatz sequence. must use long
# instead of int here, since the calculation could turn a positive integer
# into a negative one.
def get_next(current)
  (current % 2 == 0) ? current/2 : (3*current + 1)
end

# this method returns the length of the sequence started with number. there's
# no need to retain the integers that form the sequence, just return the length
def sequence(number)
  length = 0
  while (number != 1)
    length += 1
    number = get_next(number)
  end
  length
end

max_index = 0
max_sequence = 0

# only start retaining Collatz sequences at 2
2.upto(MAX_NUMBER) do |i|
  length = sequence(i)
  if (length > max_sequence)
    max_index = i
    max_sequence = length
    puts("number: #{i}, length: #{length}")
  end
end
