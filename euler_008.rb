# this method returns the product of all integers contained in list
def product(data)
  data.inject(:*)
end

# this method returns the adjacent digits of 'length' whose product is the
# largest product among all the adjacent digits within the 'digits' list
def max_product(digits, length)
  max = 0
  result = []
  start = 0
  while (start+length <= digits.size)
    # take a slice of length (4, 7, 10 or 13) digits
    slice = digits[start, length]
    index = slice.index(0)
    # if the slice contains 0, then skip to the next slice beyond the 0,
    # because a product of anything and 0 is 0.
    if (index != nil)
      start += index + 1
    else
      # calculate the product of all digits in the slice
      produit = product(slice)
      # reset max if necessary
      if (produit > max)
        max = produit
        result = slice
      end
      # move on to the next slice
      start += 1
    end
  end
  result
end

# this method converts a character string containing digits into a list of
# integer digits
def to_ints(data)
  data.chars.map(&:to_i)
end

# copy the number from above
number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"
# convert the long string number into a list of 1000 integer digits
digits = to_ints(number)
lengths = [4, 7, 10, 13]
lengths.each do |length|
  slice = max_product(digits, length)
  puts("max of #{length}: #{product(slice)} from #{slice.to_s}")
end
