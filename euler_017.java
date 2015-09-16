public class euler_017
{
  static String word(int number)
  {
    String[] units =
    {
      "one", "two", "three", "four", "five",
      "six", "seven", "eight", "nine",
    };
    String[] teens =
    {
      "ten", "eleven", "twelve", "thirteen", "fourteen",
      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    String[] tens =
    {
      "ten", "twenty", "thirty", "forty", "fifty",
      "sixty", "seventy", "eighty", "ninety"
    };

    StringBuilder word = new StringBuilder();
    // special case when number is 1000
    if (number == 1000)
      word.append("onethousand");
    else
    {
      // dealing with the hundreds
      int cent = number / 100;
      if (cent >= 1)
      {
        word.append(units[cent-1]).append("").append("hundred");
        if (number % 100 != 0)
          word.append("and");
      }

      // dealing with the tens
      if (number % 100 != 0)
      {
        int dix = number % 100;
        // when number is >= 20, things are simple
        if (dix >= 20)
        {
          int unite = dix / 10;
          word.append(tens[dix/10 - 1]);
          if (dix % 10 != 0)
          {
            word.append("");
            word.append(units[dix%10-1]);
          }
        }
        // things are a little complicated when number is in the teens
        else if (dix >= 10)
          word.append(teens[dix-10]);
        // or in the units
        else
          word.append(units[dix-1]);
      }
    }

    return word.toString();
  }

  public static void main(String[] args)
  {
    int sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
      String word = word(i);
      sum += word.length();
      System.out.println(word + ", " + sum);
    }
    // System.out.println("letters: " + sum);
  }
}
