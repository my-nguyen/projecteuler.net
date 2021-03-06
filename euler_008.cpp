#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // std::find()
using namespace std;

// this method returns the product of all integers contained in list
long product(vector<int>& data)
{
  long result = 1;
  for (int i = 0; i < data.size(); i++)
    result *= data[i];
  return result;
}

string to_string(vector<int>& list)
{
  string result;
  result.append("[");
  for (int i = 0; i < list.size(); i++)
    result.append(to_string(list[i])).append(", ");
  result.pop_back();
  result.pop_back();
  result.append("]");
  return result;
}

// this method returns the adjacent digits of 'length' whose product is the
// largest product among all the adjacent digits within the 'digits' list
vector<int> max_product(vector<int>& digits, int length)
{
  long max = 0;
  vector<int> result;
  int start = 0;
  while (start+length <= digits.size())
  {
    // take a slice of length (4, 7, 10 or 13) digits
    vector<int>::iterator begin = digits.begin() + start;
    vector<int>::iterator end = begin + length;
    vector<int> slice(begin, end);
    vector<int>::iterator index = find(begin, end, 0);
    // if the slice contains 0, then skip to the next slice beyond the 0,
    // because a product of anything and 0 is 0.
    if (index != end)
      start += (index-begin) + 1;
    else
    {
      // calculate the product of all digits in the slice
      long produit = product(slice);
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

// this method converts a character string containing digits into a list of
// integer digits
vector<int> to_integers(string data)
{
  vector<int> digits;
  for (int i = 0; i < data.size(); i++)
    digits.push_back(data[i] - '0');
  return digits;
}

int main()
{
  // copy the number from above
  string number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  // convert the long string number into a list of 1000 integer digits
  vector<int> digits = to_integers(number);
  int lengths[] = {4, 7, 10, 13};
  for (int i = 0; i < sizeof(lengths)/sizeof(int); i++)
  {
    vector<int> slice = max_product(digits, lengths[i]);
    cout << "max of " << lengths[i] << ": " << product(slice) << " from " << to_string(slice) << endl;
  }
}
