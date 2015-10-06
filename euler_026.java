// for an explanation on how to find the recurring cycles, refer to
// http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/
import java.util.*;

// this is a convenience class to bundle several pieces of information to return
// to the caller
class Decimal
{
  String data;
  boolean recurring;
  int start;
  int length;

  Decimal(String string, boolean repeating)
  {
    data = string;
    recurring = repeating;
  }

  Decimal(String string, boolean repeating, int commencement, int longueur)
  {
    this(string, repeating);
    start = commencement;
    length = longueur;
  }
}

public class euler_026
{
  static Decimal decimal(int number)
  {
    List<Integer> remainders = new ArrayList<>();
    StringBuilder builder = new StringBuilder();
    int divider = 10;
    while (divider != 0)
    {
      int remainder = divider % number;
      int start = remainders.indexOf(remainder);
      // a cycle recurs when a remainder repeats
      if (start != -1)
      {
        // record the length of the recurring cycle
        int length = builder.length() - start;
        return new Decimal(builder.toString(), true, start, length);
      }
      // no cycle found: keep recording divisor
      else
      {
        remainders.add(remainder);
        builder.append((char)(divider/number + '0'));
      }
      divider = (divider%number) * 10;
    }
    return new Decimal(builder.toString(), false);
  }

  public static void main(String[] args)
  {
    int max = 0;
    int number = 999;
    String recurrence = "";
    for (int i = 999; i >= 2; i--)
    {
      Decimal decimal = decimal(i);
      System.out.print("1/" + i + ": ");
      if (!decimal.recurring)
        System.out.println("non-recurring");
      else
      {
        int length = decimal.data.length() - decimal.start;
        System.out.println("recurring, length: " + length);

        // look for and record the max cycle length and other useful info
        if (length > max)
        {
          max = length;
          number = i;
          recurrence = decimal.data.substring(decimal.start);
        }
      }
    }
    System.out.println("number: " + number + ", length: " + max);
  }
}
