#include <stdio.h>

int gcd( int a, int b) {
	int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int pollard_rho(int target)
{
  int i = 1;
  int x = rand() % target;
  int y = x;
  int k = 2;
  while (1)
  {
    int d;
    i += 1;
    x = (x*x - 1) % target;
    d = gcd(abs(y - x), target);
    if (d != 1 && d != target)
      return d;
    if (i == k)
    {
      y = x;
      k *= 2;
    }
  }
}

void main()
{
  int targets[] = {3239, 16843009, 13915, 475143};
  int i;
  srand(time(NULL));
  for (i = 0; i < sizeof(targets)/sizeof(int); i++)
    printf("target: %d, factor: %d\n", targets[i], pollard_rho(targets[i]));
}
