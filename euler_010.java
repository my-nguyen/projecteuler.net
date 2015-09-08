// Summation of primes
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// The Sieve of Eratosthenes algorithm developed in Euler #7 was used here to
// yield marvelous result:
//
class euler_010
{
  public static void main(String[] args)
  {
    int targets[] = {10, 100000, 500000, 1000000, 1500000, 2000000};
    for (int target : targets)
    {
      primes myprimes = new primes(target);

      System.out.println("Sum primes(" + target + "): " + myprimes.sum());
    }
  }
}
