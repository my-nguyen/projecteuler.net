# Refer to http://www.mathblog.dk/project-euler-18/
# for an explanation of the solution to the problem

# this method converts a string containing integers separated by spaces into
# an array of integers
def to_ints(line)
  line.split.each do |token|
    array << token.to_i
  end
  array
end

def input()
  lines = []
  lines << "75"
  lines << "95 64"
  lines << "17 47 82"
  lines << "18 35 87 10"
  lines << "20 04 82 47 65"
  lines << "19 01 23 75 03 34"
  lines << "88 02 77 73 07 63 67"
  lines << "99 65 04 28 06 16 70 92"
  lines << "41 41 26 56 83 40 80 70 33"
  lines << "41 48 72 33 47 32 37 16 94 29"
  lines << "53 71 44 65 25 43 91 52 97 51 14"
  lines << "70 11 33 28 77 73 17 78 39 68 17 57"
  lines << "91 71 52 38 17 14 91 43 58 50 27 29 48"
  lines << "63 66 04 68 89 53 67 30 73 16 69 87 40 31"
  lines << "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"

  triangle = []
  lines.each do |line|
    triangle << line.split.map(&:to_i)
  end
  triangle
end

def to_string(triangle)
  builder = ""
  triangle.each do |row|
    builder << row.to_s << "\n"
  end
  builder
end

def process(triangle)
  puts("OUTPUT")
  (triangle.size-2).downto(0) do |i|
    current = triangle[i]
    prochaine = triangle[i+1]
    # start from next-to-bottom row, work back to top
    current.size.times do |j|
      # for each entry, take 2 sums:
      # triangle[i][j] + triangle[i+1][j] AND triangle[i][j] + triangle[i+1][j+1]
      # then replace entry with the max of the 2 sums
      entry = [current[j]+prochaine[j], current[j]+prochaine[j+1]].max
      current[j] = entry
    end
    puts("#{current}")
  end
end

triangle = input
puts("INPUT\n#{to_string(triangle)}")
process(triangle)
