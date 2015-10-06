// I choose the brute-force/straigthforward implementation because I don't quite
// understand the geometric/arithmetic solution which can be found here:
// http://www.mathblog.dk/project-euler-problem-1/
import java.util.*;

class euler_001
{
  static int sum(List<Integer> array)
  {
    int sum = 0;
    for (int number : array)
      sum += number;
    return sum;
  }

  public static void main(String[] args)
  {
    int[] limits = {10, 20, 100, 500, 1000};
    for (int limit : limits)
    {
      List<Integer> multiples = new ArrayList<>();

      // collect all multiples of 3
      int highest_3 = (limit-1) / 3;
      for (int j = 1; j <= highest_3; j++)
        multiples.add(j * 3);

      // collect all multiples of 5
      int highest_5 = (limit-1) / 5;
      for (int j = 1; j <= highest_5; j++)
        if (j % 3 != 0)
          multiples.add(j * 5);

      System.out.println("limit: " + limit + ", sum: " + sum(multiples));
    }
  }
}
