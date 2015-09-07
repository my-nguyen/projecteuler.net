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

  ~bitfield_t() { delete [] _data; }

  void print(unsigned long field);

  void clear(int long_index)
  { _data[byte_index(long_index)] &= ~(1l << bit_index(long_index)); }

  void set(int long_index)
  { _data[byte_index(long_index)] |= (1l << bit_index(long_index)); }

  unsigned long test(int long_index) const
  { return _data[byte_index(long_index)] & (1l << bit_index(long_index)); }

  friend ostream& operator<<(ostream& output, const bitfield_t& field);

  unsigned long* data() { return _data; }

  int long_count() const { return (_size/BITS_PER_LONG) + ((_size%BITS_PER_LONG) ? 1 : 0); }

private:
  char* decimal2binary(long decimal, char binary[]) const;
  int byte_index(int long_index) const { return long_index / BITS_PER_LONG; }
  int bit_index(int long_index) const { return long_index % BITS_PER_LONG; }

  unsigned long* _data;
  int _size;
};

#endif
