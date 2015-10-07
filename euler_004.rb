# this method returns the reverse of a number.
def reverse(number)
  number.to_s.reverse.to_i
end

# this method returns whether a number is a palindrome
def is_palindrome(number)
  number == reverse(number)
end

# this method counts the number of digits in a number
def count_digits(number)
  number.to_s.length
end

# this method returns number 1, repeated as many times as specified in param
def repeat(times)
  ("1" * times).to_i
end

# this method finds the largest palindrome found in all products of 1-digit,
# 2-digit and 3-digit numbers
def mine_palindrome(target)
  result = []
  max = 1
  # use 2 indices: upper starts from target down to 1, and lower starts from
  # upper down to 1
  lower_bound = repeat(count_digits(target))
  target.downto(lower_bound) do |upper|
    upper.downto(lower_bound) do |lower|
      product = upper * lower
      if (is_palindrome(product) && product > max)
        max = product
        result[0] = lower
        result[1] = upper
      end
    end
  end
  result
end

# this method generates a palindrome by combining a number with its own
# reverse
def make_palindrome(first_half)
  forward = first_half.to_s
  backward = forward.reverse
  (forward + backward).to_i
end

# this method is based on http://www.optimized.dk/project-euler-problem-4/
def optimized(target)
  result = []
  found = false
  index = target-1
  while (!found)
    # first create a fictional palindrome from index, e.g. 998899 from 998
    palindrome = make_palindrome(index)
    # then look for a number by which palindrome is evenly divisible
    target.downto(repeat(count_digits(target))) do |i|
      # that number has to be between the square root of the palindrome(1)
      # and the target number(2)
      # (1) any factor less than the square root of the palindrome will have
      # a corresponding factor larger than the square root.
      # (2) problem requires the factor to be less than target
      if (i*i < palindrome || palindrome/i > target)
        break
      end
      if (palindrome % i == 0)
        found = true
        result[0] = palindrome / i
        result[1] = i
        break
      end
    end
    index -= 1
  end
  result
end

targets = [99, 999, 9999]
targets.each do |target|
  result = mine_palindrome(target)
  puts("Mine: #{result[0]}x#{result[1]} = #{result[0]*result[1]}")
end
targets.each do |target|
  result = optimized(target)
  puts("Optimized: #{result[0]}x#{result[1]} = #{result[0]*result[1]}")
end
