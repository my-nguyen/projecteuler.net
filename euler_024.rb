# For explanations of the solution to this problem, refer to
# http://www.davidespataro.it/project-euler-problem-24/
# http://mahendrakariya.blogspot.com/2009/08/project-euler-problem-24-different.html
# http://www.mathblog.dk/project-euler-24-millionth-lexicographic-permutation/
# http://blog.singhanuvrat.com/problems/project-euler-the-millionth-lexicographic-permutation-of-the-digits
# http://math.stackexchange.com/questions/60742/finding-the-n-th-lexicographic-permutation-of-a-string
# http://www.eggwall.com/2012/01/project-euler-in-r-problem-24.html
# https://www.quora.com/What-is-the-most-efficient-solution-for-Project-Euler-problem-24-in-C-or-C++
def factorial(number)
  product = 1
  1.upto(number) do |i|
    product *= i
  end
  product
end

# this method returns the largest number whose factorial is under a limit
def largest(limit)
  i = 1
  while (factorial(i) <= limit)
    i += 1
  end
  i - 1
end

# this method returns the proper index to an array of boolean's based on a
# target and the ON and OFF elements in the array
def rank(used, target)
  count = 0
  i = 0
  while (i < used.size && count <= target)
    if (used[i] == false)
      count += 1
    end
    i += 1
  end
  i-1
end

# this method collects the index of all OFF elements in a boolean array and
# returns that collection as a String
def unused(used)
  result = ""
  used.each_index do |i|
    if (used[i] == false)
      result += (i + '0'.ord).chr
    end
  end
  result
end

limits = [ 100, 1000, 10000, 100000, 1000000, 119, 120, 121 ]
limits.each do |limit|
  permutation = ""
  index = largest(limit)
  puts("limit: #{limit}, over: #{(index+1)}, factorial: #{factorial(index+1)}")
  # array of booleans all initialized to false
  used = Array.new(index+1, false)

  while (index >= 1)
    # how many factorial(index) does it take to reach just below limit?
    divisor = limit / factorial(index)
    # adjust divisor when limit evenly divides factorial(index)
    if (limit % factorial(index) == 0)
      divisor -= 1
    end
    # calculate the proper placement/index of this divisor within the bool array
    digit = rank(used, divisor)
    # mark the bool array accordingly
    used[digit] = true
    # collect this index in the permutation
    permutation << (digit + '0'.ord).chr
    puts("limit: #{limit}, index: #{index}, factorial: #{factorial(index)}, divisor: #{divisor}, digit: #{digit}, permutation: #{permutation}")
    # calculations for the next iteration
    if (limit % factorial(index) == 0)
      limit = factorial(index)
    else
      limit %= factorial(index)
    end
    index -= 1
  end
  permutation << unused(used)

  puts("permutation: #{permutation}")
end
