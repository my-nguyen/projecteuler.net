// Lattice paths
// Starting in the top left corner of a 2×2 grid, and only being able to move to
// the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?
//
// As explained in
// http://blog.functionalfun.net/2008/07/project-euler-problem-15-city-grids-and.html
// the number of routes in a NxN grid is the value of the element located at row
// 2N, column N in a Pascal's triangle
// (https://en.wikipedia.org/wiki/Pascal's_triangle). So for a 1X1 grid, the
// number of routes is the value at (2, 1), for a 2X2 grid, the number is at
// (4, 2), etc. The formula for calculating the value of that element is:
// P(row, column) = P(row, column-1) * ((row + 1 - column) / column);
// https://en.wikipedia.org/wiki/Pascal's_triangle#Calculating_a_row_or_diagonal_by_itself
// Consult the followings for more explanation of the solution
// http://www.mathblog.dk/project-euler-15/
// http://blog.dreamshire.com/project-euler-15-solution/
// http://stefanoricciardi.com/2010/12/01/project-euler-problem-15-in-fsharp/
//
#include <iostream>
using namespace std;

long pascal(int row, int column)
{
  long result = 1;
  for (int i = 1; i <= column; i++)
    result = (result * (row + 1 - i)) / i;
  return result;
}

#define MAX_PASCAL 20

int main()
{
  for (int i = 1; i <= MAX_PASCAL; i++)
    cout << i << "x" << i << " grid: " << pascal(i*2, i) << " routes" << endl;
}
