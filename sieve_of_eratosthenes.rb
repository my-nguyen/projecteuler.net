# copied from wikibooks.org
def sieve_of_eratosthenes(max)
  arr=(2..max).to_a
  (2..Math::sqrt(max)).each do |i|
     arr.delete_if {|a|a % i == 0 && a!=i}
   end
   arr
end

# seems slower than the version I wrote in primes.rb, based on Wikipedia's
# description of Sieve of Eratosthenes. It also hangs when target number is
# 1000000
targets = [10, 100, 1000, 10000, 100000]
targets.each do |target|
  puts sieve_of_eratosthenes(target)
end
