# As explained in
# http://blog.functionalfun.net/2008/07/project-euler-problem-15-city-grids-and.html
# the number of routes in a NxN grid is the value of the element located at row
# 2N, column N in a Pascal's triangle
# (https://en.wikipedia.org/wiki/Pascal's_triangle). So for a 1X1 grid, the
# number of routes is the value at (2, 1), for a 2X2 grid, the number is at
# (4, 2), etc. The formula for calculating the value of that element is:
# P(row, column) = P(row, column-1) * ((row + 1 - column) / column);
# https://en.wikipedia.org/wiki/Pascal's_triangle#Calculating_a_row_or_diagonal_by_itself
# Consult the followings for more explanation of the solution
# http://www.mathblog.dk/project-euler-15/
# http://blog.dreamshire.com/project-euler-15-solution/
# http://stefanoricciardi.com/2010/12/01/project-euler-problem-15-in-fsharp/
#
def pascal(row, column):
  result = 1
  for i in range(1, column+1):
    result = (result * (row + 1 - i)) / i
  return result

MAX_PASCAL = 20
for i in range(1, MAX_PASCAL+1):
  print("%dx%d grid: %d routes" %(i, i, pascal(i*2, i)))
