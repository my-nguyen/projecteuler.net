// for an explanation to the geo_sum/arithmetic solution, refer to:
// http://www.mathblog.dk/project-euler-problem-1/
import java.util.*;

class euler_001
{
  static int sum(List<Integer> array)
  {
    int sum = 0;
    for (int number : array)
      sum += number;
    return sum;
  }

  static int mine_sum(int limit)
  {
    List<Integer> multiples = new ArrayList<>();

    // collect all multiples of 3
    for (int j = 1; j <= limit/3; j++)
      multiples.add(j * 3);

    // collect all multiples of 5
    for (int j = 1; j <= limit/5; j++)
      if (j % 3 != 0)
        multiples.add(j * 5);

    return sum(multiples);
  }

  // sum of multiples of 3: 3+6+9+12+…+999 = 3*(1+2+3+4+…+333)
  // whereas 1+2+3+4+…+N = N*(N+1)/2
  // so sum of multiples of 3 is 3*(N*(N+1)/2) where N=999/3=333
  // similarly, sum of multiples of 5 is 5*(N*(N+1)/2) where N=999/5=199
  static int sum_of_multiples(int divisor, int limit)
  {
    int N = limit/divisor;
    return divisor * (N * (N+1) / 2);
  }

  static int geo_sum(int limit)
  {
    return sum_of_multiples(3, limit) + sum_of_multiples(5, limit) - sum_of_multiples(15, limit);
  }

  public static void main(String[] args)
  {
    int limit = 999;
    System.out.println("Brute force: " + mine_sum(limit));
    System.out.println("Geometric: " + geo_sum(limit));
  }
}
