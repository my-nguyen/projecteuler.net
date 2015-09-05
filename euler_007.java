import java.util.BitSet;
import java.util.List;
import java.util.ArrayList;

class euler_007
{
  // Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
  // up to a target number
  // This algorithm proves to be a vast improvement on my older prime-finding
  // algorithm: while the older version took 13 seconds, this new version took
  // less than 1 second.
  // This method finds all prime numbers from 2 up to size and stores them in an
  // array, with prime numbers represented as ON bit and non-prime as OFF
  private static void get_primes(BitSet field)
  {
    // numbers 0 and 1 are not primes
    field.clear(0);
    field.clear(1);

    // start with 2, the very first prime number
    for (int i = 2; i < field.length(); i++)
    {
      // test whether bit at i is ON
      if (field.get(i))
      {
        int multiple = 2;
        while (i*multiple <= field.length())
        {
          // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
          // So turn off bit at (i*multiple)th position.
          field.clear(i*multiple);
          multiple += 1;
        }
      }
    }
  }

  // this method converts an array of booleans, where ON elements represent prime
  // numbers and OFF otherwise, into an array of prime numbers
  private static void pack_primes(BitSet field, List<Integer> primes)
  {
    for (int i = 0; i < field.length(); i++)
      if (field.get(i))
        primes.add(i);
  }

  public static void main(String[] args)
  {
    final class target_t
    {
      target_t(int p, int s)
      {
        prime = p;
        space = s;
      }

      int prime; // which prime number to get to
      int space; // how much space is needed to cover the prime number
    };

    List<target_t> targets = new ArrayList<target_t>();
    targets.add(new target_t(6, 20));
    targets.add(new target_t(11, 50));
    targets.add(new target_t(101, 600));
    targets.add(new target_t(1001, 8100));
    targets.add(new target_t(2001, 17500));
    targets.add(new target_t(3001, 27600));
    targets.add(new target_t(4001, 38000));
    targets.add(new target_t(5001, 48800));
    targets.add(new target_t(6001, 59500));
    targets.add(new target_t(7001, 70800));
    targets.add(new target_t(8001, 82000));
    targets.add(new target_t(9001, 93300));
    targets.add(new target_t(10001, 105000));

    for (target_t target : targets)
    {
      // First, obtain all prime numbers up to space. The prime numbers are ON bits
      // while the non-prime numbers are OFF bits.
      BitSet field = new BitSet(target.space);
      // initialize all bits to ON
      field.set(0, target.space);
      get_primes(field);

      // Next, extract those ON bits into another array of prime numbers
      List<Integer> primes = new ArrayList<Integer>();
      pack_primes(field, primes);

      System.out.println("found " + primes.size() + " prime numbers below " + target.space);
      // array_print(primes, prime_count);
      System.out.println("the " + target.prime + "th prime number is " + primes.get(target.prime-1));
      System.out.println("**********************************************");
    }
  }
}
