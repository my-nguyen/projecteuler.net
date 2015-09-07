#ifndef BIT_FIELD_H
#define BIT_FIELD_H

#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(long)*BITS_PER_BYTE)

// This type represents the bitfield (an array of unsigned long) that contains
// ON and OFF bits. the type includes all the operations needed on a bit such as
// clear(), set(), and test()
void bitfield_clear(unsigned long field[], int long_index);

void bitfield_set(unsigned long field[], int long_index);

unsigned long bitfield_test(unsigned long field[], int long_index);

void bitfield_print(unsigned long field[], int size);

#endif
