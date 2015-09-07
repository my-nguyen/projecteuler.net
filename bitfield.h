#ifndef BITFIELD_C_H
#define BITFIELD_C_H

#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(long)*BITS_PER_BYTE)

// This type represents the bitfield (an array of unsigned long) that contains
// ON and OFF bits. the type includes all the operations needed on a bit such as
// clear(), set(), and test()
struct bitfield_t
{
  unsigned long* _data;
  int _size;
};
typedef struct bitfield_t bitfield_t;

// C doesn't allow function overloading, hence must avoid the name initialize()
// to be used by primes_t
void init(bitfield_t* field, int size);

void clear(bitfield_t* field, int long_index);

void set(bitfield_t* field, int long_index);

unsigned long test(bitfield_t* field, int long_index);

int long_count(bitfield_t* field);

void print(bitfield_t* field);

void destruct(bitfield_t* field);

#endif
