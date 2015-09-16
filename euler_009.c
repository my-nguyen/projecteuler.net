// According to Wikipedia, Euclid's formula is a fundamental formula for
// generating Pythagorean triples given an arbitrary pair of positive integers
// m and n with m > n. The formula states that the integers
// a = m*m - n*n
// b = 2*m*n
// c = m*m + n*n
#include <stdio.h>
#include <math.h>   // sqrt(), abs()
#include <string.h>

// This method returns the sum of a+b+c
// a + b + c = m*m - n*n + 2*m*n + m*m + n*n, or 2*m*(m+n)
int sum_abc(int m, int n)
{
  return 2 * m * (m + n);
}

int compare(const void* left, const void* right)
{
  return *((const int*)left) - *((const int*)right);
}

#define TRIPLET 3
// This method returns a pythagorean triplet [a, b, c] if such a triplet is found.
// if not it returns nil.
int* pythagorean_triplets(int target, int triplet[])
{
  int m = 0;
  // since c = m*m + n*n, and a+b+c = 1000, both m*m and n*n must be < 1000,
  // or m <= 31 and n <= 31
  while (m <= (int)sqrt(target))
  {
    m += 1;
    int n = 1;
    // calculate all sums of a+b+c based on m and n between 1 and 31.
    while (n <= (int)sqrt(target))
    {
      int sum = sum_abc(m, n);
      if (sum < target)
        // keep trying with the next n
        n += 1;
      else if (sum == target)
      {
        // m equals n means (m*m - n*n).abs equals 0, OR a equals 0 and b equals c,
        // which violates the requirement a < b < c. since the largest n is reached,
        // restart with the next m and n at 1.
        if (m == n)
          break;
        else
        {
          // m and n are found. return immediately the triplet [a, b, c]
          triplet[0] = abs(m*m - n*n);
          triplet[1] = 2*m*n;
          triplet[2] = m*m + n*n;
          qsort(triplet, TRIPLET, sizeof(int), compare);
          return triplet;
        }
      }
      else
        // the largest n is reached. let's restart with the next m and n at 1
        break;
    }
  }

  // return nil if no such triplet is found
  return NULL;
}

// this method returns the product of 3 integers contained in an array
int product(int triplet[])
{
  int prod = 1;
  int i;
  for (i = 0; i < TRIPLET; i++)
    prod *= triplet[i];
  return prod;
}

// this method converts an array of 3 integers into a printable string format
char* tostring(int triplet[], char string[])
{
  strcpy(string, "[");
  int i;
  for (i = 0; i < TRIPLET; i++)
  {
    if (i)
      strcat(string, ", ");
    sprintf(string+strlen(string), "%d", triplet[i]);
  }
  return strcat(string, "]");
}

void main()
{
  int targets[] = {50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    int triplet[TRIPLET];
    int* result = pythagorean_triplets(targets[i], triplet);
    printf("triplet(%d): ", targets[i]);
    if (result == NULL)
      printf("none found\n");
    else
    {
      char print[30];
      printf("product %d from %s\n", product(triplet), tostring(triplet, print));
    }
  }
}
