import java.util.BitSet;

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number.
class sieve
{
  BitSet field;

  // the 101st prime is 547
  // the 1,001st prime is 7,927
  // the 10,001st prime is 104,743
  // the 50,001st prime is 611,957
  // This constructor fills an array of bools up to a certain size, with prime
  // numbers marked as ON bit and non-prime as OFF
  sieve(int size)
  {
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

  // this method returns the natural number of the prime number at position. for
  // example, for the prime number at 100, it returns 541. for the prime number
  // at 1000, it returns 7919. for the prime number at 5000, it returns 48611.
  int index(int position)
  {
    // index to the entire bool array
    int i = 1;
    // index by prime numbers
    int j = 1;
    while (j < position)
    {
      i += 2;
      if (field.get(i))
        j += 1;
    }
    return i;
  }

  // this method returns the sum of all prime numbers in the bool array.
  long sum()
  {
    // sum includes 2, the first prime number (at index 0) so that index i
    // (which starts at 1) can increment by 2
    long sum = 2;
    for (int i = 1; i < field.size(); i += 2)
      if (field.get(i))
        sum += i;

    return sum;
  }
}
