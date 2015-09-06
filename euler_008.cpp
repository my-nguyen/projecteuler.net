#include <iostream>
using namespace std;

const int MAX_SLICE = 13;
class slice_t
{
public:
  slice_t(int digits[], int start, int length);
  slice_t() : _size(0) {}
  ~slice_t() {}
  int find(int target);
  long product();
  slice_t& operator=(const slice_t& source);
  // operator string();
  friend ostream& operator<<(ostream& stream, const slice_t& slice);

public:
  int _data[MAX_SLICE];
  int _size;
};

// this method looks for target in an array; if target is found, it returns the
// index of the target, if not it returns a 0
int slice_t::find(int target)
{
  for (int i = 0; i < _size; i++)
    if (_data[i] == target)
      return i;
  return 0;
}

// this method returns the product of all integers contained in array
long slice_t::product()
{
  long result = 1;
  for (int i = 0; i < _size; i++)
    result *= _data[i];
  return result;
}

// this method copies an array from source to dest
slice_t& slice_t::operator=(const slice_t& source)
{
  for (int i = 0; i < source._size; i++)
    _data[i] = source._data[i];
  _size = source._size;
  return *this;
}

// this method converts an array of integers into a printable string format
ostream& operator<<(ostream& out, const slice_t& slice)
{
  out << "[";
  for (int i = 0; i < slice._size; i++)
  {
    if (i)
      out << ", ";
    out << slice._data[i];
  }
  out << "]";
  return out;
}

// this constructor creates a slice from the 'source' array, starting from 'start'
// for 'length' elements
slice_t::slice_t(int digits[], int start, int length)
{
  for (int i = 0; i < length; i++)
  {
    _data[i] = digits[start];
    start += 1;
  }
  _size = length;
}

const int MAX_DIGITS = 1000;
// this method returns the adjacent digits of 'length' whose product is the
// largest product among all the adjacent digits within the array 'digits'
slice_t max_product(int digits[], int length)
{
  long max = 0;
  slice_t result;
  int start = 0;
  while (start+length <= MAX_DIGITS)
  {
    // take a slice of length (4 or 13) digits
    slice_t slice(digits, start, length);
    // if the slice contains 0, then skip to the next slice beyond the 0,
    // because a product of anything and 0 is 0.
    int index;
    if (index = slice.find(0))
      start += index + 1;
    else
    {
      // calculate the product of all digits in the slice
      long produit = slice.product();
      // reset max if necessary
      if (produit > max)
      {
        max = produit;
        result = slice;
      }
      // move on to the next slice
      start += 1;
    }
  }
  return result;
}

// this method converts a character string containing digits into an array of digits
int* string2digits(char string[], int digits[])
{
  for (int i = 0; i < MAX_DIGITS; i++)
    digits[i] = string[i] - '0';
  return digits;
}

int main()
{
  // copy the number from above
  char number[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  // convert the number into an array of 1000 digits
  int digits[MAX_DIGITS];
  string2digits(number, digits);
  int lengths[] = {4, 7, 10, 13};
  for (int i = 0; i < sizeof(lengths)/sizeof(int); i++)
  {
    slice_t slice = max_product(digits, lengths[i]);
    cout << "max of " << lengths[i] << ": " << slice.product() << " from ";
    cout << slice << endl;
  }
}
