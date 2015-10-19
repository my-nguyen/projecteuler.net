import java.util.*;
import java.lang.*;

// this class is used to retain the pair of multiplicand and multiplier of a product
class Pair
{
  int first;
  int second;

  Pair(int left, int right)
  {
    first = left;
    second = right;
  }
}

// this class keeps tracks of which of the 9 digits (from 1 to 9) in a number
// have been used
class Flags
{
  final int ALL_DIGITS = 10;
  // cover all 10 digits from 0 to 9. array of booleans all initialized to false
  boolean[] data = new boolean[ALL_DIGITS];

  // this method marks the digits in number as ON
  Flags mask(String number)
  {
    for (char digit : number.toCharArray())
      data[digit-'0'] = true;
    return this;
  }

  // this method counts all the ON digits
  int count()
  {
    int count = 0;
    // skip digit 0
    for (int i = 1; i < ALL_DIGITS; i++)
      if (data[i])
        count += 1;
    return count;
  }

  // constructor based on an integer
  Flags()
  {
  }

  // copy constructor
  Flags(Flags rhs)
  {
    System.arraycopy(rhs.data, 0, data, 0, ALL_DIGITS);
  }
}

public class euler_032
{
  // this method returns a list of all divisors of a product number
  static List<Integer> factors(int number)
  {
    List<Integer> divisors = new ArrayList<>();
    // 1 is always a divisor
    divisors.add(1);

    if (number > 1)
    {
      // product number is also always a divisor
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

  // this method returns a list of pairs of <multiplicand, multiplier> from a
  // list of factors
  static List<Pair> pairs(List<Integer> factors)
  {
    List<Pair> pairs = new ArrayList<>();
    // only have to iterate thru half the list of factors, since beyond the
    // halfway line has already been accounted for in the pairs
    for (int i = 0; i < factors.size()/2; i++)
      pairs.add(new Pair(factors.get(i), factors.get(factors.size()-1)/factors.get(i)));
    return pairs;
  }

  public static void main(String[] args)
  {
    // some products can be obtained more than one way, so using a Set will
    // remove the duplicate products
    Set<Integer> pandigital = new HashSet<>();
    // there's a total of 9 digits (1 to 9). how many digits must a product have?
    // if it has 3 digits or less, then the pair of <multiplicand, multiplier>
    // must have at least 6 digits combined, which is impossible. if it has 5
    // digits or more, then <multiplicand, multiplier> must have at most 4
    // digits combined, which is also impossible. therefore, a product has to
    // have a 4 digits. the lower bound is just the smallest 4-digit number with
    // all 4 distinct digits: 1234. similarly, the upper bound is just the
    // highest 4-digit number with all 4 distinct digit: 9876
    for (int product = 1234; product <= 9876; product++)
    {
      Flags flags = new Flags();
      flags.mask(Integer.toString(product));
      // make sure product doesn't include 0
      if (flags.count() == 4)
      {
        // process each pair of <multiplicand, multiplier>
        for (Pair pair : pairs(factors(product)))
        {
          String first = Integer.toString(pair.first);
          String second = Integer.toString(pair.second);
          // make sure the pair of <multiplicand, multiplier> have 5 digits combined
          if (first.length() + second.length() == 5)
          {
            // make a copy of flags
            Flags copy = new Flags(flags);
            copy.mask(first).mask(second);
            // all 9 digits are filled: a pandigital is found
            if (copy.count() == 9)
            {
              pandigital.add(product);
              System.out.println(first + " x " + second + " = " + product);
            }
          }
        }
      }
    }

    int sum = 0;
    for (int product : pandigital)
      sum += product;
    System.out.println("Sum of all products: " + sum);
  }
}
