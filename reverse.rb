def reverse(number)
  other = 0
  while number != 0
    other = other*10 + number%10
    number /= 10
  end
  other
end

targets = [152, 101, 1967, 24890]
targets.each do |target|
  puts("reverse of #{target} is #{reverse(target)}")
end
