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
    // System.out.println("target: " + target + ", used: " + toString(used) + ", result: " + (i-1));
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

  // this method returns all permutations of a string
  // turn this from recursion into iteration?
  static List<String> permutations(String source)
  {
    List<String> result = new ArrayList<>();
    // special case when there's only one character in source
    if (source.length() == 1)
      result.add(source);
    else
    {
      for (int i = 0; i < source.length(); i++)
      {
        // take a substring of source, with letter at position i removed
        char letter = source.charAt(i);
        String copy = source.substring(0, i) + source.substring(i + 1);
        // compute all permutations of the substring
        for (String permute : permutations(copy.toString()))
        {
          // for each permutation found in the substring, form a new permutation
          // by combining the letter and the substring permutation.
          // System.out.println("i: " + i + ", letter: " + letter + ", copy: " + copy + ", permute: " + permute);
          result.add(letter + permute);
        }
      }
    }
    return result;
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

      while (limit % factorial(index) != 0)
      {
        // how many factorials(index) does it take to reach just below limit?
        int divisor = limit / factorial(index);
        // calculate the proper placement/index of this divisor within the bool array
        int digit = index(used, divisor);
        // mark the bool array accordingly
        used[digit] = true;
        // collect this index in the permutation
        permutation.append((char)(digit + '0'));
        System.out.println("limit: " + limit + ", index: " + index + ", factorial: " + factorial(index) + ", divisor: " + divisor + ", digit: " + digit + ", permutation: " + permutation);
        // calculations for the next iteration
        limit %= factorial(index);
        index -= 1;
      }

      // limit evenly divides a factorial: we're very close to the finish line.
      // calculate the remaining permutations
      // diff happens to be the index to the next set of permutations
      int diff = limit - factorial(index);
      if (diff != 0)
      {
        // collect all unused digits
        String unused = unused(used);
        // calculate all permutations of those unused digits
        List<String> perms = permutations(unused);
        System.out.println("diff: " + diff + ", unused: " + unused + ", perms: " + perms);
        // take the right permutation based on the difference calculated above
        permutation.append(perms.get(diff-1));
      }

      System.out.println("permutation: " + permutation);
    }
  }
}
