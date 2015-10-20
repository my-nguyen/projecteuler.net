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
for left in range(10, 354295):
  # total of the fifth powers of all digits
  total = 0
  for digit in map(int, list(str(left))):
    total += digit ** 5

  if (left == total):
    print "left=%d" %left,
    for digit in map(int, list(str(left))):
      print "%d^5=%d" %(digit, digit**5),
    print
    fifth_powers.append(total)
print "Sum of all fifth powers:", sum(fifth_powers)
