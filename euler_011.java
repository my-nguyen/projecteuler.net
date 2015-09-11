// In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
//
// 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
// 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
// 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
// 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
// 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
// 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
// 32 98 81 28 64 23 67 10 26*38 40 67 59 54 70 66 18 38 64 70
// 67 26 20 68 02 62 12 20 95 63*94 39 63 08 40 91 66 49 94 21
// 24 55 58 05 66 73 99 26 97 17 78*78 96 83 14 88 34 89 63 72
// 21 36 23 09 75 00 76 44 20 45 35 14*00 61 33 97 34 31 33 95
// 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
// 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
// 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
// 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
// 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
// 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
// 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
// 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
// 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
// 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
//
// The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
// What is the greatest product of four adjacent numbers in the same direction
// (up, down, left, right, or diagonally) in the 20×20 grid?
//
import java.util.*;

class base_array_t
{
  final static int MAX_SLICE = 4;
  final static int MAX_ROW = 20;
  final static int MAX_COLUMN = 20;
  final static int NOT_FOUND = -1;

  public base_array_t() {}

  public base_array_t(int array[], int offset, int size)
  {
    count = size;
    for (int i = 0; i < count; i++)
      data[i] = array[offset+i];
  }

  public String toString()
  {
    StringBuilder out = new StringBuilder();
    for (int i = 0; i < count; i++)
      out.append(" ").append(data[i]);
    return out.toString();
  }

  protected int[] data = new int[MAX_ROW];
  protected int count = 0;
};

class slice_t extends base_array_t
{
  public slice_t()
  {
    count = MAX_SLICE;
    for (int i = 0; i < count; i++)
      data[i] = 0;
  }

  public slice_t(int array[], int offset)
  {
    super(array, offset, MAX_SLICE);
  }

  public int find(int target)
  {
    for (int i = 0; i < count; i++)
      if (data[i] == target)
        return i;
    return NOT_FOUND;
  }

  public int product()
  {
    int result = 1;
    for (int i = 0; i < count; i++)
      result *= data[i];
    return result;
  }

  public void assign(slice_t other)
  {
    for (int i = 0; i < count; i++)
      data[i] = other.data[i];
  }

  public String toString()
  {
    StringBuilder out = new StringBuilder();
    out.append("MAX PRODUCT: ").append(product()).append(", slice:").append(super.toString());
    return out.toString();
  }
}

class array_t extends base_array_t
{
  void find_max(slice_t current)
  {
    // invoke base_array_t::toString()
    System.out.println("data:" + this);

    int start = 0;
    // while end of row is not reached
    while (start+MAX_SLICE-1 < count)
    {
      // take a slice of 4 adjacent numbers
      slice_t slice = new slice_t(data, start);
      int index = slice.find(0);
      // if the slice contains 0, then skip to the next slice beyond the 0,
      // because a product of anything and 0 is 0.
      if (index != NOT_FOUND)
        start += index + 1;
      else
      {
        // calculate the product of the 4 integers in the slice
        int product = slice.product();
        // update max if necessary
        if (product > current.product())
        {
          // invoke base_array_t::toString()
          System.out.println("current: " + current.product() + ", new: "
            + product + ", slice:" + new base_array_t(slice.data, 0, slice.count));
          current.assign(slice);
        }
        // move on to the next slice
        start += 1;
      }
    }
  }

  // the following methods function like constructors, since they all initialize
  // the fields data and count. However, since I can't find a way to
  // distinguish the many such "constructors", methods are chosen instead.
  //
  // this method extracts one row at position i from the grid
  void row(int[][] grid, int index)
  {
    for (count = 0; count < MAX_COLUMN; count++)
      data[count] = grid[index][count];
  }

  // this method extracts one column at position j from the grid
  void column(int[][] grid, int index)
  {
    for (count = 0; count < MAX_ROW; count++)
      data[count] = grid[count][index];
  }

