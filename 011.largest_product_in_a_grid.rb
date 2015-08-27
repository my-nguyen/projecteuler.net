# In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
#
# 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
# 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
# 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
# 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
# 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
# 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
# 32 98 81 28 64 23 67 10 26*38 40 67 59 54 70 66 18 38 64 70
# 67 26 20 68 02 62 12 20 95 63*94 39 63 08 40 91 66 49 94 21
# 24 55 58 05 66 73 99 26 97 17 78*78 96 83 14 88 34 89 63 72
# 21 36 23 09 75 00 76 44 20 45 35 14*00 61 33 97 34 31 33 95
# 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
# 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
# 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
# 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
# 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
# 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
# 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
# 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
# 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
# 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
#
# The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
# What is the greatest product of four adjacent numbers in the same direction
# (up, down, left, right, or diagonally) in the 20×20 grid?
#
# helper method to print out all numbers in an array
def print_array numbers
  numbers.each do |number|
    print "#{number} "
  end
  puts
end

# this method returns the slice of a row whose 4 integers have a product greater
# than max
def max_of(row, max)
  start = 0
  result = Slice.new([], max)
  while (start+MAX_SLICE-1 < row.size)
    # take a slice of 4 adjacent numbers
    slice = row[start, MAX_SLICE]
    # if the slice contains 0, then skip to the next slice beyond the 0,
    # because a product of anything and 0 is 0.
    if (slice.index(0))
      start = start + slice.index(0) + 1
    else
      # calculate the product of all numbers in the slice
      product = slice.reduce(1, :*)
      # update max if necessary
      if product > result.product
        print "current: #{result.product}, new: #{product}, slice: "
        print_array slice
        result.product = product
        result.slice = slice.dup
      end
      # move on to the next slice
      start += 1
    end
  end
  result
end

# this method extracts one column at position j from the grid
def extract_column(grid, j)
  column = Array.new
  MAX_GRID.times do |i|
    column << grid[i][j]
  end
  column
end

# This method extracts all numbers from grid starting at position (i,j) going
# down diagonally. This method is called in a loop starting at i=16 and j=0,
# and ending at i=0 and j=0.
def extract_diagonal_down_first(grid, i, j)
  diagonal = Array.new
  while i < MAX_GRID
    diagonal << grid[i][j]
    i += 1
    j += 1
  end
  diagonal
end

# This method extracts all numbers from grid starting at position (i,j) going
# down diagonally. This method is called in a loop starting at i=0 and j=1,
# and ending at i=0 and j=16.
def extract_diagonal_down_last(grid, i, j)
  diagonal = Array.new
  while j < MAX_GRID
    diagonal << grid[i][j]
    i += 1
    j += 1
  end
  diagonal
end

# This method extracts all numbers from grid starting at position (i,j) going
# up diagonally. This method is called in a loop starting at i=3 and j=0,
# and ending at i=19 and j=0.
def extract_diagonal_up_first(grid, i, j)
  diagonal = Array.new
  while i >= 0
    diagonal << grid[i][j]
    i -= 1
    j += 1
  end
  diagonal
end

# This method extracts all numbers from grid starting at position (i,j) going
# up diagonally. This method is called in a loop starting at i=19 and j=1,
# and ending at i=19 and j=16.
def extract_diagonal_up_last(grid, i, j)
  diagonal = Array.new
  while j < MAX_GRID
    diagonal << grid[i][j]
    i -= 1
    j += 1
  end
  diagonal
end

MAX_SLICE = 4
MAX_GRID  = 20
# set up input as an array of 20 strings, each containing 20 numbers
input = Array.new
input << "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08"
input << "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00"
input << "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65"
input << "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91"
input << "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80"
input << "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50"
input << "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70"
input << "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21"
input << "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72"
input << "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95"
input << "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92"
input << "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57"
input << "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58"
input << "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40"
input << "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66"
input << "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69"
input << "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36"
input << "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16"
input << "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54"
input << "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"

# convert the array of 20 strings into an array of 20 sub-arrays, each sub-array
# containing 20 numbers
grid = Array.new
input.each do |line|
  grid << line.split.map(&:to_i)
end

# practice using Ruby Struct
Slice = Struct.new(:slice, :product)
max = Slice.new([], 0)

grid.each do |row|
  print "NEW ROW: "
  print_array row
  current = max_of(row, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice

MAX_GRID.times do |i|
  column = extract_column(grid, i)
  print "NEW COLUMN: "
  print_array column
  current = max_of(column, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice

(MAX_GRID-MAX_SLICE).downto(0) do |i|
  diagonal = extract_diagonal_down_first(grid, i, 0)
  print "NEW DIAGONAL: "
  print_array diagonal
  current = max_of(diagonal, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice

1.upto(MAX_GRID-MAX_SLICE) do |j|
  diagonal = extract_diagonal_down_last(grid, 0, j)
  print "NEW DIAGONAL: "
  print_array diagonal
  current = max_of(diagonal, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice

(MAX_SLICE-1).upto(MAX_GRID-1) do |i|
  diagonal = extract_diagonal_up_first(grid, i, 0)
  print "NEW DIAGONAL: "
  print_array diagonal
  current = max_of(diagonal, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice

1.upto(MAX_GRID-MAX_SLICE) do |j|
  diagonal = extract_diagonal_up_last(grid, MAX_GRID-1, j)
  print "NEW DIAGONAL: "
  print_array diagonal
  current = max_of(diagonal, max.product)
  if current.product > max.product
    max = current
  end
end
print "max_product: #{max.product}, max_slice: "
print_array max.slice
