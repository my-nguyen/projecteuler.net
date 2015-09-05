#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX 32

char* decimal2binary(int decimal, char binary[])
{
  int i = 0;
  while (decimal)
  {
    binary[i] = (decimal % 2 ? '1' : '0');
    i += 1;
    decimal /= 2;
  }
  return binary;
}

char* decimal2binary2(int decimal, char binary[])
{
  int i = 0;
  // while (decimal)
  for (i = 0; i < MAX; i++)
  {
    binary[i] = (decimal & 1 ? '1' : '0');
    // i += 1;
    decimal >>= 1;
  }
  return binary;
}

void main()
{
  srand(time(NULL));
  int i = 0;
  for (i = 0; i < 10; i++)
  {
    char binary[MAX+1];
    memset(binary, '0', MAX);
    binary[MAX] = '\0';
// printf("binary: %s\n", binary);
    int decimal = 0xffffffff;
    printf("decimal: %d\tbinary: %s\n", decimal, decimal2binary(decimal, binary));
    printf("decimal: %d\tbinary: %s\n", decimal, decimal2binary2(decimal, binary));
  }
}
