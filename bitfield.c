#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include "bitfield.h"

// all the bit operations below were lifted from
// stackoverflow.com/questions/2525310/how-to-define-and-work-with-an-array-of-bits-in-c
int byte_index(int long_index)
{
  return long_index / BITS_PER_LONG;
}

int bit_index(int long_index)
{
  return long_index % BITS_PER_LONG;
}

// this method clears a bit at a given index
void clear(bitfield_t* field, int long_index)
{
  // literal 1 is an int which is 32 bits. the shift (<<) and complement (~)
  // will yield inaccurate results for a 32-bit integer. Thus a long literal 1l
  // is used instead because it's 64 bits.
  field->_data[byte_index(long_index)] &= ~(1l << bit_index(long_index));
}

// this method sets a bit at a given index
void set(bitfield_t* field, int long_index)
{
  field->_data[byte_index(long_index)] |= (1l << bit_index(long_index));
}

// this method tests whether a bit is on at a given index
// return type needs to be unsigned long instead of int, for reason similar
// to that in bitfield_clear()
unsigned long test(bitfield_t* field, int long_index)
{
  return field->_data[byte_index(long_index)] & (1l << bit_index(long_index));
}

// This method converts a long integer in decimal base to a binary string.
char* decimal2binary(unsigned long decimal, char binary[])
{
  int i = 0;
  for (i = 0; i < BITS_PER_LONG; i++)
  {
    binary[i] = (decimal & 1 ? '1' : '0');
    decimal >>= 1;
  }
  return binary;
}

int long_count(bitfield_t* field)
{
  return (field->_size/BITS_PER_LONG) + ((field->_size%BITS_PER_LONG) ? 1 : 0);
}

// this method prints out all 64 bits in an unsigned long bitfield
void print(bitfield_t* field)
{
  int i;
  for (i = 0; i < long_count(field); i++)
  {
    char binary[BITS_PER_LONG+1];
    binary[BITS_PER_LONG] = '\0';
    printf("%s\n", decimal2binary(field->_data[i], binary));
  }
}

void init(bitfield_t* field, int size)
{
  field->_size = size;

  // use an array of unsigned long to represent the array of booleans (bits).
  // each long contains 64 bits.
  field->_data = malloc(long_count(field) * sizeof(long));
  // printf("space required: %d, which fits in %d long's, or %ld bits\n", size, long_count(field), (long_count(field)*BITS_PER_LONG));
}

void destruct(bitfield_t* field)
{
  free(field->_data);
}
