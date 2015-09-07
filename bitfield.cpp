#include "bitfield.hpp"
#include <cstring>

bitfield_t::bitfield_t(int size)
{
  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  int long_count = (size/BITS_PER_LONG) + ((size%BITS_PER_LONG) ? 1 : 0);
  _data = new unsigned long[long_count];
  /*
  cout << "space required: " << space << ", which fits in " << long_count
      << " long's, or " << (long_count*BITS_PER_LONG) << " bits" << endl;
      */

  // initialize all bits to ON
  memset(_data, 0xFF, long_count * sizeof(long));

  _size = size;
}

// This method converts a long integer in decimal base to a binary string.
char* bitfield_t::decimal2binary(long decimal, char binary[]) const
{
  for (int i = 0; i < BITS_PER_LONG; i++)
  {
    binary[i] = (decimal & 1 ? '1' : '0');
    decimal >>= 1;
  }
  return binary;
}

// this method prints out all 64 bits in an unsigned long bitfield
ostream& operator<<(ostream& output, const bitfield_t& field)
{
  int long_count = (field._size/BITS_PER_LONG) + ((field._size%BITS_PER_LONG) ? 1 : 0);
  for (int i = 0; i < long_count; i++)
  {
    char binary[BITS_PER_LONG+1];
    binary[BITS_PER_LONG] = '\0';
    cout << "%s" << field.decimal2binary(field._data[i], binary) << endl;
  }
}
