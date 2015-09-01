// Compile with javac (download jdk before this!)
class euler_002
{
  public static void main(String[] args)
  {
    int[] limits = {10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000};
    for (int i = 0; i < limits.length; i++)
    {
      int_array fibs = new int_array();
      fibs.push(1);
      fibs.push(2);

      int fib;
      while ((fib = fibs.at(fibs.size()-2) + fibs.at(fibs.size()-1)) < limits[i])
        fibs.push(fib);

      int sum = 0;
      for (int j = 0; j < fibs.size(); j++)
        if (fibs.at(j) % 2 == 0)
          sum += fibs.at(j);

      System.out.println("limit: " + limits[i] + ", sum: " + sum);
      // fibs.print();
    }
  }
}
