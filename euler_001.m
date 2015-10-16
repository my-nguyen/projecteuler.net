// gcc euler_001.m -std=gnu99 `gnustep-config --objc-flags` -lobjc -lgnustep-base
// for an explanation to the geo_sum/arithmetic solution, refer to:
// http://www.mathblog.dk/project-euler-problem-1/
#import <Foundation/Foundation.h>

int sum(NSMutableArray* array)
{
  int sum = 0;
  for (int i = 0; i < [array count]; i++)
    sum += [[array objectAtIndex:i] intValue];
  return sum;
}

int mine_sum(int limit)
{
  NSMutableArray *multiples = [[[NSMutableArray alloc] init] autorelease];

  // collect all multiples of 3
  for (int j = 1; j <= limit/3; j++)
    [multiples addObject:[NSNumber numberWithInt:(j*3)]];

  // collect all multiples of 5
  for (int j = 1; j <= limit/5; j++)
    if (j % 3 != 0)
      [multiples addObject:[NSNumber numberWithInt:(j*5)]];

  return sum(multiples);
}

// sum of multiples of 3: 3+6+9+12+…+999 = 3*(1+2+3+4+…+333)
// whereas 1+2+3+4+…+N = N*(N+1)/2
// so sum of multiples of 3 is 3*(N*(N+1)/2) where N=999/3=333
// similarly, sum of multiples of 5 is 5*(N*(N+1)/2) where N=999/5=199
int sum_of_multiples(int divisor, int limit)
{
  int N = limit/divisor;
  return divisor * (N * (N+1) / 2);
}

int geo_sum(int limit)
{
  return sum_of_multiples(3, limit) + sum_of_multiples(5, limit) - sum_of_multiples(15, limit);
}

int main()
{
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  int limit = 999;
  printf("Brute force: %d\n", mine_sum(limit));
  printf("Geometric: %d\n", geo_sum(limit));
  [pool drain];
  return 0;
}
