#include <stdio.h>
#include <string.h>

#define MAX_SLICE 4
#define MAX_ROW 20
#define MAX_COLUMN 20

struct slice_t
{
  int _data[MAX_SLICE];
  int _product;
};
typedef struct slice_t slice_t;

void sl_initialize(slice_t* slice, int product)
{
  slice->_product = product;
}

int arr_find(int slice[], int target)
{
  int i;
  for (i = 0; i < MAX_SLICE; i++)
    if (slice[i] == target)
      return i;
  return 0;
}

int arr_product(int slice[])
{
  int result = 1;
  int i;
  for (i = 0; i < MAX_SLICE; i++)
    result *= slice[i];
  return result;
}

// helper method to print out all numbers in an array
char* arr_tostring(int slice[], int size, char* string)
{
  strcpy(string, "");
  int i;
  for (i = 0; i < size; i++)
  {
    char tmp[10];
    sprintf(tmp, " %d", slice[i]);
    strcat(string, tmp);
  }
  return string;
}

int* arr_copy(int lhs[], int rhs[])
{
  int i;
  for (i = 0; i < MAX_SLICE; i++)
    lhs[i] = rhs[i];
  return lhs;
}

void sl_copy(slice_t* lhs, slice_t* rhs)
{
  arr_copy(lhs->_data, rhs->_data);
  lhs->_product = rhs->_product;
}

// this method looks for a slice of 4 integers whose product is greater than max.
// if found, it returns a pointer to the slice. if not found, it returns NULL
void find_max(int row[], int size, slice_t* max)
{
  char string[200];
  printf("data:%s\n", arr_tostring(row, size, string));

  int* result = NULL;
  int start = 0;
  // while end of row is not reached
  while (start+MAX_SLICE-1 < size)
  {
    // take a slice of 4 adjacent numbers
    // if the slice contains 0, then skip to the next slice beyond the 0,
    // because a product of anything and 0 is 0.
    int* slice = row + start;
    int index;
    if (index = arr_find(slice, 0))
      start += index + 1;
    else
    {
      // calculate the product of the 4 integers in the slice
      int product = arr_product(slice);
      // update max if necessary
      if (product > max->_product)
      {
        char string[20];
        printf("current: %d, new: %d, slice:%s\n", max->_product, product, arr_tostring(slice, MAX_SLICE, string));

        arr_copy(max->_data, slice);
        max->_product = product;
      }
      // move on to the next slice
      start += 1;
    }
  }
}

struct grid_t
{
  int _data[MAX_ROW][MAX_COLUMN];
  slice_t _max;
};
typedef struct grid_t grid_t;

// this method extracts one row at position i from the grid
int* gr_row(grid_t* grid, int i, int result[])
{
  int j;
  for (j = 0; j < MAX_COLUMN; j++)
    result[j] = grid->_data[i][j];
  return result;
}

// this method extracts one column at position j from the grid
int* gr_column(grid_t* grid, int i, int result[])
{
  int j;
  for (j = 0; j < MAX_ROW; j++)
    result[j] = grid->_data[j][i];
  return result;
}

// This method extracts all numbers from grid starting at position (i,j) going
// down diagonally. This method is called in a loop starting at i=16 and j=0,
// and ending at i=0 and j=0.
int* gr_diagonal_down_first(grid_t* grid, int i, int j, int result[], int* size)
{
  *size = 0;
  while (i < MAX_ROW)
  {
    result[*size] = grid->_data[i][j];
    i += 1;
    j += 1;
    *size += 1;
  }
  return result;
}

// This method extracts all numbers from grid starting at position (i,j) going
// down diagonally. This method is called in a loop starting at i=0 and j=1,
// and ending at i=0 and j=16.
int* gr_diagonal_down_last(grid_t* grid, int i, int j, int result[], int* size)
{
  *size = 0;
  while (j < MAX_COLUMN)
  {
    result[*size] = grid->_data[i][j];
    i += 1;
    j += 1;
    *size += 1;
  }
  return result;
}

// This method extracts all numbers from grid starting at position (i,j) going
// up diagonally. This method is called in a loop starting at i=3 and j=0,
// and ending at i=19 and j=0.
int* gr_diagonal_up_first(grid_t* grid, int i, int j, int result[], int* size)
{
  *size = 0;
  while (i >= 0)
  {
    result[*size] = grid->_data[i][j];
    i -= 1;
    j += 1;
    *size += 1;
  }
  return result;
}

// This method extracts all numbers from grid starting at position (i,j) going
// up diagonally. This method is called in a loop starting at i=19 and j=1,
// and ending at i=19 and j=16.
int* gr_diagonal_up_last(grid_t* grid, int i, int j, int result[], int* size)
{
  *size = 0;
  while (j < MAX_COLUMN)
  {
    result[*size] = grid->_data[i][j];
    i -= 1;
    j += 1;
    *size += 1;
  }
  return result;
}

void report(slice_t* slice)
{
  char string[100];
  printf("MAX PRODUCT: %d, slice:%s\n", slice->_product, arr_tostring(slice->_data, MAX_SLICE, string));
}

// this method converts a string containing 20 integers separated by spaces into
// an array of 20 integers
void st_toarray(char* string, int array[])
{
  int j;
  char* token;
  for (token = strtok(string, " "), j = 0; token; token = strtok(NULL, " "), j++)
    array[j] = atoi(token);
}

void initialize(int data[][MAX_COLUMN])
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
  int i;
  for (i = 0; i < MAX_ROW; i++)
    st_toarray(input[i], data[i]);
}

void gr_initialize(grid_t* this)
{
  initialize(this->_data);
  sl_initialize(&this->_max, 0);
}

void main()
{
  grid_t grid;
  gr_initialize(&grid);

  int i;
  for (i = 0; i < MAX_ROW; i++)
  {
    int row[MAX_COLUMN];
    gr_row(&grid, i, row);
    find_max(row, MAX_COLUMN, &grid._max);
  }
  report(&grid._max);

  int j;
  for (j = 0; j < MAX_COLUMN; j++)
  {
    int column[MAX_ROW];
    gr_column(&grid, j, column);
    find_max(column, MAX_ROW, &grid._max);
  }
  report(&grid._max);

  for (i = MAX_ROW-MAX_SLICE; i >= 0; i--)
  {
    int diagonal[MAX_COLUMN];
    int size;
    gr_diagonal_down_first(&grid, i, 0, diagonal, &size);
    find_max(diagonal, size, &grid._max);
  }
  report(&grid._max);

  for (j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
  {
    int diagonal[MAX_ROW];
    int size;
    gr_diagonal_down_last(&grid, 0, j, diagonal, &size);
    find_max(diagonal, size, &grid._max);
  }
  report(&grid._max);

  for (i = MAX_SLICE-1; i <= MAX_ROW-1; i++)
  {
    int diagonal[MAX_COLUMN];
    int size;
    gr_diagonal_up_first(&grid, i, 0, diagonal, &size);
    find_max(diagonal, size, &grid._max);
  }
  report(&grid._max);

  for (j = 1; j <= MAX_COLUMN-MAX_SLICE; j++)
  {
    int diagonal[MAX_ROW];
    int size;
    gr_diagonal_up_last(&grid, MAX_ROW-1, j, diagonal, &size);
    find_max(diagonal, size, &grid._max);
  }
  report(&grid._max);
}
