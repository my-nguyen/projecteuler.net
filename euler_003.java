class euler_003
{
  static long largest_prime(long target)
  {
    long prime = 2;
    while (target > prime)
      // if target is divisible by the current prime, then keep dividing
      // target by the current prime
      if (target % prime == 0)
        target /= prime;
      // otherwise move on to the next number
      else
        prime += 1;
    return prime;
  }

  public static void main(String[] args)
  {
    long targets[] = {13915, 475143, 1475143, 51475143, 1851475143, 10851475143L, 600851475143L};
    int i;
    for (i = 0; i < targets.length; i++)
      System.out.println("target: " + targets[i] + ", largest prime: " + largest_prime(targets[i]));
  }
}
