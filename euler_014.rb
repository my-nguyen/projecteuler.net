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
