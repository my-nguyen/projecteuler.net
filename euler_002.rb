def print_array numbers
  numbers.each_index do |i|
    print " #{numbers[i]}"
    puts if ((i+1) % 10 == 0 && i != (numbers.size-1))
  end
  puts
end

limits = [10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000]
limits.each do |limit|
  # first, find and store all fibonacci numbers up to and including the limit
  # into an array
  fibs = [1, 2]
  while ((fib = fibs[-2] + fibs[-1]) < limit)
    fibs << fib
  end

  # then take the sum of all those fibonacci numbers that are even
  sum = 0
  fibs.each do |fib|
    sum += fib if (fib % 2 == 0)
  end

  puts("limit: #{limit}, sum: #{sum}")
  # print_array fibs
end
