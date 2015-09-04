// Euler 7, in C++, version A: ported from the C implementation
#include <iostream>
#include <cstring> // memset(), memcpy()
using namespace std;
const int BITS_PER_BYTE = 8;
const int BITS_PER_LONG = (sizeof(long)*BITS_PER_BYTE);

class bitfield
{
public:
  bitfield(int space);

  ~bitfield() { delete [] _field; }

  void print(unsigned long field);

  void clear(int long_index)
  { _field[byte_index(long_index)] &= ~(1l << bit_index(long_index)); }

  void set(int long_index)
  { _field[byte_index(long_index)] |= (1l << bit_index(long_index)); }

  unsigned long test(int long_index) const
  { return _field[byte_index(long_index)] & (1l << bit_index(long_index)); }

  int space() const { return _space; }

private:
  char* decimal2binary(long decimal, char binary[]);
  int byte_index(int long_index) const { return long_index / BITS_PER_LONG; }
  int bit_index(int long_index) const { return long_index % BITS_PER_LONG; }

  unsigned long* _field;
  int _space;
};

bitfield::bitfield(int space)
{
  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  int long_count = (space/BITS_PER_LONG) + ((space%BITS_PER_LONG) ? 1 : 0);
  _field = new unsigned long[long_count];
  cout << "space required: " << space << ", which fits in " << long_count
      << " long's, or " << (long_count*BITS_PER_LONG) << " bits" << endl;

  // initialize all bits to ON
  memset(_field, 0xFF, long_count * sizeof(long));

  _space = space;
}

// This method converts a long integer in decimal base to a binary string.
char* bitfield::decimal2binary(long decimal, char binary[])
{
  for (int i = 0; i < BITS_PER_LONG; i++)
  {
    binary[i] = (decimal & 1 ? '1' : '0');
    decimal >>= 1;
  }
  return binary;
}

// this method prints out all 64 bits in an unsigned long bitfield
void bitfield::print(unsigned long field)
{
  char binary[BITS_PER_LONG+1];
  binary[BITS_PER_LONG] = '\0';
  cout << decimal2binary(field, binary) << endl;
}

// Sieve of Eratosthenes algorithm (from wikipedia) to find all prime numbers
// up to a target number
// This algorithm proves to be a vast improvement on my older prime-finding
// algorithm: while the older version took 13 seconds, this new version took
// less than 1 second.
// This method finds all prime numbers from 2 up to size and stores them in an
// array, with prime numbers represented as ON bit and non-prime as OFF
void get_primes(bitfield* field)
{
  // numbers 0 and 1 are not primes
  field->clear(0);
  field->clear(1);

  // start with 2, the very first prime number
  for (int i = 2; i < field->space(); i++)
  {
    // test whether bit at i is ON
    if (field->test(i))
    {
      int multiple = 2;
      while (i*multiple <= field->space())
      {
        // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
        // So turn off bit at (i*multiple)th position.
        field->clear(i*multiple);
        multiple += 1;
      }
    }
  }
}

// this method converts an array of booleans, where ON elements represent prime
// numbers and OFF otherwise, into an array of prime numbers
void pack_primes(const bitfield& field, int** primes, int* prime_count)
{
  // 105000 currently accommodates up to the biggest test prime number: 10001
  // so it covers all the smaller test prime numbers.
  int tmp[105000];
  *prime_count = 0;
  for (int i = 0; i < field.space(); i++)
    if (field.test(i))
    {
      tmp[*prime_count] = i;
      *prime_count += 1;
    }

  *primes = new int[*prime_count];
  memcpy(*primes, tmp, (*prime_count * sizeof(int)));
}

int main()
{
  struct target_t
  {
    int prime; // which prime number to get to
    int space; // how much space is needed to cover the prime number
  };

  target_t targets[] =
  {
    { 6, 20 },        // 6th prime is 13, round-up space is 20
    { 11, 50 },       // 11th prime is 31, round-up space is 50
    { 101, 600 },     // 101th prime is 547, round-up space is 600
    { 1001, 8100 },   // 1001st prime is 7927
    { 2001, 17500 },  // 10001st prime is 17393
    { 3001, 27600 },  // 10001st prime is 27457
    { 4001, 38000 },  // 10001st prime is 37831
    { 5001, 48800 },  // 10001st prime is 48619
    { 6001, 59500 },  // 10001st prime is 59369
    { 7001, 70800 },  // 10001st prime is 70663
    { 8001, 82000 },  // 10001st prime is 81817
    { 9001, 93300 },  // 10001st prime is 93187
    { 10001, 105000 } // 10001st prime is 104743
  };

  for (int i = 0; i < sizeof(targets)/sizeof(target_t); i++)
  {
    // First, obtain all prime numbers up to space. The prime numbers are ON bits
    // while the non-prime numbers are OFF bits.
    bitfield field(targets[i].space);
    get_primes(&field);

    // Next, extract those ON bits into another array of prime numbers
    int* primes;
    int prime_count;
    pack_primes(field, &primes, &prime_count);

    cout << "found " << prime_count << " prime numbers below " << targets[i].space << endl;
    cout << "the " << targets[i].prime << "th prime number is " << primes[targets[i].prime-1] << endl;
    cout << "**********************************************" << endl;

    // Lastly, don't forget to free memory.
    delete [] primes;
  }
}
