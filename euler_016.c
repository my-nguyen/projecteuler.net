// this program test-uses the GMP library for computing with huge numbers
// must compile with -lgmp at the end (and not in the middle)
// since GMP is C and not C++, and since this entire program doesn't have any
// OOP feature, it's written in C instead of C++
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>

void main()
{
  int exponents[] = { 15, 50, 100, 250, 500, 750, 1000 };

  // declare, initialize and set an integer from GMP library
  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);

  int i;
  for (i = 0; i < sizeof(exponents)/sizeof(int); i++)
  {
    // compute with GMP power function
    mpz_t power;
    mpz_init(power);
    mpz_pow_ui(power, base, exponents[i]);

    char* string = mpz_get_str(NULL, 10, power);
    int sum = 0;
    int j;
    for (j = 0; j < strlen(string); j++)
      sum += string[j] - '0';

    printf("2^%d: %s, sum: %d\n", exponents[i], string, sum);
    // printf("length: %ld\n", strlen(string));
    free(string);
  }
}
