import java.util.*;

public class euler_023
{
  // this method returns a list of all proper divisors of n (numbers less than n
  // which divide evenly into n)
  static List<Integer> proper_divisors(int number)
  {
    List<Integer> list = new ArrayList<>();
    // 1 is always a divisor
    list.add(1);

    if (number > 1)
    {
      // start looking for other divisors from 2 on up.
      int i = 2;
      while (i <= (int)Math.sqrt(number))
      {
        // if number is evenly divisible by i, then retain i
        if (number % i == 0)
        {
          list.add(i);
          // possibly also retain the division of number/i.
          if (i != number/i)
            list.add(number/i);
        }
        i += 1;
      }
      Collections.sort(list);
    }

    return list;
  }

  // this method returns the sum of all numbers in a list
  static int sum(List<Integer> list)
  {
    int sum = 0;
    for (int number : list)
      sum += number;
    return sum;
  }

  public static void main(String[] args)
  {
    final int LIMIT = 28123;

    // calculate all abundant numbers from 1 to the LIMIT
    List<Integer> abundants = new ArrayList<>();
    for (int i = 1; i < LIMIT; i++)
      // an abundant number is one where the sum of all the proper divisors of
      // the number is greater than the number
      if (sum(proper_divisors(i)) > i)
        abundants.add(i);

    // take all the sums of any 2 abundant numbers within LIMIT
    boolean[] abundant_sums = new boolean[LIMIT];
    for (int i = 0; i < abundants.size(); i++)
      for (int j = i; j < abundants.size(); j++)
      {
        // sum of any 2 abundant numbers, both of which must be within LIMIT
        int sum = abundants.get(i) + abundants.get(j);
        // the sum must also be within LIMIT
        if (sum < LIMIT)
          // flag this number as the sum of some 2 abundant numbers
          abundant_sums[sum] = true;
      }

    // take the sum of all numbers that are not the sums of 2 abundant numbers
    int result = 0;
    for (int i = 0; i < abundant_sums.length; i++)
      // any unflagged number within LIMIT
      if (!abundant_sums[i])
        // take the sum of all those unflagged numbers
        result += i;

    System.out.println("result: " + result);
  }
}
