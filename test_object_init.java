import java.util.*;

class test_object_init
{
  public static void main(String[] args)
  {
    class target_t
    {
      public target_t(int p, int s)
      {
        prime = p;
        space = s;
      }
      int prime;
      int space;
    }

    target_t target = new target_t(6, 20);
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
  }
}
