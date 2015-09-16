// According to Wikipedia, Euclid's formula is a fundamental formula for
// generating Pythagorean triples given an arbitrary pair of positive integers
// m and n with m > n. The formula states that the integers
// a = m*m - n*n
// b = 2*m*n
// c = m*m + n*n
import java.lang.Math; // sqrt(), abs()
import java.util.Arrays;

class euler_009
{
  // This method returns the sum of a+b+c
  // a + b + c = m*m - n*n + 2*m*n + m*m + n*n, or 2*m*(m+n)
  static int sum_abc(int m, int n)
  {
    return 2 * m * (m + n);
  }

  final static int TRIPLET = 3;
  // This method returns a pythagorean triplet [a, b, c] if such a triplet is found.
  // if not it returns nil.
  static int[] pythagorean_triplets(int target)
  {
    int[] triplet = null;
    int m = 0;
    // since c = m*m + n*n, and a+b+c = 1000, both m*m and n*n must be < 1000,
    // or m <= 31 and n <= 31
    while (m <= (int)Math.sqrt(target))
    {
      m += 1;
      int n = 1;
      // calculate all sums of a+b+c based on m and n between 1 and 31.
      while (n <= (int)Math.sqrt(target))
      {
        int sum = sum_abc(m, n);
        if (sum < target)
          // keep trying with the next n
          n += 1;
        else if (sum == target)
        {
          // m equals n means (m*m - n*n).abs equals 0, OR a equals 0 and b equals c,
          // which violates the requirement a < b < c. since the largest n is reached,
          // restart with the next m and n at 1.
          if (m == n)
            break;
          else
          {
            // m and n are found. return immediately the triplet [a, b, c]
            triplet = new int[TRIPLET];
            triplet[0] = Math.abs(m*m - n*n);
            triplet[1] = 2*m*n;
            triplet[2] = m*m + n*n;
            Arrays.sort(triplet);
            return triplet;
          }
        }
        else
          // the largest n is reached. let's restart with the next m and n at 1
          break;
      }
    }

    // return nil if no such triplet is found
    return null;
  }

  // this method returns the product of 3 integers contained in an array
  static int product(int triplet[])
  {
    int prod = 1;
    for (int i = 0; i < TRIPLET; i++)
      prod *= triplet[i];
    return prod;
  }

  // this method converts an array of 3 integers into a printable string format
  static String toString(int[] triplet)
  {
    StringBuilder out = new StringBuilder();
    out.append("[");
    for (int i = 0; i < TRIPLET; i++)
    {
      if (i != 0)
        out.append(", ");
      out.append(triplet[i]);
    }
    return out.append("]").toString();
  }

  public static void main(String[] args)
  {
    int targets[] = {50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    for (int target : targets)
    {
      System.out.print("triplet(" + target + "): ");
      int[] triplet = pythagorean_triplets(target);
      if (triplet == null)
        System.out.println("none found");
      else
        System.out.println("product " + product(triplet) + " from " + toString(triplet));
    }
  }
}
