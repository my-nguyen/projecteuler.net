// gcc euler_003.m -std=gnu99 `gnustep-config --objc-flags` -lobjc -lgnustep-base
// for an explanation to the geo_sum/arithmetic solution, refer to:
// http://www.mathblog.dk/project-euler-problem-1/
#import <Foundation/Foundation.h>

long largest_prime(long target)
{
  long prime = 2;
  while (target > prime)
    // if target is divisible by the current prime number, then keep dividing
    // target by the current prime number. that way, if target is divisible by
    // 4, 8, 16, 32, the repeated divisions by 2 will take care of those
    // powers of 2. similarly, if target is divisible by 9, 27, 81, the
    // repeated divisions by 3 will take care of those powers of 3. and so on.
    if (target % prime == 0)
      target /= prime;
    // otherwise move on to the next number
    else
      prime += 1;
  // the last standing prime is the result looked for.
  return prime;
}

long alternative(long target)
{
  long number = target;
  long largest = 0;
  int count = 2;
  while (count*count <= number)
    if (number % count == 0)
    {
      number /= count;
      largest = count;
    }
    else
      count += 1;
  if (number > largest)
    largest = number;
  return largest;
}

int main()
{
  // NSArray *targets = @[ @(13915), @(475143), @(1475143), @(51475143), @(1851475143), @(10851475143), @(600851475143) ];
  long targets[] = {13915, 475143, 1475143, 51475143, 1851475143, 10851475143, 600851475143};
  for (int i = 0; i < sizeof(targets)/sizeof(long); i++)
    printf("target: %ld, largest prime: %ld\n", targets[i], largest_prime(targets[i]));
  for (int i = 0; i < sizeof(targets)/sizeof(long); i++)
    printf("target: %ld, alternative: %ld\n", targets[i], largest_prime(targets[i]));
}
