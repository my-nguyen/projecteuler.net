def factorial(number)
  product = 1
  1.upto(number) do |i|
    product *= i
  end
  product
end

targets = [ 10, 100 ]
targets.each do |target|
  # take the factorial of target number, the factorial being a huge integer
  factorial = factorial(target)
  # convert the huge integer into a string, break that string into an array of
  # characters, turn that array into an array of digits, then take the sum of
  # all the digits in the array of digits
  sum = factorial.to_s.chars.map(&:to_i).inject(:+)
  puts("factorial(#{target}): #{factorial}, sum: #{sum}")
end
