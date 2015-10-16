require 'set'

set = Set.new
(2..100).each do |base|
  (2..100).each do |exponent|
    power = base**exponent
    set.add(power)
  end
end
puts("Distinct terms: #{set.size}")
