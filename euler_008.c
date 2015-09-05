#include <stdio.h>
#include <string.h>

#define MAX_SLICE 13
struct slice_t
{
  int _data[MAX_SLICE];
  int _size;
};
typedef struct slice_t slice_t;

// this method looks for target in an array; if target is found, it returns the
// index of the target, if not it returns a 0
int find(slice_t* slice, int target)
{
  int i;
  for (i = 0; i < slice->_size; i++)
    if (slice->_data[i] == target)
      return i;
  return 0;
}

// this method returns the product of all integers contained in array
long product(slice_t* slice)
{
  long result = 1;
  int i;
  for (i = 0; i < slice->_size; i++)
    result *= slice->_data[i];
  return result;
}

// this method copies an array from source to dest
slice_t* copy(slice_t* source, slice_t* dest)
{
  int i;
  for (i = 0; i < source->_size; i++)
    dest->_data[i] = source->_data[i];
  return dest;
}

// this method converts an array of integers into a printable string format
char* tostring(slice_t* slice, char string[])
{
  strcpy(string, "[");
  int i;
  for (i = 0; i < slice->_size; i++)
  {
    if (i)
      strcat(string, ", ");
    sprintf(string+strlen(string), "%d", slice->_data[i]);
  }
  return strcat(string, "]");
}

// this method returns a sub-array of the 'source' array, starting from 'start'
// for 'length' elements
slice_t* subarray(int digits[], int start, int length, slice_t* slice)
{
  int i;
  for (i = 0; i < length; i++)
  {
    slice->_data[i] = digits[start];
    start += 1;
  }
  slice->_size = length;
  return slice;
}

#define MAX_DIGITS 1000
// this method returns the adjacent digits of 'length' whose product is the
// largest product among all the adjacent digits within the array 'digits'
slice_t* max_product(int digits[], int length, slice_t* result)
{
  long max = 0;
  int start = 0;
  while (start+length <= MAX_DIGITS)
  {
    // take a slice of length (4 or 13) digits
    slice_t slice;
    subarray(digits, start, length, &slice);
    // if the slice contains 0, then skip to the next slice beyond the 0,
    // because a product of anything and 0 is 0.
    int index;
    if (index = find(&slice, 0))
      start += index + 1;
    else
    {
      // calculate the product of all digits in the slice
      long produit = product(&slice);
      // reset max if necessary
      if (produit > max)
      {
        max = produit;
        copy(&slice, result);
      }
      // move on to the next slice
      start += 1;
    }
  }
  result->_size = length;
  return result;
}

// this method converts a character string containing digits into an array of digits
int* string2digits(char string[], int digits[])
{
  int i;
  for (i = 0; i < MAX_DIGITS; i++)
    digits[i] = string[i] - '0';
  return digits;
}

void main()
{
  // copy the number from above
  char number[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  // convert the number into an array of 1000 digits
  int digits[MAX_DIGITS];
  string2digits(number, digits);
  int lengths[] = {4, 7, 10, 13};
  int i;
  for (i = 0; i < sizeof(lengths)/sizeof(int); i++)
  {
    slice_t slice;
    max_product(digits, lengths[i], &slice);
    char print[100];
    printf("max of %d: %ld from %s\n", lengths[i], product(&slice), tostring(&slice, print));
  }
}