  // This method extracts all numbers from grid starting at position (i,j) going
  // down diagonally. This method is called in a loop starting at i=16 and j=0,
  // and ending at i=0 and j=0.
  void diagonal_down_first(int[][] grid, int i, int j)
  {
    count = 0;
    while (i < MAX_ROW)
    {
      data[count] = grid[i][j];
      i += 1;
      j += 1;
      count += 1;
    }
  }

  // This method extracts all numbers from grid starting at position (i,j) going
  // down diagonally. This method is called in a loop starting at i=0 and j=1,
  // and ending at i=0 and j=16.
  void diagonal_down_last(int[][] grid, int i, int j)
  {
    count = 0;
    while (j < MAX_COLUMN)
    {
      data[count] = grid[i][j];
      i += 1;
      j += 1;
      count += 1;
    }
  }

  // This method extracts all numbers from grid starting at position (i,j) going
  // up diagonally. This method is called in a loop starting at i=3 and j=0,
  // and ending at i=19 and j=0.
  void diagonal_up_first(int[][] grid, int i, int j)
  {
    count = 0;
    while (i >= 0)
    {
      data[count] = grid[i][j];
      i -= 1;
      j += 1;
      count += 1;
    }
  }

  // This method extracts all numbers from grid starting at position (i,j) going
  // up diagonally. This method is called in a loop starting at i=19 and j=1,
  // and ending at i=19 and j=16.
  void diagonal_up_last(int[][] grid, int i, int j)
  {
    count = 0;
    while (j < MAX_COLUMN)
    {
      data[count] = grid[i][j];
      i -= 1;
      j += 1;
      count += 1;
    }
  }
}

class euler_011
{
  final static int MAX_SLICE = 4;
  final static int MAX_ROW = 20;
  final static int MAX_COLUMN = 20;

  // this method converts a string containing 20 integers separated by spaces into
  // an array of 20 integers
  private static void st_toarray(String string, int[] array)
  {
    int j = 0;
    StringTokenizer token = new StringTokenizer(string, " ");
    while (token.hasMoreTokens())
    {
      array[j] = Integer.parseInt(token.nextToken());
      j++;
    }
  }

  private static void initialize(int[][] grid)
  {
    // set up input as an array of 20 strings, each containing 20 numbers
    // String[] input = String[MAX_ROW];
    String[] input =
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

    // convert the array of 20 strings into an array of 20 sub-arrays, each sub-array
    // containing 20 numbers
    for (int i = 0; i < MAX_ROW; i++)
      st_toarray(input[i], grid[i]);
  }

  public static void main(String[] args)
  {
    int[][] grid = new int[MAX_ROW][MAX_COLUMN];
    initialize(grid);

    slice_t max = new slice_t();

    for (int i = 0; i < MAX_ROW; i++)
    {
      array_t array = new array_t();
      array.row(grid, i);
      array.find_max(max);
    }
    // invoke slice_t::toString()
    System.out.println(max);

    for (int j = 0; j < MAX_COLUMN; j++)
    {
      array_t array = new array_t();
      array.column(grid, j);
      array.find_max(max);
    }
    System.out.println(max);

    for (int i = MAX_ROW-MAX_SLICE; i >= 0; i--)
    {
      array_t array = new array_t();
      array.diagonal_down_first(grid, i, 0);
      array.find_max(max);
    }
    System.out.println(max);

    for (int j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
    {
      array_t array = new array_t();
      array.diagonal_down_last(grid, 0, j);
      array.find_max(max);
    }
    System.out.println(max);

    for (int i = MAX_SLICE-1; i <= MAX_ROW-1; i++)
    {
      array_t array = new array_t();
      array.diagonal_up_first(grid, i, 0);
      array.find_max(max);
    }
    System.out.println(max);

    for (int j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
    {
      array_t array = new array_t();
      array.diagonal_up_last(grid, MAX_ROW-1, j);
      array.find_max(max);
    }
    System.out.println(max);
  }
}
