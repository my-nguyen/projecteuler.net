// For explanations of the solution to this problem, refer to
// http://www.davidespataro.it/project-euler-problem-24/
// http://mahendrakariya.blogspot.com/2009/08/project-euler-problem-24-different.html
// http://www.mathblog.dk/project-euler-24-millionth-lexicographic-permutation/
// http://blog.singhanuvrat.com/problems/project-euler-the-millionth-lexicographic-permutation-of-the-digits
// http://math.stackexchange.com/questions/60742/finding-the-n-th-lexicographic-permutation-of-a-string
// http://www.eggwall.com/2012/01/project-euler-in-r-problem-24.html
// https://www.quora.com/What-is-the-most-efficient-solution-for-Project-Euler-problem-24-in-C-or-C++
import java.util.*;

public class euler_024
{
  static int factorial(int number)
  {
    int product = 1;
    for (int i = 2; i <= number; i++)
      product *= i;
    return product;
  }

  // this method returns the largest number whose factorial is under a limit
  static int largest(int limit)
  {
    int i = 1;
    while (factorial(i) <= limit)
      i += 1;
    return i - 1;
  }

  // this method returns the proper index to an array of boolean's based on a
  // target and the ON and OFF elements in the array
  static int index(boolean[] used, int target)
  {
    int count = 0;
    int i = 0;
    while (i < used.length && count <= target)
    {
      if (used[i] == false)
        count += 1;
      i += 1;
    }
    return i-1;
  }

  // this method collects the index of all OFF elements in a boolean array and
  // returns that collection as a String
  static String unused(boolean[] used)
  {
    StringBuilder result = new StringBuilder();
    for (int i = 0; i < used.length; i++)
      if (used[i] == false)
        result.append((char)(i + '0'));
    return result.toString();
  }

  public static void main(String[] args)
  {
    int[] limits = { 100, 1000, 10000, 100000, 1000000, 119, 120, 121 };
    for (int limit : limits)
    {
      StringBuilder permutation = new StringBuilder();
      int index = largest(limit);
      System.out.println("limit: " + limit + ", over: " + (index+1) + ", factorial: " + factorial(index+1));
      // array of booleans all initialized to false
      boolean[] used = new boolean[index+1];

      while (index >= 1)
      {
        // how many factorial(index) does it take to reach just below limit?
        int divisor = limit / factorial(index);
        // adjust divisor when limit evenly divides factorial(index)
        if (limit % factorial(index) == 0)
          divisor -= 1;
        // calculate the proper placement/index of this divisor within the bool array
        int digit = index(used, divisor);
        // mark the bool array accordingly
        used[digit] = true;
        // collect this index in the permutation
        permutation.append((char)(digit + '0'));
        System.out.println("limit: " + limit + ", index: " + index + ", factorial: " + factorial(index) + ", divisor: " + divisor + ", digit: " + digit + ", permutation: " + permutation);
        // calculations for the next iteration
        if (limit % factorial(index) == 0)
          limit = factorial(index);
        else
          limit %= factorial(index);
        index -= 1;
      }
      permutation.append(unused(used));

      System.out.println("permutation: " + permutation);
    }
  }
}
