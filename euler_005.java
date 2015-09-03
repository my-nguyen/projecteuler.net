class euler_005
{
  // greatest common divisor of 2 integers
  private static long gcd(long one, long two)
  {
    while (one != 0)
    {
      long tmp = one;
      one = two % one;
      two = tmp;
    }
    return two;
  }

  // least common multiple of 2 integers
  // must declare type of parameter one and return as long; otherwise an overflow
  // would occur at one * two when one becomes too large.
  private static long lcm(long one, long two)
  {
    return (one * two) / gcd(one, two);
  }

  // least common multiple of an array of more than 2 integers
  private static long lcm_array(int array[], int size)
  {
    long multiple = lcm(array[0], array[1]);
    for (int i = 2; i < size; i++)
      multiple = lcm(multiple, array[i]);
    return multiple;
  }

  public static void main(String[] args)
  {
    int array[] = new int[20];
    for (int i = 0; i < array.length; i++)
      array[i] = i+1;

    // test with different sizes
    int sizes[] = {5, 10, 15, 20};
    for (int size : sizes)
      System.out.println("LCM(1.." + size + "): " + lcm_array(array, size));
  }
}
