import java.util.*;

public class euler_021
{
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
    // int[] pairs = new int[10];
    List<Integer> pairs = new ArrayList<>();
    for (int i = 1; i <= MAX_AMICABLE; i++)
    {
      if (pairs.contains(i) == false)
      {
        int sumi = sum(divisors(i));
        for (int j = 1; j <= MAX_AMICABLE; j++)
        {
          if (i != j)
          {
            int sumj = sum(divisors(j));
            if (sumi == j && sumj == i)
            {
              System.out.println(i + " and " + j);
              pairs.add(i);
              pairs.add(j);
            }
          }
        }
      }
    }
    System.out.println("sum: " + sum(pairs));
  }
}
