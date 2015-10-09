import java.util.BitSet;

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number.
class sieve
{
  BitSet field;
  int index;

  // the 20th prime is 71, the 200th prime is 1,223, the 2,000th prime is
  // 17,389, the 20,000th prime is 224,737, the 200,000th prime is 2,750,159,
  // and the 2,000,000th prime is 32,452,843 so the ratio of natural to prime
  // is roughly 17. round this ratio up to 20.
  final int NATURAL_2_PRIME = 20;
  // This constructor fills an array of bools up to a certain size, with prime
  // numbers marked as ON bit and non-prime as OFF
  sieve(int position)
  {
    index = position;
    int size = position * NATURAL_2_PRIME;
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

  // this method returns the natural number of the prime number at index. for
  // example, for the prime number at 100, it returns 541. for the prime number
  // at 1000, it returns 7919. for the prime number at 5000, it returns 48611.
  int index()
  {
    // index to the entire bool array
    int result = 1;
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
    for (int i = 0; i < field.size(); i++)
      if (field.get(i))
        sum += i;
    return sum;
  }
}
