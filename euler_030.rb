# this method returns the sum of all numbers in a list
def sum(list)
  list.inject(:+)
end

fifth_powers = []
# Lower bound: since no single-digit number is a sum (per problem description),
# the lower bound is 10
# Upper bound: Suppose we have a 9-digit number.  The highest 9-digit number is
# 999999999. 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5, or
# (9^5)*9 is 531441, which is only 6 digits, which doesn't match the 9-digit
# left-hand side (999999999). Next for a 8-digit number. Right-hand side is
# (9^5)*8 or 472392, which is 6 digits, and which doesn't match the 8-digit
# left-hand side. Next is 7-digit number: right-hand number is (9^5)*7 or
# 413343, which is still 6 digits: no match. Next is 6-digit: right-hand side
# is (9^5)*6 or 354294, which matches the number of digits on the left-hand
# side. So upper bound is 354294.
(10..354294).each do |left|
  # sum of the fifth powers of all digits
  sum = 0
  left.to_s.each_char do |digit|
    sum += digit.to_i ** 5
  end

  if (left == sum)
    print("left=#{left}")
    left.to_s.each_char do |digit|
      print(" #{digit}^5=#{digit.to_i**5}")
    end
    puts
    fifth_powers << sum
  end
end
puts("Sum of all fifth powers: #{sum(fifth_powers)}")
