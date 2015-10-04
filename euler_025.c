#include <stdio.h>
#include <gmp.h>

void main()
{
  mpz_t limit;
  mpz_init(limit);
  mpz_ui_pow_ui(limit, 10, 999);
  mpz_t fib1;
  mpz_init(fib1);
  mpz_set_ui(fib1, 1);
  mpz_t fib2;
  mpz_init(fib2);
  mpz_set_ui(fib2, 1);
  mpz_t fib3;
  mpz_init(fib3);
  mpz_add(fib3, fib1, fib2);
  int index = 3;
  while (mpz_cmp(fib3, limit) < 0)
  {
    mpz_set(fib1, fib2);
    mpz_set(fib2, fib3);
    mpz_add(fib3, fib1, fib2);
    index += 1;
  }

  printf("index: %d\n", index);
}
