# The Sieve of Eratosthenes algorithm developed in Euler #7 was used here to
# yield marvelous result:
# Target      Sum             Pre-Sieve     Post-Sieve
# 10          17              0             0
# 100000      454396537       12            .05
# 500000      9914236195      274           .24
# 1000000     37550402023     1007          .47
# 1500000     82074443256     2201          .72
# 2000000     142913828922    3850          .97
#
from sieve import Sieve

targets = [10, 100000, 500000, 1000000, 1500000, 2000000]
for target in targets:
  primes = Sieve(target)
  print("Sum primes(%d): %d" %(target, primes.sum()))
