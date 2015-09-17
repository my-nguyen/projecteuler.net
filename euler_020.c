#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>

void factorial(int number, mpz_t product)
{
  mpz_init(product);
  mpz_set_ui(product, 1);
  int i;
  for (i = 1; i <= number; i++)
    mpz_mul_si(product, product, i);
}

void main()
{
  int targets[] = { 10, 100 };
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
  {
    // take the factorial of target number, the factorial being a BigInteger,
    // convert the BigInteger into a String, then convert the String into an
    // array of digit-characters, before summing up all the digits in the array
    mpz_t factor;
    factorial(targets[i], factor);
    char* string = mpz_get_str(NULL, 10, factor);
    int sum = 0;
    int j;
    for (j = 0; j < strlen(string); j++)
      sum += string[j] - '0';

    printf("factorial(%d): ", targets[i]);
    mpz_out_str(stdout, 10, factor);
    printf(", sum: %d\n", sum);
  }
}
