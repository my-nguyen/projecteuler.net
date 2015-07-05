# Multiples of 3 and 5
# If we list all the natural numbers below 10 that are multiples of 3 or 5,
# we get 3, 5, 6, and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#
print("Enter a limit: ")
# limit is 1 below the value entered (if entry is 20, then limit is 19)
limit = gets.to_i - 1

# if entry is 20, then limit is 19, and threes is 6 (19 divided by 3). Then the
# multiples of 3 are 1*3, 2*3, 3*3, 4*3, 5*3, 6*3, OR 3, 6, 9, 12, 15, and 18.
# sum them all as per the problem's requirement
total = 0
threes = limit / 3
1.upto(threes) do |number|
  total += number * 3
end

# similarly with multiples of 5, except that we need to discount those that are
# multiples of both 5 and 3, because those are already accounted for in the
# other loop above
fives = limit / 5
1.upto(fives) do |number|
  if (number % 3 != 0)
    total += number * 5
  end
end

puts "TOTAL: #{total}"
