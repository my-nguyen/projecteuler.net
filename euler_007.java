import java.util.List;
import java.util.ArrayList;

class euler_007
{
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
      primes myprimes = new primes(target.space);

      System.out.println("prime(" + target.prime + "): " + myprimes.index(target.prime));
    }
  }
}
