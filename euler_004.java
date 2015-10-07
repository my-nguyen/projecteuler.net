class euler_004
{
  // this method returns the reverse of a number.
  static int reverse(int number)
  {
    return Integer.parseInt(new StringBuilder(Integer.toString(number)).reverse().toString());
  }

  // this method returns whether a number is a palindrome
  static boolean is_palindrome(int number)
  {
    return number == reverse(number);
  }

  // this method counts the number of digits in a number
  static int count_digits(int number)
  {
    return Integer.toString(number).length();
  }

  // this method returns number 1, repeated as many times as specified in param
  static int repeat(int times)
  {
    // return new String(new char[times]).replace("\0", "1");
    // return Stringutils.repeat("1", times);
    StringBuilder builder = new StringBuilder();
    for (int i = 0; i < times; i++)
      builder.append("1");
    return Integer.parseInt(builder.toString());
  }

  // this method finds the largest palindrome found in all products of 1-digit,
  // 2-digit and 3-digit numbers
  static int[] mine_palindrome(int target)
  {
    int[] result = new int[2];
    int max = 1;
    // use 2 indices: upper starts from target down to 1, and lower starts from
    // upper down to 1
    int lower_bound = repeat(count_digits(target));
    for (int upper = target; upper >= lower_bound; upper--)
    {
      for (int lower = upper; lower >= lower_bound; lower--)
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
    return result;
  }

  // this method generates a palindrome by combining a number with its own
  // reverse
  static int make_palindrome(int first_half)
  {
    String forward = Integer.toString(first_half);
    String backward = new StringBuilder(forward).reverse().toString();
    return Integer.parseInt(forward + backward);
  }

  // this method is based on http://www.optimized.dk/project-euler-problem-4/
  static int[] optimized(int target)
  {
    int[] result = new int[2];
    boolean found = false;
    int index = target-1;
    while (!found)
    {
      // first create a fictional palindrome from index, e.g. 998899 from 998
      int palindrome = make_palindrome(index);
      // then look for a number by which palindrome is evenly divisible
      for (int i = target; i >= repeat(count_digits(target)); i--)
      {
        // that number has to be between the square root of the palindrome(1)
        // and the target number(2)
        // (1) any factor less than the square root of the palindrome will have
        // a corresponding factor larger than the square root.
        // (2) problem requires the factor to be less than target
        if (i*i < palindrome || palindrome/i > target)
          break;
        if (palindrome % i == 0)
        {
          found = true;
          result[0] = palindrome / i;
          result[1] = i;
          break;
        }
      }
      index -= 1;
    }
    return result;
  }

  public static void main(String[] args)
  {
    int targets[] = {99, 999, 9999};
    for (int target : targets)
    {
      int result[] = mine_palindrome(target);
      System.out.println("Mine: " + result[0] + "x" + result[1] + " = " + result[0]*result[1]);
    }
    for (int target : targets)
    {
      int[] result = optimized(target);
      System.out.println("Optimized: " + result[0] + "x" + result[1] + " = " + result[0]*result[1]);
    }
  }
}
