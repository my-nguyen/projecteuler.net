class euler_005
{
  // this method returns the greatest common divisor of 2 integers
  static long gcd(long one, long two)
  {
    while (one != 0)
    {
      long tmp = one;
      one = two % one;
      two = tmp;
    }
    return two;
  }

  // this method returns the least common multiple of 2 integers
  // must declare parameter type and return type as long; otherwise an overflow
  // would occur at one * two when one becomes too large.
  static long lcm(long one, long two)
  {
    return (one * two) / gcd(one, two);
  }

  // this method returns the least common multiple of an array of more than 2 integers
  static long my_algorithm(int size)
  {
    long multiple = 2;
    for (int i = 3; i <= size; i++)
      multiple = lcm(multiple, i);
    return multiple;
  }

  static long brute_force(int size)
  {
    int i = size;
    int j = 0;
    while (j <= size)
    {
      i += size;
      j = 2;
      while (j <= size)
        if (i % j != 0)
          break;
        else
          j += 1;
    }
    return i;
  }

  public static void main(String[] args)
  {
    int[] sizes = { 5, 10, 15, 20 };
    for (int size : sizes)
    {
      System.out.println("My algorithm(" + size + "): " + my_algorithm(size));
      System.out.println("Brute force(" + size + "): " + brute_force(size));
    }
  }
}
