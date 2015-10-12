public class euler_014
{
  static final int MAX_NUMBER = 1000000;

  static void longest_sequence()
  {
    // Java doesnt' allow an array of List:
    // List<Integer>[] table = new List<Integer>[MAX_NUMBER]; // invalid
    // So a List of List was considered:
    // List<List<Integer>> table = new ArrayList<List<Integer>>(MAX_NUMBER);
    // But with 1000000 entries, that would cause the system to run out of memory
    // So forget List. Just retain the index to the term with highest
    // sequence, and retain the sequence instead of the whole term
    int max_index = 0;
    int max_sequence = 0;

    // only start retaining Collatz terms at 2
    for (int index = 2; index <= MAX_NUMBER; index++)
    {
      int sequence = 1;
      long term = index;
      while (term != 1)
      {
        sequence += 1;
        // get the next number in the Collatz term. term needs to be of
        // type long; if it were of type int, then (3*term + 1) would
        // overflow the max integer
        term = (term % 2 == 0) ? term/2 : (3*term + 1);
      }

      if (sequence > max_sequence)
      {
        max_index = index;
        max_sequence = sequence;
        System.out.println("number: " + index + ", sequence: " + sequence);
      }
    }
  }

  static void caching()
  {
    int max_index = 0;
    int max_sequence = 0;

    // cache storage of sequence length of all numbers up to the current one,
    // and will eventually store all 1000000 sequence lengths.
    int[] cache = new int[MAX_NUMBER+1];
    for (int number : cache)
      number = 0;
    cache[1] = 1;

    for (int index = 2; index <= MAX_NUMBER; index++)
    {
      int sequence = 0;
      long term = index;
      // if term < index, then it's already in cache
      while (term != 1 && term >= index)
      {
        sequence += 1;
        term = (term % 2 == 0) ? term/2 : (3*term + 1);
      }

      // cache[1] is 1
      // cache[2] is 2 (2, {cache[1]})
      // cache[3] is 8 (3, 10, 5, 16, 8, 4, {cache[2]})
      // cache[4] is 3 (4, {cache[2]})
      // cache[5] is 6 (5, 16, 8, {cache[4]})
      cache[index] = sequence + cache[(int)term];
      // System.out.println("index: " + index + ", cache[" + index + "]: " + cache[index] + ", sequence: " + sequence + ", term: " + term + ", cache[" + term + "]: " + cache[(int)term]);
      if (cache[index] > max_sequence)
      {
        max_index = index;
        max_sequence = cache[index];
        System.out.println("caching: " + index + ", sequence: " + cache[index]);
      }
    }
  }

  public static void main(String[] args)
  {
    longest_sequence();
    caching();
  }
}
