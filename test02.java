import java.util.*;

class test02
{
  static List<Integer> factors(int number)
  {
    List<Integer> divisors = new ArrayList<>();
    // 1 is always a divisor
    divisors.add(1);

    if (number > 1)
    {
      // target number is also always a divisor
      divisors.add(number);
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

  public static void main(String[] args)
  {
    // String tmp = Stringutils.repeat("1", 5);
    System.out.println("repeat: " + tmp);
  }
}
