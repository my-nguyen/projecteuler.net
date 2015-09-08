import java.util.BitSet;

class primes
{
  // Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
  // up to a target number
  // This algorithm proves to be a vast improvement on my older prime-finding
  // algorithm: while the older version took 13 seconds, this new version took
  // less than 1 second.
  // This method finds all prime numbers from 2 up to size and stores them in an
  // array, with prime numbers represented as ON bit and non-prime as OFF
  public primes(int size)
  {
    _field = new BitSet(size);

    // initialize all bits to ON
    _field.set(0, size);

    // numbers 0 and 1 are not primes
    _field.clear(0);
    _field.clear(1);

    // start with 2, the very first prime number
    for (int i = 2; i < size; i++)
    {
      // test whether bit at i is ON
      if (_field.get(i))
      {
        int multiple = 2;
        while (i*multiple < size)
        {
          // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
          // So turn off bit at (i*multiple)th position.
          _field.clear(i*multiple);
          multiple += 1;
        }
      }
    }
  }

  public long index(int position)
  {
    // index to the entire bool array
    int i = 1;
    // index only up to target
    int j = 0;
    while (j < position)
    {
      i += 1;
      if (_field.get(i))
        j += 1;
    }
    return i;
  }

  public long sum()
  {
    long sum = 0;
    // iterate the entire bitfield
    for (int i = 0; i < _field.size(); i++)
      if (_field.get(i))
        sum += i;
    return sum;
  }

  private BitSet _field;
}
