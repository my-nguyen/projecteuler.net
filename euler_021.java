import java.util.*;

public class euler_021
{
  // this method returns a list of all proper divisors of n (numbers less than n
  // which divide evenly into n)
  static List<Integer> divisors(int number)
  {
    List<Integer> divisors = new ArrayList<>();
    // 1 is always a divisor
    divisors.add(1);

    if (number > 1)
    {
      // start looking for other divisors from 2 on up.
      int i = 2;
      while (i <= (int)Math.sqrt(number))
      {
        // if number is evenly divisible by i, then retain i
        if (number % i == 0)
        {
          divisors.add(i);
          // possibly also retain the division of number/i.
          if (i != number/i)
            divisors.add(number/i);
        }
        i += 1;
      }
      Collections.sort(divisors);
    }
    return divisors;
  }

  // this method returns the sum of all numbers in a list
  static int sum(List<Integer> list)
  {
    int sum = 0;
    for (int number : list)
      sum += number;
    return sum;
  }

  final static int MAX_AMICABLE = 10000;
  public static void main(String[] args)
  {
    List<Integer> pairs = new ArrayList<>();
    for (int i = 1; i <= MAX_AMICABLE; i++)
    {
      // take the sum of all divisors of the current number (i)
      int sum = sum(divisors(i));
      // at this point in the previous version, in order to look for a matching
      // pair, there was an inner loop going from 1 to 10000. as a result, the
      // old program took 95,626 milliseconds; compare that with the 89 ms it
      // takes in the improved version.
      // improvement: only need to check for a pair if sum is greater than i.
      if (sum > i)
      {
        // take the sum of all divisors of the sum, and see if that equals the
        // current number (i)
        if (sum(divisors(sum)) == i)
        {
          System.out.println(i + " and " + sum);
          pairs.add(i);
          pairs.add(sum);
        }
      }
    }
    System.out.println("sum: " + sum(pairs));
  }
}
