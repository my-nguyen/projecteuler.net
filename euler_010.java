import java.util.*;

class Primes
{
  BitSet field;
  int index;

  // Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
  // up to a target number.
  // This constructor fills an array of bools from 2 to order, with prime
  // numbers marked as ON bit and non-prime as OFF
  Primes(int position)
  {
    index = position;

    // the 100th prime is 541, the 1000th prime is 7919, the 10000th prime is
    // 104729, the 100000th prime is 1299709 so size is roughly 13 times the
    // prime number/position
    int size = position * 20;
    field = new BitSet(size);

    // initialize all bits to ON
    field.set(0, size);

    // numbers 0 and 1 are not primes
    field.clear(0);
    field.clear(1);

    // start with 2, the very first prime number
    for (int i = 2; i < size; i++)
    {
      // test whether bit at i is ON
      if (field.get(i))
      {
        int multiple = 2;
        while (i*multiple < size)
        {
          // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
          // So turn off bit at (i*multiple)th position.
          field.clear(i*multiple);
          multiple += 1;
        }
      }
    }
  }

  // this method returns the natural number of the prime number at position.
  // for example, for prime at position 100, it returns 541. for prime at 1000,
  // it returns 7919. for prime at 5000, it returns 48611.
  long index()
  {
    // index to the entire bool array
    long result = 1;
    // index by prime numbers
    int j = 1;
    while (j < index)
    {
      result += 2;
      if (field.get(result))
        j += 1;
    }
    return result;
  }

  long sum()
  {
    long sum = 0;
    // iterate the entire bitfield
    for (int i = 0; i < _field.size(); i++)
      if (_field.get(i))
        sum += i;
    return sum;
  }
}

class euler_010
{

  public static void main(String[] args)
  {
    int targets[] = {10, 100000, 500000, 1000000, 1500000, 2000000};
    for (int target : targets)
    {
      System.out.println("Sum primes(" + target + "): " + sieve_index(target));
    }
  }
}
