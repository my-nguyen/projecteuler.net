class euler_010
{
  public static void main(String[] args)
  {
    int targets[] = {10, 100000, 500000, 1000000, 1500000, 2000000};
    for (int target : targets)
    {
      Sieve primes = new Sieve(target);
      System.out.println("Sum primes(" + target + "): " + primes.sum());
    }
  }
}
