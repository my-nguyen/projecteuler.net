// Compile with javac (download jdk before this!)
import java.util.*;

class euler_002
{
  public static void main(String[] args)
  {
    int[] limits = {10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000};
    // for (int i = 0; i < limits.length; i++)
    for (int limit : limits)
    {
      List<Integer> fibs = new ArrayList<Integer>();
      fibs.add(1);
      fibs.add(2);

      int fib;
      while ((fib = fibs.get(fibs.size()-2) + fibs.get(fibs.size()-1)) < limit)
        fibs.add(fib);

      int sum = 0;
      // for (int j = 0; j < fibs.size(); j++)
      for (int fibo : fibs)
        if (fibo % 2 == 0)
          sum += fibo;

      System.out.println("limit: " + limit + ", sum: " + sum);
      // fibs.print();
    }
  }
}
