// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1)
// contains 10 terms. Although it has not been proved yet (Collatz Problem), it
// is thought that all starting numbers finish at 1.
// Which starting number, under one million, produces the longest chain?
// NOTE: Once the chain starts the terms are allowed to go above one million.
//
import java.util.*;

public class euler_014
{
  static final int MAX_NUMBER = 1000000;

  // this method returns the next number in the Collatz sequence. must use long
  // instead of int here, since the calculation could turn a positive integer
  // into a negative one.
  static long next(long current)
  {
    return (current % 2 == 0) ? current/2 : (3*current + 1);
  }

  // this method returns the length of the sequence started with number. there's
  // no need to retain the integers that form the sequence, just return the length
  static int sequence(long number)
  {
    int length = 0;
    while (number != 1)
    {
      length++;
      number = next(number);
    }
    return length;
  }

  public static void main(String[] args)
  {
    // Java doesnt' allow an array of List
    // List<Integer>[] table = new List<Integer>[MAX_NUMBER];
    // But with 1000000 entries, the following legit declaration would cause
    // the system to run out of memory:
    // List<List<Integer>> table = new ArrayList<List<Integer>>(MAX_NUMBER);
    // So forget List. Just retain the index to the sequence with highest length,
    // and retain the length instead of the whole sequence
    int max_index = 0;
    int max_sequence = 0;

    // only start retaining Collatz sequences at 2
    for (int i = 2; i < MAX_NUMBER; i++)
    {
      int sequence = sequence(i);
      if (sequence > max_sequence)
      {
        max_index = i;
        max_sequence = sequence;
        System.out.println("number: " + i + ", length: " + sequence);
      }
    }
  }
}
