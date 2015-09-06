#include <stdio.h>
#include <string.h>

char* arr_tostring(int array[], int size, char string[])
{
  strcpy(string, "[");
  int i;
printf("string: %s\n", string);
  for (i = 0; i < size; i++)
  {
    if (i)
      strcat(string, ", ");
printf("string: %s\n", string);
    sprintf(string+strlen(string), "%d", array[i]);
printf("string: %s\n", string);
  }
  return strcat(string, "]");
}

void main()
{
  int array[] = {2, 4, 6, 8};
  char string[30] = "MY NGUYEN";
  arr_tostring(array, 4, string);
  printf("array: %s\n", string);
}
