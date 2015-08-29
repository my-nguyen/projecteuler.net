# Largest palindrome product
# A palindromic number reads the same both ways. The largest palindrome made
# from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.
#
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

def largest(digit_count)
  # max values for each digit; assuming we don't work beyond a 3-digit number
  max = [9, 99, 999]
  # an array that stores a number of palindromes found, so that its largest
  # palindrome will be returned later
  pals = []

  # start with left = max, decreasing and looping 9 times
  left = max[digit_count-1]
  9.times do
    # start with right = left
    right = left
    while (right >= 1)
      # if a palindrome is found for the product of left and right, then store
      # that palindrome in an array, so that its largest value will be returned
      if (palindrome?(left * right))
        pals << left*right
        break
      end
      right -= 1
    end
    left -= 1
  end

  # return the largest value in the palindrome array
  return pals.sort.last
end

1.upto(3) do |n|
  puts("Largest #{n}-digit: #{largest(n)}")
end
