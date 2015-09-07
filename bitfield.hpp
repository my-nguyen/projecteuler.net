#ifndef BITFIELD_CPP_H
#define BITFIELD_CPP_H

#include <iostream>
using namespace std;

#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(long)*BITS_PER_BYTE)

class bitfield_t
{
public:
  bitfield_t(int space);

  ~bitfield_t() { delete [] _field; }

  void print(unsigned long field);

  void clear(int long_index)
  { _field[byte_index(long_index)] &= ~(1l << bit_index(long_index)); }

  void set(int long_index)
  { _field[byte_index(long_index)] |= (1l << bit_index(long_index)); }

  unsigned long test(int long_index) const
  { return _field[byte_index(long_index)] & (1l << bit_index(long_index)); }

  // int space() const { return _space; }

  friend ostream& operator<<(ostream& output, const bitfield_t& field);

private:
  char* decimal2binary(long decimal, char binary[]) const;
  int byte_index(int long_index) const { return long_index / BITS_PER_LONG; }
  int bit_index(int long_index) const { return long_index % BITS_PER_LONG; }

  unsigned long* _field;
  int _space;
};

#endif
