# original algorithm to check whether a number is a palindrome: first convert
# the number to a string, then compare the digits from both ends.
def palindrome?(number)
  string = number.to_s
  i = 0
  # move index i forward while comparing the leftmost with the rightmost digit
  while (i < string.length/2 && string[i] == string[-1-i])
    i += 1
  end

  # if index goes beyond half the number without finding a mismatch, then
  # a palindrome is found. Otherwise, no palindrome.
  return i >= string.length/2
end

# find the reverse of a number. this method is flawed: if the original number
# has trailing zeroes, then those zeroes won't appear in the reversed number.
def reverse(number)
  other = 0
  while number != 0
    other = other*10 + number%10
    number /= 10
  end
  other
end

# new and improved algorithm to find a palindrome: compare the number with its
# own reverse
def palindrome2?(number)
  number == reverse(number)
end

# find the largest palindrome found in all products of 1-digit, 2-digit and
# 3-digit numbers
def largest_palindrome_product(target)
  max = 1
  result = []
  # use 2 indices: upper starts from target down to 1, and lower starts from upper
  # down to 1
  target.downto(1) do |upper|
    upper.downto(1) do |lower|
      product = upper * lower
      if (palindrome2?(product) && product > max)
        max = product
        result = [lower, upper, product]
      end
    end
  end
  result
end

targets = [9, 99, 999, 9999]
targets.each do |target|
  puts("Largest #{target.to_s.size}-digit: #{largest_palindrome_product(target)}")
end
