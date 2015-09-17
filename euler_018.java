// Refer to http://www.mathblog.dk/project-euler-18/
// for an explanation of the solution to the problem
//
import java.util.*;
import java.lang.Math;

public class euler_018
{
  static List<List<Integer>> input()
  {
    Scanner scanner = new Scanner(System.in);
    // 2-dimensional array of integers
    List<List<Integer>> triangle = new ArrayList<>();
    int i = 1;
    while (scanner.hasNextInt())
    {
      List<Integer> row = new ArrayList<>();
      // read 1 int at row 1, 2 int's at row 2, etc
      for (int j = 0; j < i; j++)
        row.add(scanner.nextInt());
      triangle.add(row);
      i++;
    }
    scanner.close();

    return triangle;
  }

  static void print(List<List<Integer>> triangle)
  {
    System.out.println("INPUT");
    for (List<Integer> row : triangle)
    {
      for (int number : row)
        System.out.print(" " + number);
      System.out.println();
    }
  }

  static void process(List<List<Integer>> triangle)
  {
    System.out.println("OUTPUT");
    for (int i = triangle.size()-2; i >= 0; i--)
    {
      List<Integer> current = triangle.get(i);
      List<Integer> next = triangle.get(i+1);
      // start from next-to-bottom row, work back to top
      for (int j = 0; j < current.size(); j++)
      {
        // for each entry, take 2 sums: triangle[i][j] + triangle[i+1][j] and
        // triangle[i][j] + triangle[i+1][j+1]
        // then replace entry with the max of the 2 sums
        int max = Math.max(current.get(j)+next.get(j), current.get(j)+next.get(j+1));
        current.set(j, max);
        System.out.print(" " + current.get(j));
      }
      System.out.println();
    }
  }

  public static void main(String[] args)
  {
    List<List<Integer>> triangle = input();
    print(triangle);
    process(triangle);
  }
}
