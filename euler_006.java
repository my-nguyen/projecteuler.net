class euler_006
{
  private static long sum_squares(int max)
  {
    long sum = 0;
    for (int i = 1; i <= max; i++)
      sum += (long)Math.pow(i, 2);
    return sum;
  }

  private static long square_sum(int max)
  {
    long sum = 0;
    for (int i = 1; i <= max; i++)
      sum += i;
    return (long)Math.pow(sum, 2);
  }

  public static void main(String[] args)
  {
    int targets[] = {10, 50, 100};
    for (int target : targets)
      System.out.println("Difference(" + target + "): " + (square_sum(target) - sum_squares(target)));
  }
}
