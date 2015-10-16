// gcc euler_002.m -std=gnu99 `gnustep-config --objc-flags` -lobjc -lgnustep-base
// for an explanation to the "Even Only" solution, refer to:
// http://www.mathblog.dk/project-euler-problem-2/
#import <Foundation/Foundation.h>

int mine_sum(int limit)
{
  int fib1 = 1;
  int fib2 = 1;
  int fib3;
  int sum = 0;
  while ((fib3 = fib1 + fib2) < limit)
  {
    // take the sum of only even fibonacci numbers
    if (fib3 % 2 == 0)
      sum += fib3;
    fib1 = fib2;
    fib2 = fib3;
  }

  return sum;
}

// Fn = Fn-1 + Fn-2 =
// Fn-2 + Fn-3 + Fn-3 +Fn-4 = (since Fn-1 = Fn-2 + Fn-3 and so on)
// Fn-3 + Fn-4 + Fn-3 +Fn-3 +Fn-4 = 3Fn-3 + 2Fn-4 =
// 3Fn-3 + Fn-4 + Fn-5 + Fn-6) =
// 4Fn-3 + Fn-6 (since Fn-4 + Fn-5 = Fn-3)
int even_sum(int limit)
{
  int fib3 = 2;
  int fib6 = 0;
  int result = 2;
  int sum = 0;
  while (result < limit)
  {
    sum += result;
    result = 4*fib3 + fib6;
    fib6 = fib3;
    fib3 = result;
  }

  return sum;
}

int main()
{
  int limit = 4000000;
  printf("Mine: %d\n", mine_sum(limit));
  printf("Even only: %d\n", even_sum(limit));
}
