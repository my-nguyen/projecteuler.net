import java.util.*;

public class euler_031
{
  static List<List<Integer>> count(int total, int[] denominations)
  {
    List<List<Integer>> list = new ArrayList<List<Integer>>();
    // special case when there's only one denomination left: create and return a
    // List<List<Integer>> where the inner List<Integer> contains only the
    // division of total over the one denomination.
    if (denominations.length == 1)
    {
      List<Integer> sublist = new ArrayList<>();
      sublist.add(total/denominations[0]);
      list.add(sublist);
    }
    else
    {
      // try different combinations by multiplying the head denomination with
      // 0, 1, 2, etc.
      for (int i = 0; i <= total/denominations[0]; i++)
      {
        int new_total = total - denominations[0]*i;
        int[] sub_denominations = Arrays.copyOfRange(denominations, 1, denominations.length);
        // recursive call with a new total and a sub array formed by removing
        // the head element from the list of denominations.
        for (List<Integer> sublist : count(new_total, sub_denominations))
        {
          // generate a new List<List<Integer>> by prepending the head
          // denomination to the List<List<Integer>> returned from the recursive
          // call
          List<Integer> entry = new ArrayList<>();
          entry.add(i);
          entry.addAll(sublist);
          list.add(entry);
        }
      }
    }
    return list;
  }

  public static void main(String[] args)
  {
    int[] denominations = { 200, 100, 50, 20, 10, 5, 2, 1 };
    List<List<Integer>> list = count(200, denominations);
    for (List<Integer> sublist : list)
      System.out.println(sublist);
    System.out.println(list.size());
  }
}
