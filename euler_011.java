import java.util.*;

class Constants
{
  final static int MAX_SLICE = 4;
  final static int MAX_ROW = 20;
  final static int MAX_COLUMN = 20;
}

class Slice
{
  List<Integer> data = new ArrayList<>();

  // this constructor creates an empty max Slice, with all integers set to zero.
  Slice()
  {
    for (int i = 0; i < Constants.MAX_SLICE; i++)
      data.add(0);
  }

  // this constructor copies data from a list of integers
  Slice(List<Integer> rhs)
  {
    data = rhs;
  }

  // this method returns the product of all integers in the Slice.
  int product()
  {
    int result = 1;
    for (int number : data)
      result *= number;
    return result;
  }

  // this methods reports both the product of and the contents of all integers
  // in the Slice
  String report()
  {
    StringBuilder out = new StringBuilder();
    out.append("MAX PRODUCT: ").append(product()).append(", slice ").append(data);
    return out.toString();
  }
}

// base class used by 6 other classes (Row, Column, DownFirst, DownLast, UpFirst
// and UpLast) with a common method find_max()
class Array
{
  List<Integer> data = new ArrayList<>();

  // this method finds, within the data array, the slice whose product has the
  // maximum value and if so, replace the current max with the new max.
  void find_max(Slice current)
  {
    System.out.println("data " + data);

    int start = 0;
    // while end of row is not reached
    while (start+Constants.MAX_SLICE <= data.size())
    {
      // take a slice of 4 adjacent numbers
      Slice slice = new Slice(data.subList(start, start+Constants.MAX_SLICE));
      // search the new slice for integer zero
      int index = slice.data.indexOf(0);
      // if the slice contains 0, then skip to the next slice beyond the 0,
      // because a product of anything and 0 is 0.
      if (index != -1)
        start += index + 1;
      else
      {
        // calculate the product of the 4 integers in the slice
        int product = slice.product();
        // update max if necessary
        if (product > current.product())
        {
          System.out.println("current: " + current.product() + ", new: " + product + ", slice " + slice.data);
          current.data = slice.data;
        }
        // move on to the next slice
        start += 1;
      }
    }
  }
}

// this class contains all 20 integers in a row
class Row extends Array
{
  // this constructor extracts one row at position i from the grid
  Row(List<List<Integer>> grid, int row)
  {
    for (int i = 0; i < Constants.MAX_COLUMN; i++)
      data.add(grid.get(row).get(i));
  }
}

// this class contains all 20 integers in a column
class Column extends Array
{
  // this constructor extracts one column at position j from the grid
  Column(List<List<Integer>> grid, int column)
  {
    for (int i = 0; i < Constants.MAX_ROW; i++)
      data.add(grid.get(i).get(column));
  }
}

// empty class that serves as base for the following 4 diagonal classes
class Diagonal extends Array
{
}

class DownFirst extends Diagonal
{
  // This constructor extracts all numbers from grid starting at position (i,j)
  // going down diagonally. This method is called in a loop starting at i=16 and
  // j=0, and ending at i=0 and j=0.
  DownFirst(List<List<Integer>> grid, int i, int j)
  {
    while (i < Constants.MAX_ROW)
    {
      data.add(grid.get(i).get(j));
      i += 1;
      j += 1;
    }
  }
}

class DownLast extends Diagonal
{
  // This constructor extracts all numbers from grid starting at position (i,j)
  // going down diagonally. This method is called in a loop starting at i=0 and
  // j=1, and ending at i=0 and j=16.
  DownLast(List<List<Integer>> grid, int i, int j)
  {
    while (j < Constants.MAX_COLUMN)
    {
      data.add(grid.get(i).get(j));
      i += 1;
      j += 1;
    }
  }
}

class UpFirst extends Diagonal
{
  // This constructor extracts all numbers from grid starting at position (i,j)
  // going up diagonally. This method is called in a loop starting at i=3 and
  // j=0, and ending at i=19 and j=0.
  UpFirst(List<List<Integer>> grid, int i, int j)
  {
    while (i >= 0)
    {
      data.add(grid.get(i).get(j));
      i -= 1;
      j += 1;
    }
  }
}

class UpLast extends Diagonal
{
  // This constructor extracts all numbers from grid starting at position (i,j)
  // going up diagonally. This method is called in a loop starting at i=19 and
  // j=1, and ending at i=19 and j=16.
  UpLast(List<List<Integer>> grid, int i, int j)
  {
    while (j < Constants.MAX_COLUMN)
    {
      data.add(grid.get(i).get(j));
      i -= 1;
      j += 1;
    }
  }
}

class euler_011
{
  // this method converts a string containing 20 integers separated by spaces
  // into an array of 20 integers
  static List<Integer> to_ints(String string)
  {
    List<Integer> array = new ArrayList<>();
    // replaced StringTokenizer with String::split() because StringTokenizer is
    // legacy class
    String[] tokens = string.split(" ");
    for (int i = 0; i < tokens.length; i++)
      array.add(Integer.parseInt(tokens[i]));
    return array;
  }

  static List<List<Integer>> init()
  {
    // set up input as an array of 20 strings, each containing 20 numbers
    String[] lines =
    {
      "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08",
      "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00",
      "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65",
      "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91",
      "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80",
      "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50",
      "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70",
      "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21",
      "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72",
      "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95",
      "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92",
      "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57",
      "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58",
      "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40",
      "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66",
      "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69",
      "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36",
      "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16",
      "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54",
      "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"
    };

    // convert the array of 20 strings into an array of 20 sub-arrays, each
    // sub-array containing 20 numbers
    List<List<Integer>> grid = new ArrayList<List<Integer>>();
    for (String line : lines)
      grid.add(to_ints(line));
    return grid;
  }

  public static void main(String[] args)
  {
    // set up grid as an array of 20 sub-arrays, each containing 20 integers
    List<List<Integer>> grid = init();
    // create an empty max Slice
    Slice max = new Slice();

    for (int i = 0; i < Constants.MAX_ROW; i++)
    {
      // extract one row
      Row row = new Row(grid, i);
      // find max product within the row
      row.find_max(max);
    }
    System.out.println(max.report());

    for (int j = 0; j < Constants.MAX_COLUMN; j++)
    {
      // extract one column
      Column column = new Column(grid, j);
      // find max product within the column
      column.find_max(max);
    }
    System.out.println(max.report());

    for (int i = Constants.MAX_ROW-Constants.MAX_SLICE; i >= 0; i--)
    {
      DownFirst down_first = new DownFirst(grid, i, 0);
      down_first.find_max(max);
    }
    System.out.println(max.report());

    for (int j = 1; j <= Constants.MAX_COLUMN-Constants.MAX_SLICE; j++)
    {
      DownLast down_last = new DownLast(grid, 0, j);
      down_last.find_max(max);
    }
    System.out.println(max.report());

    for (int i = Constants.MAX_SLICE-1; i <= Constants.MAX_ROW-1; i++)
    {
      UpFirst up_first = new UpFirst(grid, i, 0);
      up_first.find_max(max);
    }
    System.out.println(max.report());

    for (int j = 1; j <= Constants.MAX_COLUMN-Constants.MAX_SLICE; j++)
    {
      UpLast up_last = new UpLast(grid, Constants.MAX_ROW-1, j);
      up_last.find_max(max);
    }
    System.out.println(max.report());
  }
}
