// Refer to 001.multiples_of_3_and_5.rb for clarifying comments.
// Compile with gcc
#include <stdio.h>

int mycompare(const void* left, const void* right)
{
  return *((const int*)left) - *((const int*)right);
}

int array_push(int* array, int size, int element)
{
  array[size] = element;
  return size + 1;
}
void array_sort(int* array, int size)
{
  qsort(array, size, sizeof(int), mycompare);
}

int array_sum(int* array, int size)
{
  int sum = 0;
  int i;
  for (i = 0; i < size; i++)
    sum += array[i];
  return sum;
}

void array_print(int* array, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf(" %d", array[i]);
    if ((i+1) % 10 == 0)
      printf("\n");
  }
  printf("\n");
}

void main()
{
  int limits[] = {10, 20, 100, 500, 1000};
  int i;
  for (i = 0; i < 5; i++)
  {
    int multiples[1000];
    int size = 0;

    int highest_3 = (limits[i]-1) / 3;
    int j;
    for (j = 1; j <= highest_3; j++)
      size = array_push(multiples, size, (j*3));

    int highest_5 = (limits[i]-1) / 5;
    for (j = 1; j <= highest_5; j++)
      if (j % 3 != 0)
        size = array_push(multiples, size, (j*5));

    array_sort(multiples, size);
    printf("limit: %d, sum: %d\n", limits[i], array_sum(multiples, size));
    // array_print(multiples, size);
  }
}
