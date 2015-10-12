// Refer to http://www.mathblog.dk/project-euler-18/
// for an explanation of the solution to the problem
import java.util.*;
import java.lang.Math;

public class euler_018
{
  // this method converts a string containing integers separated by spaces into
  // an array of integers
  static List<Integer> to_ints(String string)
  {
    List<Integer> array = new ArrayList<>();
    String[] tokens = string.split(" ");
    for (int i = 0; i < tokens.length; i++)
      array.add(Integer.parseInt(tokens[i]));
    return array;
  }

  static List<List<Integer>> input()
  {
    String[] lines =
    {
      "75",
      "95 64",
      "17 47 82",
      "18 35 87 10",
      "20 04 82 47 65",
      "19 01 23 75 03 34",
      "88 02 77 73 07 63 67",
      "99 65 04 28 06 16 70 92",
      "41 41 26 56 83 40 80 70 33",
      "41 48 72 33 47 32 37 16 94 29",
      "53 71 44 65 25 43 91 52 97 51 14",
      "70 11 33 28 77 73 17 78 39 68 17 57",
      "91 71 52 38 17 14 91 43 58 50 27 29 48",
      "63 66 04 68 89 53 67 30 73 16 69 87 40 31",
      "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"
    };

    List<List<Integer>> triangle = new ArrayList<>();
    for (String line : lines)
      triangle.add(to_ints(line));
    return triangle;
  }

  static public String toString(List<List<Integer>> triangle)
  {
    StringBuilder builder = new StringBuilder();
    for (List<Integer> row : triangle)
      builder.append(row.toString()).append("\n");
    return builder.toString();
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
        // for each entry, take 2 sums:
        // triangle[i][j] + triangle[i+1][j] AND triangle[i][j] + triangle[i+1][j+1]
        // then replace entry with the max of the 2 sums
        int max = Math.max(current.get(j)+next.get(j), current.get(j)+next.get(j+1));
        current.set(j, max);
      }
      System.out.println(current);
    }
  }

  public static void main(String[] args)
  {
    List<List<Integer>> triangle = input();
    System.out.print("INPUT\n" + toString(triangle));
    process(triangle);
  }
}
