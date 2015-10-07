// gcc euler_006.c -lgmp
#include <stdio.h>
#include <gmp.h>

void mine_square_sum(long max, mpz_t sum)
{
  mpz_set_ui(sum, 0);
  long i;
  for (i = 1; i <= max; i++)
    mpz_add_ui(sum, sum, i);
  mpz_pow_ui(sum, sum, 2);
}

void mine_sum_squares(long max, mpz_t sum)
{
  mpz_set_ui(sum, 0);
  long i;
  for (i = 1; i <= max; i++)
  {
    mpz_t square;
    mpz_init(square);
    mpz_set_ui(square, i);
    mpz_pow_ui(square, square, 2);
    mpz_add(sum, sum, square);
  }
}

// 1+2+3+4+…+N = N*(N+1)/2
void arith_square_sum(long max, mpz_t sum)
{
  mpz_set_ui(sum, max/2);
  mpz_mul_ui(sum, sum, max+1);
  mpz_pow_ui(sum, sum, 2);
}

// sum of squares = N*(N+1)*(2*N+1)/6;
void arith_sum_squares(long max, mpz_t sum)
{
  mpz_set_ui(sum, max);
  mpz_mul_ui(sum, sum, max+1);
  mpz_mul_ui(sum, sum, 2*max+1);
  mpz_cdiv_q_ui(sum, sum, 6);
}

void main()
{
  long targets[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
  // long targets[] = {100000};
  int i;
  for (i = 0; i < sizeof(targets)/sizeof(long); i++)
  {
    long target = targets[i];
    mpz_t sum;
    mpz_init(sum);
    mine_square_sum(target, sum);
    mpz_t squares;
    mpz_init(squares);
    mine_sum_squares(target, squares);
    mpz_t result;
    mpz_init(result);
    mpz_sub(result, sum, squares);
    printf("Mine(%ld): ", target);
    mpz_out_str(stdout, 10, result);
    printf("\n");
  }
  for (i = 0; i < sizeof(targets)/sizeof(long); i++)
  {
    long target = targets[i];
    mpz_t sum;
    mpz_init(sum);
    arith_square_sum(target, sum);
    mpz_t squares;
    mpz_init(squares);
    arith_sum_squares(target, squares);
    mpz_t result;
    mpz_init(result);
    mpz_sub(result, sum, squares);
    printf("Arithmetic(%ld): ", target);
    mpz_out_str(stdout, 10, result);
    printf("\n");
  }
}
