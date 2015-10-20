# this method opens a file, reads the only line in the file which contains
# over 5,000 names, parse the names, store them in a list, then return the list
def input
  names = []

  # read from file.
  File.open("euler_022-names.txt", "r") do |file|
    # there's only one huge line (46447 characters) to read
    file.each_line do |line|
      # parse the line into strings (names) based on delimeter ",\""
      # retain each name in a list
      names = line.split(/\W+/)
    end

    # this is a hack to remove the first string (which is somehow empty) from
    # array. the strings result from the split operation based on a regular
    # expresion, so that regex is faulty.
    names.shift
    # sort the names alphabetically
    names.sort!
  end

  names
end

# this method returns a list of scores of the corresponding names. each score
# is calculated by taking the total of the alphabetical value of all letters
# in a name before multiplying that total by the alphabetical position of
# that name.
def scores(names)
  scores = []
  # go thru the name list
  names.each_index do |i|
    sum = 0
    names[i].each_char do |letter|
      # sum of the alphabetical value of all letters of a name
      value = letter.ord - 'A'.ord + 1
      sum += value
      # puts("char: #{letter}, value: #{value}")
    end
    # puts("total: #{sum}, index: #{i}")
    # multiply the sum with the alphabetical position of the name
    sum *= i + 1

    # retain that product in a list
    scores << sum
  end

  scores
end

# this method returns the sum of all integers in a list
def sum(list)
  list.inject(:+)
end

names = input
# puts("index of COLIN: #{names.index("COLIN")}")
points = scores(names)
puts("Total: #{sum(points)}")
