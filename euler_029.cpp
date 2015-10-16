#include <iostream>
#include <set>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

int main()
{
  set<mpz_class> collection;
  for (int base = 2; base <= 100; base++)
    for (int exponent = 2; exponent <= 100; exponent++)
    {
      mpz_t bbase;
      mpz_init(bbase);
      mpz_set_ui(bbase, base);

      mpz_t bpower;
      mpz_init(bpower);
      mpz_pow_ui(bpower, bbase, exponent);

      collection.insert(mpz_class(bpower));
    }
  cout << "Distinct terms: " << collection.size() << endl;
}
