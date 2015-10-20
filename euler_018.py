# Refer to http://www.mathblog.dk/project-euler-18/
# for an explanation of the solution to the problem

# this method converts a string containing integers separated by spaces into
# an array of integers
def to_ints(line):
  return map(int, line.split())

def input():
  lines = []
  lines.append("75")
  lines.append("95 64")
  lines.append("17 47 82")
  lines.append("18 35 87 10")
  lines.append("20 04 82 47 65")
  lines.append("19 01 23 75 03 34")
  lines.append("88 02 77 73 07 63 67")
  lines.append("99 65 04 28 06 16 70 92")
  lines.append("41 41 26 56 83 40 80 70 33")
  lines.append("41 48 72 33 47 32 37 16 94 29")
  lines.append("53 71 44 65 25 43 91 52 97 51 14")
  lines.append("70 11 33 28 77 73 17 78 39 68 17 57")
  lines.append("91 71 52 38 17 14 91 43 58 50 27 29 48")
  lines.append("63 66 04 68 89 53 67 30 73 16 69 87 40 31")
  lines.append("04 62 98 27 23 09 70 98 73 93 38 53 60 04 23")

  triangle = []
  for line in lines:
    triangle.append(to_ints(line))
  return triangle

def to_string(triangle):
  builder = ""
  for row in triangle:
    builder += str(row)
    builder += "\n"
  builder = builder[:-1]
  return builder

def process(triangle):
  print "OUTPUT"
  for i in range(len(triangle)-2, -1, -1):
    current = triangle[i]
    prochaine = triangle[i+1]
    # start from next-to-bottom row, work back to top
    for j in range(len(current)):
      # for each entry, take 2 sums:
      # triangle[i][j] + triangle[i+1][j] AND triangle[i][j] + triangle[i+1][j+1]
      # then replace entry with the max of the 2 sums
      entry = max(current[j]+prochaine[j], current[j]+prochaine[j+1])
      current[j] = entry
    print current

triangle = input()
print("INPUT\n%s" %to_string(triangle))
process(triangle)
