def longest_sequence()
  max_index = 0
  max_sequence = 0

  # only start retaining Collatz terms at 2
  2.upto(MAX_NUMBER) do |index|
    sequence = 1
    term = index
    while (term != 1)
      sequence += 1
      # get the next number in the Collatz term. term needs to be of
      # type long; if it were of type int, then (3*term + 1) would
      # overflow the max integer
      term = (term % 2 == 0) ? term/2 : (3*term + 1)
    end

    if (sequence > max_sequence)
      max_index = index
      max_sequence = sequence
      puts("number: #{index}, sequence: #{sequence}")
    end
  end
end

def caching()
  max_index = 0
  max_sequence = 0

  # cache storage of sequence length of all numbers up to the current one,
  # and will eventually store all 1000000 sequence lengths.
  cache = []
  (MAX_NUMBER+1).times do |i|
    cache << 0
  end
  cache[1] = 1

  2.upto(MAX_NUMBER) do |index|
    sequence = 0
    term = index
    # if term < index, then it's already in cache
    while (term != 1 && term >= index)
      sequence += 1
      term = (term % 2 == 0) ? term/2 : (3*term + 1)
    end

    # cache[1] is 1
    # cache[2] is 2 (2, {cache[1]})
    # cache[3] is 8 (3, 10, 5, 16, 8, 4, {cache[2]})
    # cache[4] is 3 (4, {cache[2]})
    # cache[5] is 6 (5, 16, 8, {cache[4]})
    cache[index] = sequence + cache[term]
    # puts("index: #{index}, cache[#{index}]: #{cache[index]}, sequence: #{sequence}, term: #{term}, cache[#{term}]: #{cache[term]}")
    if (cache[index] > max_sequence)
      max_index = index
      max_sequence = cache[index]
      puts("caching: #{index}, sequence: #{cache[index]}")
    end
  end
end

MAX_NUMBER = 1000000
longest_sequence
caching
