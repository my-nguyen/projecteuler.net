def longest_sequence():
  max_index = 0
  max_sequence = 0

  # only start retaining Collatz terms at 2
  for index in range(2, MAX_NUMBER+1):
    sequence = 1
    term = index
    while (term != 1):
      sequence += 1
      # get the next number in the Collatz term. term needs to be of
      # type long; if it were of type int, then (3*term + 1) would
      # overflow the max integer
      term = term/2 if (term % 2 == 0) else (3*term + 1)

    if (sequence > max_sequence):
      max_index = index
      max_sequence = sequence
      print("number: %d, sequence: %d" %(index, sequence))

def caching():
  max_index = 0
  max_sequence = 0

  # cache storage of sequence length of all numbers up to the current one,
  # and will eventually store all 1000000 sequence lengths.
  cache = [0] * (MAX_NUMBER+1)
  cache[1] = 1

  for index in range(2, MAX_NUMBER+1):
    sequence = 0
    term = index
    # if term < index, then it's already in cache
    while (term != 1 and term >= index):
      sequence += 1
      term = term/2 if (term % 2 == 0) else (3*term + 1)

    # cache[1] is 1
    # cache[2] is 2 (2, {cache[1]})
    # cache[3] is 8 (3, 10, 5, 16, 8, 4, {cache[2]})
    # cache[4] is 3 (4, {cache[2]})
    # cache[5] is 6 (5, 16, 8, {cache[4]})
    cache[index] = sequence + cache[term]
    # print("index: %d, cache[%d]: %d, sequence: %d, term: %d, cache[%d]: %d" %(index, index, cache[index, sequence, term, term, cache[term]]))
    if (cache[index] > max_sequence):
      max_index = index
      max_sequence = cache[index]
      print("caching: %d, sequence: %d" %(index, cache[index]))

MAX_NUMBER = 1000000
longest_sequence()
caching()
