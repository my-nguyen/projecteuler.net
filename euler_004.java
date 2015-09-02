class euler_004
{
  // find the reverse of a number. this method is flawed: if the original number
  // has trailing zeroes, then those zeroes won't appear in the reversed number.
  private static int reverse(int number)
  {
    int other = 0;
    while (number != 0)
    {
      other = other*10 + number%10;
      number /= 10;
    }
    return other;
  }

  // new and improved algorithm to find a palindrome: compare the number with its
  // own reverse
  private static boolean is_palindrome(int number)
  {
    return number == reverse(number);
  }

  // find the largest palindrome found in all products of 1-digit, 2-digit and
  // 3-digit numbers
  private static void largest_palindrome_product(int target, int[] result)
  {
    int max = 1;
    // use 2 indices: upper starts from target down to 1, and lower starts from upper
    // down to 1
    for (int upper = target; upper >= 1; upper--)
    {
      for (int lower = upper; lower >= 1; lower--)
      {
        int product = upper * lower;
        if (is_palindrome(product) && product > max)
        {
          max = product;
          result[0] = lower;
          result[1] = upper;
        }
      }
    }
  }

  public static void main(String[] args)
  {
    int targets[] = {9, 99, 999, 9999};
    int result[] = new int[2];
    for (int target : targets)
    {
      largest_palindrome_product(target, result);
      System.out.println("largest palindrome product: [" + result[0] + ", " + result[1]
           + ", " + result[0]*result[1] + "]");
    }
  }
}
