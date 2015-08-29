// Compile with javac (download jdk before this!)
class euler_001
{
  public static void main(String[] args)
  {
    int[] limits = {10, 20, 100, 500, 1000};
    for (int i = 0; i < 5; i++)
    {
      int_array multiples = new int_array();
      int highest_3 = (limits[i]-1) / 3;
      for (int j = 1; j <= highest_3; j++)
        multiples.push(j * 3);

      int highest_5 = (limits[i]-1) / 5;
      for (int j = 1; j <= highest_5; j++)
        if (j % 3 != 0)
          multiples.push(j * 5);

      multiples.sort();
      System.out.println("limit: " + limits[i] + ", sum: " + multiples.sum());
      // multiples.print();
    }
  }
}
