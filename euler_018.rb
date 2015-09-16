# Refer to http://www.mathblog.dk/project-euler-18/
# for an explanation of the solution to the problem
#

def input
  # triangle is a 2-dimensional array of integers
  triangle = []

  # fetch one whole line until the end of input
  STDIN.each_line do |line|
    row = line.split.map {|i| i.to_i}
    triangle << row
  end
  triangle
end

def myprint(triangle)
  puts "INPUT"
  triangle.each do |row|
    row.each do |item|
      print(" #{item}")
    end
    puts
  end
end

def process(triangle)
  puts "OUTPUT"
  (triangle.size-2).downto(0) do |i|
    # must use reference here; otherwise a copy would be created locally and
    # the line current[j] = maxi would cause the local copy, and not the
    # triangle itself, to save the max value.
    current = triangle[i];
    prochaine = triangle[i+1];
    # start from next-to-bottom row, work back to top
    current.each_index do |j|
      # for each entry, take 2 sums: triangle[i][j] + triangle[i+1][j] and
      # triangle[i][j] + triangle[i+1][j+1]
      # then replace entry with the max of the 2 sums
      max = [current[j]+prochaine[j], current[j]+prochaine[j+1]].max
      current[j] = max;
      print(" #{current[j]}")
    end
    puts
  end
end

triangle = input
myprint(triangle)
process(triangle)
