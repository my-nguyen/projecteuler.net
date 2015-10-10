class Slice
  attr_accessor :data

  # this constructor sets up the @data field. must use default parameter to
  # simulate overloading of initialize(), because Ruby doesn't allow overloading
  # while Java and C++ does.
  def initialize(data = nil)
    if (data.nil?)
      @data = []
      MAX_SLICE.times do
        @data << 0
      end
    else
      @data = data
    end
  end

  # this method returns the product of all integers in the Slice.
  def product()
    @data.inject(:*)
  end

  # this methods reports both the product of and the contents of all integers
  # in the Slice
  def report()
    builder = ""
    builder << "MAX PRODUCT: " << product().to_s << ", slice " << @data.inspect
    builder
  end
end

# base class used by 6 other classes (Row, Column, DownFirst, DownLast, UpFirst
# and UpLast) with a common method find_max()
class Array
  def initialize
    @data = []
  end

  # this method finds, within the data array, the slice whose product has the
  # maximum value and if so, replace the current max with the new max.
  def find_max(current)
    puts("data #{@data}")

    start = 0
    # while end of row is not reached
    while (start+MAX_SLICE <= @data.size)
      # take a slice of 4 adjacent numbers
      slice = Slice.new(@data[start, MAX_SLICE])
      # search the new slice for integer zero
      index = slice.data.index(0)
      # if the slice contains 0, then skip to the next slice beyond the 0,
      # because a product of anything and 0 is 0.
      if (index != nil)
        start += index + 1
      else
        # calculate the product of the 4 integers in the slice
        product = slice.product()
        # update max if necessary
        if (product > current.product)
          puts("current: #{current.product}, new: #{product}, slice #{slice.data}")
          current.data = slice.data
        end
        # move on to the next slice
        start += 1
      end
    end
  end
end

# this class contains all 20 integers in a row
class Row < Array
  # this constructor extracts one row at position i from the grid
  def initialize(grid, row)
    super()
    MAX_COLUMN.times do |i|
      @data << grid[row][i]
    end
  end
end

# this class contains all 20 integers in a column
class Column < Array
  # this constructor extracts one column at position j from the grid
  def initialize(grid, column)
    super()
    MAX_ROW.times do |i|
      @data << grid[i][column]
    end
  end
end

# empty class that serves as base class for the 4 diagonal classes below
class Diagonal < Array
  def initialize()
    super()
  end
end

class DownFirst < Diagonal
  # This constructor extracts all numbers from grid starting at position (i,j)
  # going down diagonally. This method is called in a loop starting at i=16 and
  # j=0, and ending at i=0 and j=0.
  def initialize(grid, i, j)
    super()
    while (i < MAX_ROW)
      @data << grid[i][j]
      i += 1
      j += 1
    end
  end
end

class DownLast < Diagonal
  # This constructor extracts all numbers from grid starting at position (i,j)
  # going down diagonally. This method is called in a loop starting at i=0 and
  # j=1, and ending at i=0 and j=16.
  def initialize(grid, i, j)
    super()
    while (j < MAX_COLUMN)
      @data << grid[i][j]
      i += 1
      j += 1
    end
  end
end

class UpFirst < Diagonal
  # This constructor extracts all numbers from grid starting at position (i,j)
  # going up diagonally. This method is called in a loop starting at i=3 and
  # j=0, and ending at i=19 and j=0.
  def initialize(grid, i, j)
    super()
    while (i >= 0)
      @data << grid[i][j]
      i -= 1
      j += 1
    end
  end
end

class UpLast < Diagonal
  # This constructor extracts all numbers from grid starting at position (i,j)
  # going up diagonally. This method is called in a loop starting at i=19 and
  # j=1, and ending at i=19 and j=16.
  def initialize(grid, i, j)
    super()
    while (j < MAX_COLUMN)
      @data << grid[i][j]
      i -= 1
      j += 1
    end
  end
end

# this method converts a string containing 20 integers separated by spaces
# into an array of 20 integers
def to_int_array(string, array)
  # replaced StringTokenizer with String::split() because StringTokenizer is
  # legacy class
  tokens = string.split
  tokens.each do |token|
    array << token.to_i
  end
end

def init()
  # set up lines as an array of 20 strings, each containing 20 numbers
  lines = []
  lines << "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08"
  lines << "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00"
  lines << "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65"
  lines << "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91"
  lines << "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80"
  lines << "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50"
  lines << "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70"
  lines << "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21"
  lines << "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72"
  lines << "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95"
  lines << "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92"
  lines << "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57"
  lines << "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58"
  lines << "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40"
  lines << "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66"
  lines << "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69"
  lines << "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36"
  lines << "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16"
  lines << "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54"
  lines << "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"

  # convert the array of 20 strings into an array of 20 sub-arrays, each
  # sub-array containing 20 numbers
  grid = Array.new
  lines.each do |line|
    grid << line.split.map(&:to_i)
  end
  grid
end

MAX_SLICE = 4
MAX_ROW = 20
MAX_COLUMN = 20
# set up grid as an array of 20 sub-arrays, each containing 20 integers
grid = init

# create an empty max Slice
max = Slice.new

MAX_ROW.times do |i|
  # extract one row
  row = Row.new(grid, i)
  # find max product within the row
  row.find_max(max)
end
puts("#{max.report}")

MAX_COLUMN.times do |j|
  # extract one column
  column = Column.new(grid, j)
  # find max product within the column
  column.find_max(max)
end
puts("#{max.report}")

(MAX_ROW-MAX_SLICE).downto(0) do |i|
  down_first = DownFirst.new(grid, i, 0)
  down_first.find_max(max)
end
puts("#{max.report}")

1.upto(MAX_COLUMN-MAX_SLICE) do |j|
  down_last = DownLast.new(grid, 0, j)
  down_last.find_max(max)
end
puts("#{max.report}")

(MAX_SLICE-1).upto(MAX_ROW-1) do |i|
  up_first = UpFirst.new(grid, i, 0)
  up_first.find_max(max)
end
puts("#{max.report}")

1.upto(MAX_COLUMN-MAX_SLICE) do |j|
  up_last = UpLast.new(grid, MAX_ROW-1, j)
  up_last.find_max(max)
end
puts("#{max.report}")
