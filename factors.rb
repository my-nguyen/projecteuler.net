# find all factors of a target number
def find_factors(number)
  # 1 is always a divisor
  factors = [1]
  if number > 1
    # number is also always a divisor
    factors << number
    # start looking for other factors from 2 on up.
    i = 2
    while (i <= Math.sqrt(number).to_i)
      # if number is evenly divisible by i, then retain i, and possibly also
      # the division of number/i.
      if (number % i == 0)
        factors << i
        factors << number/i if (i != number/i)
      end
      i += 1
    end
    factors.sort!
  end
  factors
end

targets = [8051, 10403]
targets.each do |target|
  factors = find_factors(target)
  puts("FACTORS of #{target}: #{factors}")
end
