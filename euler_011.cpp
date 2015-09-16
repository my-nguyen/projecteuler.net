#include <iostream>
#include <cstring> // strtok()
#include <cstdlib> // atoi()
using namespace std;

#define MAX_SLICE 4
#define MAX_ROW 20
#define MAX_COLUMN 20
#define NOT_FOUND -1

class base_array_t
{
public:
  base_array_t() {}
  base_array_t(int array[], int size);
  virtual ostream& output(ostream& out);
  friend ostream& operator<<(ostream& out, base_array_t& array);

protected:
  int data[MAX_ROW];
  int count;
};

base_array_t::base_array_t(int array[], int size)
{
  count = size;
  for (int i = 0; i < count; i++)
    data[i] = array[i];
}

// helper method to print out all numbers in an array
ostream& base_array_t::output(ostream& out)
{
  for (int i = 0; i < count; i++)
    out << " " << data[i];
  return out;
}

ostream& operator<<(ostream& out, base_array_t& array)
{
  return array.output(out);
}

struct slice_t : public base_array_t
{
  slice_t();
  slice_t(int array[]) : base_array_t(array, MAX_SLICE) {}
  int find(int target);
  int product();
  slice_t& operator=(const slice_t& rhs);
  ostream& output(ostream& out);
  friend class array_t;
};

slice_t::slice_t()
{
  count = MAX_SLICE;
  for (int i = 0; i < count; i++)
    data[i] = 0;
}

int slice_t::find(int target)
{
  for (int i = 0; i < count; i++)
    if (data[i] == target)
      return i;
  return NOT_FOUND;
}

int slice_t::product()
{
  int result = 1;
  for (int i = 0; i < count; i++)
    result *= data[i];
  return result;
}

slice_t& slice_t::operator=(const slice_t& rhs)
{
  for (int i = 0; i < count; i++)
    data[i] = rhs.data[i];
  return *this;
}

ostream& slice_t::output(ostream& out)
{
  out << "MAX PRODUCT: " << product() << ", slice:";
  base_array_t::output(out) << endl;
}

struct array_t : public base_array_t
{
  void find_max(slice_t* current);
  // these methods function like constructors, since they all initialize the
  // data and count fields of array_t. However, since I can't find a way to
  // distinguish the many such "constructors", methods are chosen instead.
  void row(int grid[][MAX_COLUMN], int index);
  void column(int grid[][MAX_COLUMN], int index);
  void diagonal_down_first(int grid[][MAX_COLUMN], int i, int j);
  void diagonal_down_last(int grid[][MAX_COLUMN], int i, int j);
  void diagonal_up_first(int grid[][MAX_COLUMN], int i, int j);
  void diagonal_up_last(int grid[][MAX_COLUMN], int i, int j);
};

// this method looks for a slice of 4 integers whose product is greater than max.
// if found, it returns a pointer to the slice. if not found, it returns NULL
void array_t::find_max(slice_t* current)
{
  // invoke base_array_t::operator<<()
  cout << "data:" << *this << endl;

  int start = 0;
  // while end of row is not reached
  while (start+MAX_SLICE-1 < count)
  {
    // take a slice of 4 adjacent numbers
    slice_t slice(data + start);
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
      if (product > current->product())
      {
        base_array_t base(slice.data, slice.count);
        // invoke base_array_t::operator<<()
        cout << "current: " << current->product() << ", new: " << product << ", slice:" << base << endl;
        *current = slice;
      }
      // move on to the next slice
      start += 1;
    }
  }
}

// this method extracts one row at position i from the grid
void array_t::row(int grid[][MAX_COLUMN], int index)
{
  for (count = 0; count < MAX_COLUMN; count++)
    data[count] = grid[index][count];
}

// this method extracts one column at position j from the grid
void array_t::column(int grid[][MAX_COLUMN], int index)
{
  for (count = 0; count < MAX_ROW; count++)
    data[count] = grid[count][index];
}

// This method extracts all numbers from grid starting at position (i,j) going
// down diagonally. This method is called in a loop starting at i=16 and j=0,
// and ending at i=0 and j=0.
void array_t::diagonal_down_first(int grid[][MAX_COLUMN], int i, int j)
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
void array_t::diagonal_down_last(int grid[][MAX_COLUMN], int i, int j)
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
void array_t::diagonal_up_first(int grid[][MAX_COLUMN], int i, int j)
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
void array_t::diagonal_up_last(int grid[][MAX_COLUMN], int i, int j)
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

// this method converts a string containing 20 integers separated by spaces into
// an array of 20 integers
void st_toarray(char* string, int array[])
{
  int j = 0;
  for (char* token = strtok(string, " "); token; token = strtok(NULL, " "))
  {
    array[j] = atoi(token);
    j++;
  }
}

void initialize(int grid[][MAX_COLUMN])
{
  // set up input as an array of 20 strings, each containing 20 numbers
  char input[][100] =
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

int main()
{
  int grid[MAX_ROW][MAX_COLUMN];
  initialize(grid);

  slice_t max;

  for (int i = 0; i < MAX_ROW; i++)
  {
    array_t array;
    array.row(grid, i);
    array.find_max(&max);
  }
  // invoke slice_t::operator<<()
  cout << max;

  for (int j = 0; j < MAX_COLUMN; j++)
  {
    array_t array;
    array.column(grid, j);
    array.find_max(&max);
  }
  cout << max;

  for (int i = MAX_ROW-MAX_SLICE; i >= 0; i--)
  {
    array_t array;
    array.diagonal_down_first(grid, i, 0);
    array.find_max(&max);
  }
  cout << max;

  for (int j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
  {
    array_t array;
    array.diagonal_down_last(grid, 0, j);
    array.find_max(&max);
  }
  cout << max;

  for (int i = MAX_SLICE-1; i <= MAX_ROW-1; i++)
  {
    array_t array;
    array.diagonal_up_first(grid, i, 0);
    array.find_max(&max);
  }
  cout << max;

  for (int j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
  {
    array_t array;
    array.diagonal_up_last(grid, MAX_ROW-1, j);
    array.find_max(&max);
  }
  cout << max;
}
