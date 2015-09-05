#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> array(10, 3);
  for (int i = 0; i < array.size(); i++)
    cout << array[i] << " ";
  cout << endl;
}
