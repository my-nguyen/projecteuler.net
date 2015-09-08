#include "bitfield.hpp"
#include <cstring>

bitfield_t::bitfield_t(int size) : _size(size)
{
  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  _data = new unsigned long[long_count()];
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
  for (int i = 0; i < field.long_count(); i++)
  {
    char binary[BITS_PER_LONG+1];
    binary[BITS_PER_LONG] = '\0';
    cout << "%s" << field.decimal2binary(field._data[i], binary) << endl;
  }
}
