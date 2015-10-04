limit = 10**999
fib1 = 1
fib2 = 1
fib3 = fib1 + fib2
index = 3
while (fib3 < limit)
  fib1 = fib2
  fib2 = fib3
  fib3 = fib1 + fib2
  index += 1
end

puts("index: #{index}")
