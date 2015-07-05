# Largest prime factor
# The prime factors of 13195 are 5, 7, 13 and 29
# What is the largest prime factor of the number 600851475143?
#
def prime?(number)
  case number
  # 1 is not a prime number
  when 1
    return false
  # 2 is a prime number
  when 2
    return true
  else
    # an even number larger than 2 is not a prime number
    if number % 2 == 0
      return false
    else
      # only seach up to half the test number
      2.upto(number/2) do |n|
        if (number % n == 0)
           return false
        end
      end
      return true
    end
  end
end

def factors(number)
  # larray contains all factors to the left, and rarray all factors to the right
  larray = Array.new
  rarray = Array.new
  # default factors are 1 and the test number itself
  lfactor = 1
  rfactor = number

  while (lfactor < rfactor)
    # found a factor
    if number % lfactor == 0
      rfactor = number / lfactor
      # save the 2 factors
      larray << lfactor
      rarray.insert(0, rfactor)
    end
    lfactor += 1
  end

  # result is the combination of all factors on the left and right
  return larray + rarray
end

def largest_prime(factors)
  factors.reverse_each do |n|
    if prime?(n)
      return n
    end
  end
end

print("Enter a number: ")
number = gets.to_i
puts("#{number} is #{ prime?(number) ? '' : 'not ' }prime")
puts("FACTORS of #{number}: #{factors(number)}")
puts("Largest prime factor of #{number}: #{largest_prime(factors(number))}")
