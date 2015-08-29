#include <stdio.h>

int mycompare(const void* left, const void* right)
{
  return *((const int*)left) - *((const int*)right);
}

int array_push(int* array, int* size, int element)
{
  array[*size] = element;
  *size += 1;
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
