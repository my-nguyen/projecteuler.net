// must compile as: g++ test_gmp.cpp -lgmp
// and not as: g++ -lgmp test_gmp.cpp
#include <stdio.h>
#include <gmp.h>

void main()
{
  // first declare a variable of type mpz_t
  mpz_t base;
  // second, initialize the variable
  mpz_init(base);
  // third, set the variable to some integer
  mpz_set_ui(base, 2);

  unsigned long exponent = 10;
  // how to compute using the power function
  mpz_t huge;
  mpz_init(huge);
  mpz_pow_ui(huge, base, exponent);
  printf("power(");
  // how to print an mpz_t
  mpz_out_str(stdout, 10, base);
  printf(", %lu): ", exponent);
  mpz_out_str(stdout, 10, huge);
  printf("\n");

  char string[600];
  printf("string: %s\n", mpz_get_str(string, 10, huge));
}
