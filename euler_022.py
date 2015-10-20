import re

# this method opens a file, reads the only line in the file which contains
# over 5,000 names, parse the names, store them in a list, then return the list
def input():
  names = []

  # read from file.
  file = open("euler_022-names.txt", "r")
  # there's only one huge line (46447 characters) to read. parse the line into
  # strings (names) based on regular expression "\w+" (one or more word characters)
  # then retain each name in a list
  names = re.findall(r'\w+', file.read())
  # sort the names alphabetically
  names.sort()

  file.close()
  return names

# this method returns a list of scores of the corresponding names. each score
# is calculated by taking the total of the alphabetical value of all letters
# in a name before multiplying that total by the alphabetical position of
# that name.
def scores(names):
  scores = []
  # go thru the name list
  for i in range(len(names)):
    total = 0
    for letter in names[i]:
      # sum of the alphabetical value of all letters of a name
      value = ord(letter) - ord('A') + 1
      total += value
      # print("char: %s, value: %d" %(letter, value))
    # print("total: %d, index: %d" %(total, i))
    # multiply the sum with the alphabetical position of the name
    total *= i + 1

    # retain that product in a list
    scores.append(total)
  return scores

names = input()
# print("index of COLIN: %d" %names.index("COLIN"))
points = scores(names)
print("Total: %d" %sum(points))
